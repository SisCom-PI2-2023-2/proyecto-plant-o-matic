---
layout: post
title: "ThingsBoard Rule chains"
date: 2023-10-17 22:25:00 -0300
categories: posts
---

`Usuario Thingsboard`
-
Octavio creó un usuario en Thingsboard Cloud para ir realizando pruebas.

`Root`
![Root](https://github.com/SisCom-PI2-2023-2/proyecto-plant-o-matic/blob/main/docs/assets/Root.jpg)
`Temperatura`
- Entra el dato, verifica que sea telemetria y luego revisa si es device "termometro".
- No es, envia log "wrong device". Si es, toma el valor y resuelve la accion a tomar.
![Temperatura](https://github.com/SisCom-PI2-2023-2/proyecto-plant-o-matic/blob/main/docs/assets/Temperatura.jpg)
`Humedad`
- La logica es simimar a la de la temperatura pero cambian las acciones a tomar segun los parametros medidos.
![humedad](https://github.com/SisCom-PI2-2023-2/proyecto-plant-o-matic/blob/main/docs/assets/humedad.jpg)
- GRACIAS! @octarevetria

