---
layout: post
title: "ThingsBoard Rule chains"
date: 2023-10-17 22:25:00 -0300
categories: posts
---

`Root`

![Root](/assets/Root.jpg)

`Temperatura`

- Entra el dato, verifica que sea telemetria y luego revisa si es device "termometro".
- No es, envia log "wrong device". Si es, toma el valor y resuelve la accion a tomar.

![Temperatura](/assets/Temperatura.jpg)

`Humedad`

- La logica es simimar a la de la temperatura pero cambian las acciones a tomar segun los parametros medidos.

![humedad](/assets/humedad.jpg)

- GRACIAS! @octarevetria

