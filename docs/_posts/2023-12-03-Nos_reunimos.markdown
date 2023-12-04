---
layout: post
title: "Nos_reunimos"
date: 2023-12-03 12:30:00 -0300
categories: posts
---
´Reunión´
Nos reunimos para poder cerrar algunas ideas y seguir haciando pruebas.

 - Javier llegó a un código "final
 - Martín hizo funcionar el sensor de humedad

   ```c++
   #include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>
#include <DallasTemperature.h>
#include <Wire.h>
#include <Adafruit_ADS1X15.h>
#include <map>
#include <string>


class Auxiliar {
private:
    std::string plantaActual;
    std::map<std::string, std::pair<std::pair<int, int>, std::pair<int, int>>> datosDePlantas;

    void inicializarDatosDePlantas() {
        datosDePlantas["Rosa"] = {{15, 29}, {40, 70}};
        datosDePlantas["Cactus"] = {{20, 35}, {10, 30}};
        datosDePlantas["Helecho"] = {{18, 35}, {60, 80}};
        datosDePlantas["Orquídea"] = {{16, 35}, {55, 75}};
        // Agregar más plantas según sea necesario
    }

public:
    Auxiliar(const std::string& planta) {
        inicializarDatosDePlantas();
        auto it = datosDePlantas.find(planta);
        if (it != datosDePlantas.end()) {
            plantaActual = planta;
        } else {
            Serial.println("Planta desconocida");
            plantaActual = "DefaultPlant";
        }
    }

    std::array<int, 4> getPlantThresholds() {
        auto rango = datosDePlantas[plantaActual];
        return {rango.first.first, rango.first.second, rango.second.first, rango.second.second};
    }

    bool esTemperaturaAdecuada(int temp) {
        auto rango = datosDePlantas[plantaActual].first;
        return temp >= rango.first && temp <= rango.second;
    }

    bool esHumedadAdecuada(int humedad) {
        auto rango = datosDePlantas[plantaActual].second;
        return humedad >= rango.first && humedad <= rango.second;
    }

    void cambiarPlanta(const std::string& nuevaPlanta) {
        auto it = datosDePlantas.find(nuevaPlanta);
        if (it != datosDePlantas.end()) {
            plantaActual = nuevaPlanta;
        } else {
            Serial.println("Planta desconocida");
            plantaActual = "DefaultPlant";
        }
    }
};

unsigned long lastTemperatureSignalTime = 0;
unsigned long lastHumiditySignalTime = 0;
const unsigned long signalInterval = 1200000; // 20 minutes in milliseconds
const unsigned long humiditySignalDuration = 5000; // 5 seconds in milliseconds

// Crear una version de la clase
Auxiliar miPlanta("Rosa");

// Update these with values suitable for your network.
const char* ssid = "Manuel-5GHz";
const char* password = "26831706";
const char* mqtt_server = "demo.thingsboard.io"; //"104.196.24.70";
const char* token = "yxBvaTo366CtIrbS4ZDI";
// {clientId:"rbp222y1d1717mqq2jdr",userName:"martin",password:"123456"}

// Temperature objects
OneWire temperatura(2);
DallasTemperature sensores(&temperatura);

//Analogic objects
Adafruit_ADS1115 ads;

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
      Serial.println(buffer);
    }
    if (metodo == "getValue") {
        /*sensores.requestTemperatures(); // Request temperatures
        int temp1 = sensores.getTempCByIndex(0); // Sensor 1
        String dataJS = "{\"Temperatura 1\":" + String(temp1, 3) + "}";
        char json[100];
        dataJS.toCharArray(json, dataJS.length() + 1);
        mqttClient.publish("v1/devices/me/telemetry", json);*/
      //char json[100];
      //dataJS.toCharArray(json, dataJS.length() + 1);
      char outTopic[128];
      ("v1/devices/me/rpc/response/" + _number).toCharArray(outTopic,128);
      DynamicJsonDocument resp(256);
      resp["params"] = "true";
      char buffer[256];
      serializeJson(resp, buffer);


    } else if (metodo == "getTemperature2") { //ESTO NO CREO QUE SE USE
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

    } else if (metodo == "setValueBomba") {
        boolean estado = incoming_message["params"];
        if (estado) {
            digitalWrite(16, LOW); // ENCENDER BOMBA DE AGUA
        } else {
            digitalWrite(16, HIGH); // APAGAR BOMBA DE AGUA
        }
        Serial.println("entro1");
        // Attribute update
        DynamicJsonDocument resp(256);
        resp["estado"] = estado;
        char buffer[256];
        serializeJson(resp, buffer);
        resp["bombaDeAgua"] = estado;
        serializeJson(resp, buffer);
        mqttClient.publish("v1/devices/me/attributes", buffer);
        Serial.print("Publish message [attribute]: ");
        Serial.println(buffer);
    }
    else if (metodo == "setValueFan") {
        boolean estado_fan = incoming_message["params"];
        if (estado_fan) {
            digitalWrite(16, LOW); // ENCENDER BOMBA DE AGUA
        } else {
            digitalWrite(16, HIGH); // APAGAR BOMBA DE AGUA
        }
        // Attribute update
        DynamicJsonDocument resp(256);
        
        resp["estado_fan"] = estado_fan;
        char buffer2[256];
        serializeJson(resp, buffer2);
        resp["ventilador"] = estado_fan;
        serializeJson(resp, buffer2);
        mqttClient.publish("v1/devices/me/attributes", buffer2);
        Serial.print("Publish message [attribute]: ");
        Serial.println(buffer2);
    
    }
    else if (metodo == "5") {
         char outTopic[128];
         String salida = "1";
        ("v1/devices/me/rpc/response/" + _number).toCharArray(outTopic,128);
        if (salida == "1") {
          salida = "0";
        }else {
          salida = "1";
        }
       
        mqttClient.publish(outTopic, salida.c_str());
        Serial.println(outTopic);
        
    }
  }
}

void reconnect() {
  // Loop until we're reconnected
  while (!mqttClient.connected()) {
    Serial.println("Attempting MQTT connection...");
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
  pinMode(16, OUTPUT);
  pinMode(15, OUTPUT); // Set pin 15 as output for the fan
  pinMode(BUILTIN_LED, OUTPUT);     // Initialize the BUILTIN_LED pin as an output
  Serial.begin(115200);
  setup_wifi();
  mqttClient.setServer(mqtt_server, 1883);
  mqttClient.setCallback(callback);
  sensores.begin();
  ads.begin();
  delay(1000);
}

int humidityOutput(int humidity) {
    // Get the plant's humidity thresholds
    auto thresholds = miPlanta.getPlantThresholds();
    int minHumidity = thresholds[2];

    // Calculate the humidity deficit
    int humidityDeficit = minHumidity - humidity;

    // Variables for delay time and return value
    int delayTime = 0;
    int returnValue = 0;

    // Adjust delay time based on humidity deficit
    if (humidityDeficit > 0) {
        if (humidityDeficit > 30) {
            delayTime = 25000;
            returnValue = 25;
        } else if (humidityDeficit > 20) {
            delayTime = 15000;
            returnValue = 15;
        } else if (humidityDeficit > 10) {
            delayTime = 8000;
            returnValue = 8;
        } else {
            Serial.println("Humidity is close to the suitable range. Minor or no action needed.");
            return 0;
        }

        digitalWrite(16, HIGH);
        delay(delayTime);
        digitalWrite(16, LOW);
    } else {
        Serial.println("Humidity is within or above the suitable range. No action needed.");
        return 0;
    }

    return returnValue;
}

void controlFan(int measuredTemp, bool &fanState) {
    // Retrieve the maximum temperature threshold for the plant
    auto thresholds = miPlanta.getPlantThresholds();
    int maxTemperature = thresholds[1];

    if (measuredTemp > maxTemperature || measuredTemp < 5) {
        // If the temperature is higher than the max threshold or lower than 5 degrees, turn on the fan
        if (!fanState) {
            digitalWrite(15, HIGH); // Turn on the fan
            fanState = true;
            Serial.println("Fan turned ON");
        }
    } else {
        // If the temperature is within the range, turn off the fan
        if (fanState) {
            digitalWrite(15, LOW); // Turn off the fan
            fanState = false;
            Serial.println("Fan turned OFF");
        }
    }
}

int handleAndPublishTemperature(int sensorIndex, const char* telemetryTopic) {
    sensores.requestTemperatures();
    int temperature = sensores.getTempCByIndex(sensorIndex);

    DynamicJsonDocument resp(256);

    if (sensorIndex == 0) {
      resp["Temperatura 1"] = temperature;
      char buffer[256];
      serializeJson(resp, buffer);
      mqttClient.publish(telemetryTopic, buffer);
      Serial.print("Publish Message [telemetry]: ");
      Serial.println(buffer);
    } else if (sensorIndex == 1) {
      resp["Temperatura 2"] = temperature;
      char buffer[256];
      serializeJson(resp, buffer);
      mqttClient.publish(telemetryTopic, buffer);
      Serial.print("Publish Message [telemetry]: ");
      Serial.println(buffer);
    } else {
        Serial.println("Invalid sensor index");
        return -1; // Return -1 for invalid sensor index
    }

    return temperature; // Return the measured temperature
}

int handleAndPublishHumidity(int sensorIndex, const char* telemetryTopic) {
    int humidity;
    String humidityKey;

    if (sensorIndex == 0) {
        humidity = map(ads.readADC_SingleEnded(0), 0, 32767, 100, 0); // Sensor 1
        //humidity = ads.readADC_SingleEnded(0);
        //humidity = 20;
        humidityKey = "Humedad 1";
    } else if (sensorIndex == 1) {
        //humidity = map(ads.readADC_SingleEnded(1), 0, 32767, 100, 0); // Sensor 2
        humidity = 40;
        humidityKey = "Humedad 2";
    } else {
        Serial.println("Invalid sensor index");
        return -1; // Return -1 for invalid sensor index
    }

    DynamicJsonDocument resp(256);
    char buffer[256];

    resp[humidityKey] = humidity;
    serializeJson(resp, buffer);
    mqttClient.publish(telemetryTopic, buffer);
    Serial.print("Publish Message [telemetry]: ");
    Serial.println(buffer);

    return humidity; // Return the measured humidity
}

const float pi = 3.14159265358979323846; // Valor de pi

// Función para calcular el volumen de agua que pasa por el tubo
float calcularVolumen(float diametro, float tiempo) {
  // Calcular el área de la sección transversal
  float area = (pi * diametro * diametro) / 4.0;

  // Calcular el volumen de agua (volumen = área * tiempo)
  float volumen = area * tiempo;

  return volumen;
}

void loop() {
    if (!mqttClient.connected()) {
        reconnect();
    }
    mqttClient.loop();

    unsigned long now = millis();
    value = random(100);
    bool fanState = false;
    // Handle thermometer 1
    float temp_medida0 = handleAndPublishTemperature(0, "v1/devices/me/telemetry");
    controlFan(temp_medida0, fanState);
    

    // Handle thermometer 2
    float temp_medida1 = handleAndPublishTemperature(1, "v1/devices/me/telemetry");

    // Handle humidity sensor 1
    float humid_medida0 = handleAndPublishHumidity(0, "v1/devices/me/telemetry");
    int tiempo_encendido = humidityOutput(humid_medida0);
    float volumenDeAgua = calcularVolumen(5, tiempo_encendido);
    DynamicJsonDocument volumenDoc(256);
    volumenDoc["volumen"] = volumenDeAgua;
    char volumenBuffer[256];
    serializeJson(volumenDoc, volumenBuffer);
    mqttClient.publish("v1/devices/me/telemetry", volumenBuffer);
    Serial.print("Publish Message [volumen_total]: ");
    Serial.println(volumenBuffer);
        
    // Handle humidity sensor 2
    float humid_medida1 = handleAndPublishHumidity(1, "v1/devices/me/telemetry");

    // float volumenDeAgua = calcularVolumen(diametroDelTubo, tiempoDeFlujo);

}

```


