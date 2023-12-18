---
layout: page
title: Resumen del Proyecto
permalink: /resumen/
---

### Determinar el enfoque del proyecto
A la hora de elegir un tema para desarrollar, el mantenimiento de los jardines fue una tematica que llamó significativamente nuestra atención. Principalmente porque sentiamos que con varias de las herramientas de ingeniería que existen en la actualidad este problema es mucho más abordable que antes.

### Descripción del problema
Optamos por destacar las amenazas que más atentan contra la sostenibilidad de un jardín tradicional, tales como plantas deshidratadas, plantas sofocadas y plantas expuestas a las heladas. Partiendo de esos desafíos, buscamos crear una solución que posibilite informar, controlar y actuar en relación con los obstáculos que pretendemos evitar. Las funciones de nuestra solución deben incluir: hidratar una planta deshidratada, ventilar una planta sofocada y emitir una alerta si una planta se encuentra en un nivel de frío peligroso. Además, toda esta información se presentará en un panel gráfico para que el usuario pueda interactuar de manera remota con el jardín.

### Solución planteada
Para diseñar una solución, optamos por considerar que un prototipo formado por cuatro pequeñas áreas de cultivo podría simular el comportamiento de un jardín o huerto doméstico. Cada área de cultivo estará equipada con un sensor de temperatura y otro de humedad. Estos dispositivos estarán conectados a una placa que enviará toda la información sobre el estado de los cultivos a una plataforma en internet. Por otra parte, el prototipo contará con una bomba de agua y dos ventiladores. Estos dispositivos también se conectarán a la placa mencionada anteriormente y podrán activarse automáticamente según sea necesario o manualmente por el usuario a través de la plataforma en línea.

En resumen el usuario tendrá a sus disposición estas funciones:
   * Definir la temperatura limite para encendido automático de ventiladores
   * Accionar los ventiladores de manera remota
   * Definir la humedad limite para encendido automático del riego
   * Accionar el riego de manera remota
   * Definir la temperatura para las alertas de helada
   * Disponer de humedad y temperatura de los cultivos a distancia

### Planificación de pruebas de concepto y prototipos
Se definieron varias pruebas conceptuales intentando preservar la modularidad entre ellas. Gracias a su modularidad, los integrantes del equipo pudieron trabajar simultáneamente en diferentes partes del proyecto, sin depender de otras tareas para avanzar. En un principio decidimos trabajar todos juntos en el diseño y elección de componentes, a partir de la llegada de materiales decidimos dividir el proyecto en dos pruebas iniciales.
Estas pruebas iniciales son:
   * Prueba de sensor de humedad y temperatura con placa ESP8266
   * Prueba de rule chains de ThingsBoard
     
##### Prueba de sensor de humedad y temperatura con placa ESP8266
El propósito de esta prueba es establecer la comunicación entre los sensores y la ESP8266. Elegimos comenzar por este punto porque ya estábamos familiarizados con sensores similares a los que íbamos a utilizar. Gracias a estos conocimientos previos, percibimos un menor riesgo, ya que partíamos con una ventaja por lo aprendido anteriormente. Algunos de los posibles problemas son el uso diversas bibliotecas y la existencia de distintas versiones del IDE de Arduino. 

##### Prueba de rule chains de ThingsBoard
El cometido de esta prueba consistió en comprender el funcionamiento de ThingsBoard mediante el uso de rulechains y establecer una rule chain que se alineara con la lógica de nuestra solución. Esta prueba contaba con varios riesgos, por eso decidimos destinarle dos integrantes del equipo. El principal obstáculo, era nuestra total inexperiencia con la plataforma ThingsBoard. Profundizando en este problema, no teníamos certeza de si las rule chains nos permitirían alcanzar toda la lógica y comunicación necesarias para desarrollar la solución que teníamos en mente. Además, en caso de necesitar necesitar alarmas no nos quedaba claro si era posible integrarlas a la rule chain.

Una vez desarrolladas las pruebas iniciales, la idea es continuar con pruebas para integrar el sensado con la plataforma. Es decir, recibir las telemetrías de los sensores en ThingsBoard en un panel gráfico acorde. Y a su vez, probar el envío de comandos desde ThingsBoard.

##### Prueba de comandos RPC envíados desde ThingsBoard
La siguiente prueba de concepto consistió en simular una conexión MQTT desde el panel gráfico de ThingsBoard hacia MQTTX, una herramienta destinada a clientes MQTT. La prueba ofrece la ventaja de validar la correcta transmisión del mensaje MQTT desde ThingsBoard. Si la prueba fuera enviando directamente a la placa y encontraramos un error, sería necesario diagnosticar si el problema se originó durante el envío o la recepción. Ocasionando grandes pérdidas de tiempo para todo el equipo. Con esta prueba, esperamos comprender cómo nuestros actuadores funcionan remotamente a través de ThingsBoard.

##### Prueba de integración de telemetrías de los sensores en panel de ThingsBoard
El objetivo es incorporar las mediciones de los sensores que recibe la placa a un panel gráfico ThingsBoard vía MQTT. Los desafíos que identificamos en lo previo son: manejar los mensajes de "telemetry" en el formato correcto, nuestro dsconocimiento del funcionamiento de los paneles gráficos de ThingsBoard y posibles diferencias de unidades en escalas de medición y timeseries. Idealmente, esta prueba de concepto nos permitiría visualizar las mediciones de los sensores en un panel gráfico de la plataforma ThingsBoard.

##### Prototipo 1

##### Prototipo final

### Experimentos
A continuación, analizaremos en detalle los distintos experimentos y evaluaciones mencionados anteriormente. Dirigiendo nuestra atención a los objetivos, examinaremos lo necesario a nivel hardware y software para realizar la prueba, lo aprendido durante el desarrollo del prototipo y determinaremos si logramos alcanzar nuestras metas. En caso de no lograrlas analizaremos el porque.

##### Concepto 1: Prueba de sensor de humedad y temperatura con placa ESP8266
El propósito de esta prueba es establecer la comunicación entre los sensores y la ESP8266. En el transcurso de la prueba decidimos ahondar un poco más y sumamos como objetivo visualizar los datos envíados en la plataforma. 
Los materiales utilizados fueron:
   * DS18B20 Sensor de temperatura
   * MK0280 Sensor de humedad
   * Módulo NODEMCU V3 Esp8266 wifi MK0882
   * Convertidor ADS1115
   * Protoboard
   
Referencias o guías de los componentes que necesitamos:
   * <a href="https://www.analog.com/media/en/technical-documentation/data-sheets/ds18b20.pdf">Datasheet DS18B20</a>
   * <a href="https://www.researchgate.net/profile/Mohamed-Fezari-2/publication/328265730_NodeMCU_V3_For_Fast_IoT_Application_Development/links/5bc1f82b458515a7a9e71ac1/NodeMCU-V3-For-Fast-IoT-Application-Development.pdf">Guía ESP8266</a>
   * <a href="https://components101.com/modules/soil-moisture-sensor-module">Guía sensor de humedad</a>
   * <a href="https://cdn-shop.adafruit.com/datasheets/ads1115.pdf">Datasheet ADS1115</a>
   
La prueba salió como esperabamos ya que pudimos efectivamente sensar y ver los resultados en la plataforma. Queriamos probar varios sensores en simultaneo, pero obviamos que la placa solo contaba con una entrada analógica. Por lo tanto los sensores fueron probados por separado. Gracias a esta prueba comprendimos que necesitariamos de un convertidor A/D para sensar varias temperaturas y humedades en simultáneo. Una vez incorporado el convertidor A/D con ayuda de un panel gráfico predeterminado probamos la visualización de los valores en ThingsBoard. Este ensayo también fue satisfactorio.

El código utilizado y el video de los resultados de esta prueba se pueden encontrar en los detalles de nuestra bitácora, a continuación pueden encontrar un enlace a la misma. 
<a href="https://siscom-pi2-2023-2.github.io/proyecto-plant-o-matic/posts/2023/10/23/Prueba-sensores.html">Prueba de sensores - Bitácora</a>

##### Concepto 2: Prueba de rule chains de ThingsBoard
El cometido de esta prueba es comprender el funcionamiento de ThingsBoard mediante el uso de rulechains y diseñar una rule chain que se adecuará con la lógica de nuestra solución.
Toda la prueba fue desarrollada dentro de la plataforma ThingsBoard.

Como guía y referencia para poder avanzar con las pruebas utilizamos:
   * <a href="https://thingsboard.io/docs/user-guide/rule-engine-2-0/re-getting-started/">Intro de Rule Engines</a>
   * <a href="https://thingsboard.io/docs/reference/mqtt-api/">Guía para MQTT de ThingsBoard</a>
   * <a href="https://thingsboard.io/docs/user-guide/ui/rule-chains/">Guía para Rule Chains</a>

En esta evaluación, comenzamos desde la cadena raíz original y optamos por incorporar un salto a una cadena nueva cuando el mensaje recibido fuera una telemetría. Iniciamos con la cadena de sensado de temperatura y humedad porque era la lógica con la que estábamos más familiarizados. Realizamos todos los tests con los comandos -curl en consola y con el debug de la rule chain. Esta prueba no fue exitosa, el desarrollo de la misma se extendió más de lo esperado. Y no logramos incorporar alarmas en la rule chain. El fracaso de esta prueba se debió a varios factores:
   * Desconocimiento de la plataforma
   * Solo se realizaron pruebas en la plataforma
   * No se realizó la lógica de manera modular
   * No se realizó un esquema con los distintas interacciones entre la placa y la plataforma
   * Concentrarse demasiado en los perfiles y dispositivos

Desde el principio, habría sido ventajoso considerar todas las posibles interacciones entre la placa y la plataforma. Es decir, identificar cuándo era necesario enviar un mensaje MQTT del tipo RPC, cuándo una Telemetría y cuándo un Atributo. Definir qué enviaría la placa o la plataforma y qué tipo de mensaje se esperaría. Con toda esta información disponible, la elección de bloques para la lógica hubiera sido mucho más adecuada. A su vez, la realización de toda la lógica en la plataforma sin validación por fuera del debug y ping de dispositivos, dificulto mucho a la hora de intentar unificar la cadena con las señales reales de la solución.
Finalmente, si pudieramos rehacer esta prueba, destinariamos mucho más tiempo a la división y comprensión de las herramientas necesarias de la solución. Centrandonos en los roles de la placa y la plataforma en cada uno de los estados de la lógica del problema.

Las capturas de las cadenas diseñadas para la prueba de concepto son parte de nuestra bitácora, como podrán ver en el enlace. <a href="https://siscom-pi2-2023-2.github.io/proyecto-plant-o-matic/posts/2023/10/18/ThingsBoard-Rule-chains.html">Prueba de Rulechains - Bitácora</a>

##### Concepto 3: Prueba de comandos RPC envíados desde ThingsBoard
La siguiente prueba conceptual implicó simular una conexión MQTT desde el panel gráfico de ThingsBoard hacia la placa, solo que el programa MQTTX simularía el rol de la placa. Con ayuda del widget "Knob Control" del panel gráfico de ThingsBoard pudimos definir funciones RPC para entender su funcionamiento y como interactuarían con las variables definidas en la placa. Planteamos una función para operar una variable booleana, como puede ser el estado de un LED. 

La prueba fue exitosa, ya que pudimos validar que el envío de ThingsBoard era correcto, permitiendonos poner toda nuestra atención en la recepción de la placa. En el enlace a la bitácora se podrá ver en la penúltima imagen, una captura de una parte de lo probado. 
<a href="https://github.com/SisCom-PI2-2023-2/proyecto-plant-o-matic/blob/main/docs/_posts/2023-11-11-Pudimos-enviarle-al-Knob-Control.markdown">Captura de las pruebas en MQTTX</a>

##### Concepto 3: Prueba de integración de telemetrías de los sensores en ThingsBoard


##### Prueba de boton toggle
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

![s-l1600](/assets/s-l1600.jpg)
