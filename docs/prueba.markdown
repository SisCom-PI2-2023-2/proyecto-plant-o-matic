---
layout: page
title: Resumen del Proyecto
permalink: /resumen/
---

#### Determinar el enfoque del proyecto
A la hora de elegir un tema para desarrollar, el mantenimiento de los jardines fue una tematica que llamó significativamente nuestra atención. Principalmente porque sentiamos que con varias de las herramientas de ingeniería que existen en la actualidad este problema es mucho más abordable que antes.

#### Descripción del problema
Optamos por destacar las amenazas que más atentan contra la sostenibilidad de un jardín tradicional, tales como plantas deshidratadas, plantas sofocadas y plantas expuestas a las heladas. Partiendo de esos desafíos, buscamos crear una solución que posibilite informar, controlar y actuar en relación con los obstáculos que pretendemos evitar. Las funciones de nuestra solución deben incluir: hidratar una planta deshidratada, ventilar una planta sofocada y emitir una alerta si una planta se encuentra en un nivel de frío peligroso. Además, toda esta información se presentará en un panel gráfico para que el usuario pueda interactuar de manera remota con el jardín.

#### Solución planteada
Para diseñar una solución, optamos por considerar que un prototipo formado por cuatro pequeñas áreas de cultivo podría simular el comportamiento de un jardín o huerto doméstico. Cada área de cultivo estará equipada con un sensor de temperatura y otro de humedad. Estos dispositivos estarán conectados a una placa que enviará toda la información sobre el estado de los cultivos a una plataforma en internet. Por otra parte, el prototipo contará con una bomba de agua y dos ventiladores. Estos dispositivos también se conectarán a la placa mencionada anteriormente y podrán activarse automáticamente según sea necesario o manualmente por el usuario a través de la plataforma en línea.

En resumen el usuario tendrá a sus disposición estas funciones:
   * Definir la temperatura limite para encendido automático de ventiladores
   * Accionar los ventiladores de manera remota
   * Definir la humedad limite para encendido automático del riego
   * Accionar el riego de manera remota
   * Definir la temperatura para las alertas de helada
   * Disponer de humedad y temperatura de los cultivos a distancia

## Planificación de pruebas y validación de conceptos
Se definieron varias pruebas conceptuales intentando preservar la modularidad entre ellas. Gracias a su modularidad, los integrantes del equipo pudieron trabajar simultáneamente en diferentes partes del proyecto, sin depender de otras tareas para avanzar. En un principio decidimos trabajar todos juntos en el diseño y elección de componentes, a partir de la llegada de materiales decidimos dividir el proyecto en tres pruebas de concepto iniciales:
   * Prueba de sensor de humedad y temperatura con placa ESP8266
   * Prueba de rule chains de ThingsBoard
   * Desarrollo de GitHub Pages con Bitácora
     
El principal riesgo de este tipo de pruebas, es que aunque los conceptos puedan funcionar de manera independiente, es necesario unificarlos para lograr una solución, y en ese proceso suelen surgir problemas en los límites.

La siguiente prueba de concepto consistió en simular una conexión MQTT desde el panel gráfico de ThingsBoard hacia MQTTX, una herramienta destinada a clientes MQTT. La prueba ofrece la ventaja de validar la correcta transmisión del mensaje MQTT desde ThingsBoard. En caso de la prueba fuera enviando directamente a la placa y encontraramos un error, sería necesario diagnosticar si el problema se originó durante el envío o la recepción. Ocasionando grandes pérdidas de tiempo para todo el equipo.

#### Prueba de boton toggle
##### Fotos y descripción
##### Items de la prueba, hardware y software
##### Debe incluir datasheets y especificaciones de sensores y componentes
##### Enlace al código de la prueba en GitHub
##### Se evalua lo que salio bien y mal de cada prueba

#### Prueba de sensores con placa Marta
##### Fotos y descripción
##### Items de la prueba, hardware y software
##### Debe incluir datasheets y especificaciones de sensores y componentes
##### Enlace al código de la prueba en GitHub
##### Se evalua lo que salio bien y mal de cada prueba

## Demo o Exposición de la solución
#### Diagrama de la solución
#### Enlace al código final en GitHub
#### Incluir justificación de decisiones en base al anteproyecto
#### Reflexión del proyecto, explicar que salio mal y que podria mejorarse
Quotes

   > Cita o recuadro


