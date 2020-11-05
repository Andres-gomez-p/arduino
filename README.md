# Arduino Laboratorio 5 
El sistema tiene dos modos de operación:
1. Modo Passthrough.
2. Modo Analog Reference.

El selector S3 permite la selección del modo de operación del sistema donde 1 (nivel lógico alto)
selecciona el primer modo y 0 (nivel lógico alto) el segundo.
El modo Passthrough muestra en los leds D0, D1 y D2 los valores que se seleccionen en S0, S1 y S2
respectivamente. El modo Analog Reference muestra en los Leds un estado del sistema teniendo
en cuenta el valor leído desde el ADC, un valor de referencia y una tolerancia seleccionada con S2,
S1 y S0. Para este modo, el valor de referencia son los 4 primeros dígitos del carné divido en 4; la
tolerancia se aplica sobre el valor de referencia y es un valor decimal seleccionado con S2, S1 y S0
(por ejemplo, la tolerancia mínima es de ±0% y máxima de ±7%); los leds muestran si el valor leído
desde el ADC se encuentra dentro o fuera del rango del rango de la tolerancia de la siguiente
manera:
- D2 se activa cuando el valor ADC supera la tolerancia positiva.
- D1 se activa cuando el valor ADC esta dentro del rango permitido por la tolerancia y el
valor de referencia.
- D0 se activa cuando el valor ADC está por debajo de la tolerancia negativa.
El led D3 muestra el modo de operación del sistema.

![WhatsApp Image 2020-11-05 at 9 09 11 AM](https://user-images.githubusercontent.com/69565998/98251474-be8cc380-1f46-11eb-828b-4d893721348b.jpeg)
![WhatsApp Image 2020-11-05 at 9 08 52 AM](https://user-images.githubusercontent.com/69565998/98251520-cba9b280-1f46-11eb-83db-a25303e92ab0.jpeg)
![WhatsApp Image 2020-11-05 at 9 08 18 AM](https://user-images.githubusercontent.com/69565998/98251534-cf3d3980-1f46-11eb-8a25-e8976d93b390.jpeg)
