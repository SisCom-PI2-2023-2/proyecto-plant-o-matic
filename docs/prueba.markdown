---
layout: page
title: Resumen del Proyecto
permalink: /resumen/
---

### Determinar el enfoque del proyecto
A la hora de elegir un tema para desarrollar, el mantenimiento de los jardines fue una temática que llamó significativamente nuestra atención. Principalmente porque sentíamos que con varias de las herramientas de ingeniería que existen en la actualidad este problema es mucho más abordable que antes.

### Descripción del problema
Optamos por destacar las amenazas que más atentan contra la sostenibilidad de un jardín tradicional, tales como plantas deshidratadas y plantas sofocadas que necesitan ser atendidas. Partiendo de esos desafíos, buscamos crear una solución que posibilite informar, controlar y actuar en relación con los obstáculos que pretendemos evitar. 

Las funciones de nuestra solución deben incluir: hidratar una planta deshidratada, ventilar una planta sofocada y monitoreo de valores vitales para los cultivos. Además, toda esta información se presentará en un panel gráfico para que el usuario pueda interactuar de manera remota con el jardín.

### Solución planteada
Para diseñar una solución, optamos por considerar que un prototipo formado por una pequeña área de cultivo podría simular el comportamiento de un jardín o huerto doméstico. El área de cultivo estará equipada con dos sensores de temperatura y dos de humedad. Para sensar los parámetros a la altura de la planta y también en la tierra y raíces. Estos dispositivos estarán conectados a una placa que enviará toda la información sobre el estado de los cultivos a una plataforma en internet. 

Por otra parte, el prototipo contará con una bomba de agua y un ventilador. Estos dispositivos también se conectarán a la placa mencionada anteriormente y podrán activarse automáticamente según sea necesario o manualmente por el usuario a través de la plataforma en línea.

En resumen el usuario tendrá a sus disposición estas funciones:
   * Accionar la ventilación de manera remota
   * Accionar el riego de manera remota
   * Encendido de ventilación y riego de manera automática para cada tipo de planta
   * Disponer de humedad y temperatura de los cultivos a distancia

### Planificación de pruebas de concepto y prototipos
Se definieron varias pruebas conceptuales intentando preservar la modularidad entre ellas. Gracias a su modularidad, los integrantes del equipo pudieron trabajar simultáneamente en diferentes partes del proyecto, sin depender de otras tareas para avanzar. En un principio decidimos trabajar todos juntos en el diseño y elección de componentes, a partir de la llegada de materiales decidimos dividir el proyecto en dos pruebas iniciales.

Estas pruebas iniciales son:
   * Prueba de sensor de humedad y temperatura con placa ESP8266
   * Prueba de rule chains de ThingsBoard
     
##### Prueba de sensor de humedad y temperatura con placa ESP8266
El propósito de esta prueba es establecer la comunicación entre los sensores y la ESP8266. Elegimos comenzar por este punto porque ya estábamos familiarizados con sensores similares a los que íbamos a utilizar. Gracias a estos conocimientos previos, percibimos un menor riesgo, ya que partíamos con una ventaja por lo aprendido anteriormente. Algunos de los posibles problemas son el uso diversas bibliotecas y la existencia de distintas versiones del IDE de Arduino. 

##### Prueba de rule chains de ThingsBoard
El cometido de esta prueba consistió en comprender el funcionamiento de ThingsBoard mediante el uso de rulechains y establecer una rule chain que se alineara con la lógica de nuestra solución. Esta prueba contaba con varios riesgos, por eso decidimos destinarle dos integrantes del equipo. El principal obstáculo, era nuestra total inexperiencia con la plataforma ThingsBoard. Profundizando en este problema, no teníamos certeza de si las rule chains nos permitirían alcanzar toda la lógica y comunicación necesarias para desarrollar la solución que teníamos en mente. Además, en caso de necesitar alarmas no nos quedaba claro si era posible integrarlas a la rule chain.

Una vez desarrolladas las pruebas iniciales, el plan es continuar con pruebas para integrar el sensado con la plataforma. Es decir, recibir las telemetrías de los sensores en ThingsBoard en un panel gráfico acorde. Y a su vez, probar el envío de comandos desde ThingsBoard.

##### Prueba de comandos RPC envíados desde ThingsBoard
La siguiente prueba de concepto consistió en simular una conexión MQTT desde el panel gráfico de ThingsBoard hacia MQTTX, una herramienta destinada a clientes MQTT. La prueba ofrece la ventaja de validar la correcta transmisión del mensaje MQTT desde ThingsBoard. Si la prueba fuera enviando directamente a la placa y encontraramos un error, sería necesario diagnosticar si el problema se originó durante el envío o la recepción. Ocasionando pérdidas de tiempo para todo el equipo. Con esta prueba, esperamos comprender cómo nuestros actuadores funcionan remotamente a través de ThingsBoard.

##### Prueba para accionadores
Con este prototipo buscamos controlar el accionado de la bomba y el ventilador. Que luego será integrado al prototipo de accionadores de nuestro proyecto. Nuestro objetivo es poder activarlos de manera manual y remota. Y para eso necesitamos adecuar la tensión de control a los valores necesarios. Lo posibles problemas que pueden presentarse son: falta de corriente para la bomba de agua y manejo de los retardos para el correcto funcionamiento de la solución.

##### Prototipo de Dashboard con accionado manual y automático
Nos parece crucial, una vez funcionales los actuadores, la integración de los mismos con la plataforma. Esto nos permitirá comprender posibles estados o situaciones no previstos. Asimismo, es esencial tener en cuenta posibles retrasos o zonas grises que puedan dificultar el funcionamiento del sistema.

### Experimentos
A continuación, analizaremos en detalle los distintos experimentos y evaluaciones mencionados anteriormente. Dirigiendo nuestra atención a los objetivos, examinaremos lo necesario a nivel hardware y software para realizar la prueba, lo aprendido durante el desarrollo del prototipo y determinaremos si logramos alcanzar nuestras metas. En caso de no lograrlas analizaremos el porqué.

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

En esta evaluación, comenzamos desde la cadena raíz original y optamos por incorporar un salto a una cadena nueva cuando el mensaje recibido fuera una telemetría. Iniciamos con la cadena de sensado de temperatura y humedad porque era la lógica con la que estábamos más familiarizados. Realizamos todos los tests con los comandos -curl en consola y con el debug de la rule chain. Esta prueba no fue exitosa, el desarrollo de la misma se extendió más de lo esperado. Y no logramos incorporar alarmas en la rule chain. 

El fracaso de esta prueba se debió a varios factores:
   * Desconocimiento de la plataforma
   * Solo se realizaron pruebas en la plataforma
   * No se realizó la lógica de manera modular
   * No se realizó un esquema con los distintas interacciones entre la placa y la plataforma
   * Concentrarse demasiado en los perfiles y dispositivos

Desde el principio, habría sido ventajoso considerar todas las posibles interacciones entre la placa y la plataforma. Es decir, identificar cuándo era necesario enviar un mensaje MQTT del tipo RPC, cuándo una Telemetría y cuándo un Atributo. Definir qué enviaría la placa o la plataforma y qué tipo de mensaje se esperaría. Con toda esta información disponible, la elección de bloques para la lógica hubiera sido mucho más adecuada. A su vez, la realización de toda la lógica en la plataforma sin validación por fuera del debug y ping de dispositivos, dificultó mucho a la hora de intentar unificar la cadena con las señales reales de la solución.

Finalmente, si pudieramos rehacer esta prueba, destinariamos mucho más tiempo a la división y comprensión de las herramientas necesarias de la solución. Centrándonos en los roles de la placa y la plataforma en cada uno de los estados de la lógica del problema.

Las capturas de las cadenas diseñadas para la prueba de concepto son parte de nuestra bitácora, como podrán ver en el enlace. <a href="https://siscom-pi2-2023-2.github.io/proyecto-plant-o-matic/posts/2023/10/18/ThingsBoard-Rule-chains.html">Prueba de Rulechains - Bitácora</a>

##### Concepto 3: Prueba de comandos RPC envíados desde ThingsBoard
La siguiente prueba conceptual implicó simular una conexión MQTT desde el panel gráfico de ThingsBoard hacia la placa, solo que el programa MQTTX simularía el rol de la placa. Con ayuda del widget "Knob Control" del panel gráfico de ThingsBoard pudimos definir funciones RPC para entender su funcionamiento y como interactuarían con las variables definidas en la placa. Planteamos una función para operar una variable booleana, como puede ser el estado de un LED. 

La prueba fue exitosa, ya que pudimos validar que el envío de ThingsBoard era correcto, permitiendonos poner toda nuestra atención en la recepción de la placa. Los conocimientos que nos brindó esta práctica fueron, comprensión del formato de MQTT con Header fijo o variable y procedimiento de request y response de MQTT. En el enlace a la bitácora se podrá ver en la penúltima imagen, una captura de una parte de lo probado. 
<a href="https://github.com/SisCom-PI2-2023-2/proyecto-plant-o-matic/blob/main/docs/_posts/2023-11-11-Pudimos-enviarle-al-Knob-Control.markdown">Captura de las pruebas en MQTTX</a>

##### Concepto 4: Prueba para accionadores
El propósito era accionar nuestros actuadores con las señales de la placa. 

Los componentes que necesitamos fueron:
   * Módulo NODEMCU V3 Esp8266 wifi MK0882
   * Ventilador de 12V
   * Fuente de 5V de 2A
   * Transistor NPN P2N2222A
   * Resistencia de 1K ohm. 
   * Réle AX1RC-5V
   * Protoboard

Hojas de datos e información de referencia de algunos de los componentes:
   * <a href="https://datasheetspdf.com/pdf-file/1264803/METALTEX/AX1RC-5V/1">Datasheet Réle</a>
   * <a href="https://pchub.com/lffan-linfu-lfs0912gh-server-square-fan-lfs0912gh-p215294">Info del ventilador</a>
   * <a href="https://www.onsemi.com/pdf/datasheet/p2n2222a-d.pdf">Datasheet NPN</a>

Al realizar la prueba, aun no contabamos con una fuente de 12V con corriente suficiente para la bomba de agua. Entonces decidimos probar con una de 5V que teníamos a disposición que para el ventilador era más que suficiente. Diseñamos el circuito de manera de amplificar nuestra corriente de salida de la placa al valor necesario por los accionadores, utilizamos el transistor para alcanzar dicha corriente y asi conectar/desconectar la bobina dentro del réle. Logramos lo que buscabamos con un código que alternaba entre encendido y apagado. El ventilador efectivamente se apagaba y prendía acorde a lo programado. Video y código de la prueba: <a href="https://siscom-pi2-2023-2.github.io/proyecto-plant-o-matic/posts/2023/11/18/Prueba_bombas_y_ventiladores_MARTIN.html">Prueba accionadores</a>

##### Prototipo 1: Dashboard con accionado manual y automático
El objetivo de esta prueba es accionar un actuador desde el dashboard, intercalando entre modo manual y automático. Este prototipo comprende una parte importante de nuestra solución final. Que de funcionar bien validaría una porción importante de la solución final. 

Los componentes que necesitamos fueron:
   * Módulo NODEMCU V3 Esp8266 wifi MK0882
   * Ventilador de 12V
   * Fuente de 12V de 2A
   * Transistor NPN P2N2222A
   * DS18B20 Sensor de temperatura
   * MK0280 Sensor de humedad
   * Resistencia de 1K ohm
   * Convertidor ADS1115
   * Réle AX1RC-5V
   * Protoboard
   * Barra congelada

La prueba tuvo resultados de acuerdo a nuestras expectativas. Primero decidimos poner el ventilador en modo manual, y su funcionamiento fue tal como anticipábamos. Después, al elevar la temperatura del sensor a 25 grados Celsius con calor corporal, conseguimos activar el ventilador de manera automática. Posteriormente, al enfriarlo con una barra congelada, logramos reducirlo a 23 grados, lo que ocasionó el apagado automático del ventilador. Esta prueba nos permitió unificar varias de la partes del proyecto que fueron hechas por separado. Esto nos sirvió mucho de cara al armado de la solución final y la maqueta. El video del ensayo con el prototipo puede encontrarse como "video ventilador" en la bitácora. <a href="https://siscom-pi2-2023-2.github.io/proyecto-plant-o-matic/posts/2023/12/18/PRONTO.html">Prototipo de accionado</a>

### Demostración de la solución
Ensayo de la presentación completa de la solución con todas las partes correspondientes.

Los materiales que utilizamos fueron:
   * Módulo NODEMCU V3 Esp8266 wifi MK0882
   * Ventilador de 12V
   * Bomba limpia parabrisas de 12V
   * Manguera
   * Maceta de tierra
   * Fuente de 12V de 2A
   * Transistor NPN P2N2222A
   * 2x DS18B20 Sensor de temperatura
   * 2x MK0280 Sensor de humedad
   * Resistencia de 1K ohm
   * Convertidor ADS1115
   * 2x Réle AX1RC-5V
   * Protoboard
   * Jumpers
   * Barra congelada

En la demostración implementamos los perfiles de plantas para customizar los activados automáticos de los actuadores:
   * Rosa - Temperatura/Humedad: [15,29]/[40,70]
   * Cactus - Temperatura/Humedad: [20,35]/[10,30]
   * Helecho - Temperatura/Humedad: [18,35]/[60,80]
   * Orquídea - Temperatura/Humedad: [16,35]/[55,75]

Un ejemplo de lo que determina el perfil, en el caso del "Helecho". En el escenario donde el control automático esta activado, y la temperatura del sensor en la planta del Helecho supera los 35 grados Celsius. El ventilador se activaría de manera automática. Una vez, por debajo de los 35 grados este se apagaría solo. Por otro lado, si la humedad en la tierra del cultivo del Helecho cayera por debajo del 60% el riego se dispararía automáticamente. 

Además, se le incorporó un registro del volumen regado en lo que va del mes. Esto podrá verse con facilidad en el panel gráfico de la solución. 

Agregamos un esquemático de la solución final.

![esquema](/assets/esquema.jpg)

### Conclusión
Con respecto a lo planteado en el anteproyecto, se pudo alcanzar lo propuesto para el MVP exceptuando el uso de APIs para la obtención de valores óptimos. Como alternativa diseñamos una variedad de perfiles de plantas con los valores optimos sugeridos ya cargados en la placa para poder operar los actuadores de manera acorde.

Con respecto a la solución Estándar, entendemos que con más tiempo y mejores conocimientos previos de la plataforma podríamos haber incorporado el uso de APIs. 
Para la versión Premium, nos vimos limitados por el costo y dificultad de medición de las magnitudes elegidas. En particular, medir la conductividad del suelo requiere de un ensayo extenso y poco integrable a nuestro sistema. Por su complejidad decidimos descartar las mediciones de conductividad y PH.

En relación a posibles mejoras en la solución final, creemos que existe margen para ampliar nuestra maqueta. La bomba de 12V de agua cuenta con caudal suficiente para regar decenas de cultivos pequeños. 
Por otro lado, una vez implementados los perfiles de plantas, nos dimos cuenta que pudimos haber dejado un rango personalizable para el usuario. En dicho rango él elige la temperatura a partir de la cual accionar de manera autmática. Esto es útil, porque no todas las plantas pueden quedar contempladas dentro de los perfiles.

Otra posible mejora sería, la implementación de alertas para las cotas de los rangos sensados sin actuadores. Como lo son las plantas a temperaturas muy bajas o las plantas hiperhidratadas. Sus actuadores no son tan compatibles como el riego y la ventilación, pero una alerta podría advertir al usuario para intervenir de manera manual en su cultivo.

Finalmente, como mencionamos en la sección "experimentos", si tuviéramos la oportunidad de empezar de nuevo, abordaríamos las funcionalidades de ThingsBoard de manera más modular. Esta plataforma posee numerosas capacidades que pueden motivarnos a probar varias cosas simultáneamente y complicar aún más la resolución del problema. La integración de los documentos de casos de uso y guías en nuestro proceso de diseño es algo que debimos haber hecho desde el primer día que comenzamos con el proyecto.

### Enlace al código final en GitHub
<a href="https://github.com/SisCom-PI2-2023-2/proyecto-plant-o-matic/blob/main/c%C3%B3digos/c%C3%B3digo_final">Repositorio del código para el proyecto</a>
