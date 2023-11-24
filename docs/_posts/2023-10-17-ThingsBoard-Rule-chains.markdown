---
layout: post
title: "ThingsBoard Rule chains"
date: 2023-10-17 22:25:00 -0300
categories: posts
---

`Root`

![Root](https://github.com/SisCom-PI2-2023-2/proyecto-plant-o-matic/assets/142456291/Root.jpg)

`Temperatura`

- Entra el dato, verifica que sea telemetria y luego revisa si es device "termometro".
- No es, envia log "wrong device". Si es, toma el valor y resuelve la accion a tomar.

![Temperatura](https://github.com/SisCom-PI2-2023-2/proyecto-plant-o-matic/assets/142456291/Temperatura.jpg)

`Humedad`

- La logica es simimar a la de la temperatura pero cambian las acciones a tomar segun los parametros medidos.

![humedad](https://github.com/SisCom-PI2-2023-2/proyecto-plant-o-matic/assets/142456291/humedad.jpg)

- GRACIAS! @octarevetria

