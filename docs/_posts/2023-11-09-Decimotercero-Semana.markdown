---
layout: post
title: "Semana decimotercera"
date: 2023-11-09 12:00:00 -0300
categories: posts
---
# Funcionó el conversor
![Conversor](https://github.com/SisCom-PI2-2023-2/proyecto-plant-o-matic/blob/main/docs/assets/Conversor.jpg)

`Últimas versiones de código por esta semana`

Queremos enviar dato al ..... de things, pero no lo hemos logrado

```c++

#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>
#include <DallasTemperature.h>

// Update these with values suitable for your network.
const char* ssid = "Elina";
const char* password = "proyecto2";
const char* mqtt_server = "demo.thingsboard.io"; //"104.196.24.70";
const char* token = "yxBvaTo366CtIrbS4ZDI";
// {clientId:"rbp222y1d1717mqq2jdr",userName:"martin",password:"123456"}

OneWire temperatura(2);
DallasTemperature sensores(&temperatura);

// Connection objects
WiFiClient espClient;
PubSubClient mqttClient(espClient);

//timestamp of the last telemetry update
unsigned long lastMsg = 0;

//buffer sizes and messages
#define MSG_BUFFER_SIZE  (50)
char msg[MSG_BUFFER_SIZE];
char msg2[MSG_BUFFER_SIZE];

//json document to store incoming messages
DynamicJsonDocument incoming_message(256);

//Fake telemetry
int value = 0;

//Led state
boolean estado = false;

//Initiates WiFi Connection
void setup_wifi() {

  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  randomSeed(micros());

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

//This method is called whenever a MQTT message arrives. We must be prepared for any type of incoming message.
//We are subscribed to RPC Calls: v1/devices/me/rpc/request/+
void callback(char* topic, byte* payload, unsigned int length) {
  
  //log to console
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();

  //convert topic to string to parse
  String _topic = String(topic);
  
  if (_topic.startsWith("v1/devices/me/rpc/request/")) {
    //We are in a request, check request number
    String _number = _topic.substring(26);

    //Read JSON Object
    deserializeJson(incoming_message, payload);
    String metodo = incoming_message["method"];
    
    if (metodo == "getTemperature1") {
        sensores.requestTemperatures(); // Request temperatures
        int temp1 = sensores.getTempCByIndex(0); // Sensor 1
        String dataJS = "{\"Temperatura 1\":" + String(temp1, 3) + "}";
        char json[100];
        dataJS.toCharArray(json, dataJS.length() + 1);
        mqttClient.publish("v1/devices/me/telemetry", json);
    } else if (metodo == "getTemperature2") {
        sensores.requestTemperatures(); // Request temperatures
        int temp2 = sensores.getTempCByIndex(1); // Assuming Sensor 2
        String dataJS = "{\"Temperatura 2\":" + String(temp2, 3) + "}";
        char json[100];
        dataJS.toCharArray(json, dataJS.length() + 1);
        char outTopic[128];
        ("v1/devices/me/rpc/response/" + _number).toCharArray(outTopic,128);
        DynamicJsonDocument resp(256);
        resp["value"] = temp2;
        char buffer[256];
        serializeJson(resp, buffer);
        mqttClient.publish(outTopic, "23");
        Serial.println(outTopic);
        Serial.println(buffer);
    }
    else if (metodo == "motorToggle") {
        char json[100];
        dataJS.toCharArray(json, dataJS.length() + 1);
        char outTopic[128];
        ("v1/devices/me/rpc/response/" + _number).toCharArray(outTopic,128);
        DynamicJsonDocument resp(256);
        resp["value"] = temp2;
        char buffer[256];
        serializeJson(resp, buffer);
        mqttClient.publish(outTopic, "23");
    }
  }
}

void reconnect() {
  // Loop until we're reconnected
  while (!mqttClient.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect - mqttClient.connect(DEVICE_ID, TOKEN, TOKEN)
    if (mqttClient.connect("Placa", token, token)) {
      Serial.println("connected");
      // Once connected, subscribe to rpc topic
      mqttClient.subscribe("v1/devices/me/rpc/request/+");
    } else {
      Serial.print("failed, rc=");
      Serial.print(mqttClient.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void setup() {
  pinMode(BUILTIN_LED, OUTPUT);     // Initialize the BUILTIN_LED pin as an output
  Serial.begin(115200);
  setup_wifi();
  mqttClient.setServer(mqtt_server, 1883);
  mqttClient.setCallback(callback);
  sensores.begin();
}

void loop() {

  if (!mqttClient.connected()) {
    reconnect();
  }
  mqttClient.loop();

  unsigned long now = millis();
  if (now - lastMsg > 2000) {
    lastMsg = now;
    value = random(100);

    //Send value as telemetry
    DynamicJsonDocument resp(256);
    resp["value"] = value;
    char buffer[256];
    serializeJson(resp, buffer);
    
    mqttClient.publish("v1/devices/me/telemetry", buffer);
    
    Serial.print("Publish message [telemetry]: ");
    Serial.println(buffer);
    
  }
}

```
- Este código manda las temperaturas al dispositivo en thingsboard y se ve en las gráficas (valores random)
  
```c++

#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>
#include <DallasTemperature.h>

// Update these with values suitable for your network.
const char* ssid = "Manuel-5GHz";
const char* password = "26831706";
const char* mqtt_server = "demo.thingsboard.io"; //"104.196.24.70";
const char* token = "yxBvaTo366CtIrbS4ZDI";
// {clientId:"rbp222y1d1717mqq2jdr",userName:"martin",password:"123456"}

OneWire temperatura(2);
DallasTemperature sensores(&temperatura);

// Connection objects
WiFiClient espClient;
PubSubClient mqttClient(espClient);

//timestamp of the last telemetry update
unsigned long lastMsg = 0;

//buffer sizes and messages
#define MSG_BUFFER_SIZE  (50)
char msg[MSG_BUFFER_SIZE];
char msg2[MSG_BUFFER_SIZE];

//json document to store incoming messages
DynamicJsonDocument incoming_message(256);

//Fake telemetry
int value = 0;

//Led state
boolean estado = false;

//Initiates WiFi Connection
void setup_wifi() {

  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  randomSeed(micros());

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

//This method is called whenever a MQTT message arrives. We must be prepared for any type of incoming message.
//We are subscribed to RPC Calls: v1/devices/me/rpc/request/+
void callback(char* topic, byte* payload, unsigned int length) {
  
  //log to console
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();

  //convert topic to string to parse
  String _topic = String(topic);
  
  if (_topic.startsWith("v1/devices/me/rpc/request/")) {
    //We are in a request, check request number
    String _number = _topic.substring(26);

    //Read JSON Object
    deserializeJson(incoming_message, payload);
    String metodo = incoming_message["method"];
    
    if (metodo=="checkStatus") {  //Check device status. Expects a response to the same topic number with status=true.
      
      char outTopic[128];
      ("v1/devices/me/rpc/response/"+_number).toCharArray(outTopic,128);
      
      DynamicJsonDocument resp(256);
      resp["status"] = true;
      char buffer[256];
      serializeJson(resp, buffer);
      mqttClient.publish(outTopic, buffer);
    }
    if (metodo == "getTemperature1") {
        sensores.requestTemperatures(); // Request temperatures
        int temp1 = sensores.getTempCByIndex(0); // Sensor 1
        String dataJS = "{\"Temperatura 1\":" + String(temp1, 3) + "}";
        char json[100];
        dataJS.toCharArray(json, dataJS.length() + 1);
        mqttClient.publish("v1/devices/me/telemetry", json);
    } else if (metodo == "getTemperature2") {
        sensores.requestTemperatures(); // Request temperatures
        int temp2 = sensores.getTempCByIndex(1); // Assuming Sensor 2
        String dataJS = "{\"Temperatura 2\":" + String(temp2, 3) + "}";
        char json[100];
        dataJS.toCharArray(json, dataJS.length() + 1);
        char outTopic[128];
        ("v1/devices/me/rpc/response/" + _number).toCharArray(outTopic,128);
        DynamicJsonDocument resp(256);
        resp["value"] = temp2;
        char buffer[256];
        serializeJson(resp, buffer);
        temp2 = 20;
        String salida = (String) temp2;
        mqttClient.publish(outTopic, salida.c_str());
        Serial.println(outTopic);
        Serial.println(buffer);
    } else if (metodo == "setLedStatus") {
        boolean estado = incoming_message["params"];
        if (estado) {
            digitalWrite(LED_BUILTIN, LOW); // Turn on led
        } else {
            digitalWrite(LED_BUILTIN, HIGH); // Turn off led
        }
        // Attribute update
        DynamicJsonDocument resp(256);
        resp["estado"] = estado;
        char buffer[256];
        serializeJson(resp, buffer);
        mqttClient.publish("v1/devices/me/attributes", buffer);
        Serial.print("Publish message [attribute]: ");
        Serial.println(buffer);
    }
  }
}

void reconnect() {
  // Loop until we're reconnected
  while (!mqttClient.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect - mqttClient.connect(DEVICE_ID, TOKEN, TOKEN)
    if (mqttClient.connect("Placa", token, token)) {
      Serial.println("connected");
      // Once connected, subscribe to rpc topic
      mqttClient.subscribe("v1/devices/me/rpc/request/+");
    } else {
      Serial.print("failed, rc=");
      Serial.print(mqttClient.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void setup() {
  pinMode(BUILTIN_LED, OUTPUT);     // Initialize the BUILTIN_LED pin as an output
  Serial.begin(115200);
  setup_wifi();
  mqttClient.setServer(mqtt_server, 1883);
  mqttClient.setCallback(callback);
  sensores.begin();
}

void loop() {

  if (!mqttClient.connected()) {
    reconnect();
  }
  mqttClient.loop();
 

  unsigned long now = millis();
  if (now - lastMsg > 2000) {
    lastMsg = now;
    value = random(100);

    //Send value as telemetry
    DynamicJsonDocument resp(256);
    resp["value"] = value;
    char buffer[256];
    serializeJson(resp, buffer);
    mqttClient.publish("v1/devices/me/telemetry", buffer);
    
    Serial.print("Publish message [telemetry]: ");
    Serial.println(buffer);

    //sensores.requestTemperatures(); //Pregunta oor las temps
    //temp1 = sensores.getTempCByIndex(0); //Sensor 1
    resp["Temperatura 1"] = value;
    serializeJson(resp, buffer);
    mqttClient.publish("v1/devices/me/telemetry", buffer);

    //temp2 = sensores.getTempCByIndex(1); // Sensor 2
    resp["Temperatura 2"] = value;
    serializeJson(resp, buffer);
    mqttClient.publish("v1/devices/me/telemetry", buffer);
  }
}

```

![ThingsRandom](https://github.com/SisCom-PI2-2023-2/proyecto-plant-o-matic/blob/main/docs/assets/ThingsRandom.jpg)
