---
layout: post
title: "Prueba Sensores"
date: 2023-10-23 16:00:00 -0300
categories: posts
---

codigo 20 octubre Martin

```c++

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <OneWire.h>
#include <DallasTemperature.h>

//OneWire oneWire(2);
OneWire tierra(2);

//DallasTemperature sensor1(&oneWire);
DallasTemperature sensor2(&tierra);

void setup() {
  delay(1000);
  Serial.begin(9600);
  //sensor1.begin();   //Se inicia el sensor
  sensor2.begin();
}

void loop() {

//sensor2.requestTemperatures();   //Se envía el comando para leer la temperatura
//float temp1= sensor1.getTempCByIndex(0); //Se obtiene la temperatura en ºC

sensor2.requestTemperatures();   //Se envía el comando para leer la temperatura
float temp2= sensor2.getTempCByIndex(0); //Se obtiene la temperatura en ºC
float temp1= sensor2.getTempCByIndex(1); //Se obtiene la temperatura en ºC

Serial.print("Temperatura 1 = ");
Serial.print(temp1);
Serial.println(" C");
delay(1000); 
Serial.print("Temperatura 2 = ");
Serial.print(temp2);
Serial.println(" C");
delay(1000);
  
}

```

![Pruebasensores](https://github.com/SisCom-PI2-2023-2/proyecto-plant-o-matic/blob/main/docs/assets/Pruebasensores.jpg)

https://www.youtube.com/shorts/7EKZ_7OAp7w
