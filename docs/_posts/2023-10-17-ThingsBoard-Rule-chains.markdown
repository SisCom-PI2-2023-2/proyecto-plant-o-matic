---
layout: post
title: "ThingsBoard Rule chains"
date: 2023-10-17 22:25:00 -0300
categories: posts
---

# Usuario Thingsboard

Octavio creó un usuario en Thingsboard Cloud para ir realizando pruebas.

`Root`

![Root](/proyecto-plant-o-matic/assets/Root.jpg)

`Temperatura`

![Temperatura](/proyecto-plant-o-matic/assets/Temperatura.jpg)

Entra el dato, verifica que sea telemetria y luego revisa si es device "termometro".
- No es, envia log "wrong device". Si es, toma el valor y resuelve la accion a tomar.
  
`Humedad`

![humedad](/proyecto-plant-o-matic/assets/humedad.jpg)

La logica es simimar a la de la temperatura pero cambian las acciones a tomar segun los parametros medidos.
- GRACIAS! @octarevetria

