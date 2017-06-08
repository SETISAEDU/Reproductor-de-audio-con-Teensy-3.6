# Reproductor-de-audio-con-Teensy-3.6

El desarrollo de este proyecto consiste en reproducir diferentes audios desde la tarjeta de desarrollo Teensy 3.6, donde hacemos uso de sus salidas analogicas DAC para obtener sonido estério. Ademas se utilizara la ranura ranura micro SD integrado en la tarjeta Teensy 3.6 Para insertar una memoria micro SD que contendrá los archivos de audio que serán reproducidos.

## Comunicación entre una memoria micro SD y un microcontrolador.

Su simplicidad y sus prestaciones de capacidad y velocidad hacen que una tarjeta de memoria SD o una MicroSD sea un sistema excelente para almacenar información  desde un dispositivo basado en un microcontrolador.

La comunicacion de la memoria micro SD con un microcontrolador se puede hacer por medio del protocolo PSI. El SPI es un protocolo de comunicación  síncrona de 4 hilos, entre dispositivos electrónicos presentado por Motorola en 1982, que ha ganado bastante aceptación en la industria como sistema de comunicación de muy corta distancia, normalmente dentro la placa de circuito impreso.

Es un protocolo de transmisión que permite alcanzar velocidades muy altas y que se diseñó pensando en comunicar un micro controlador con distintos periféricos y que funciona a full dúplex (Una forma retorcida de decir que puede enviar y recibir datos al mismo tiempo).

SPI utiliza una solución síncrona, porque utiliza unas líneas diferentes para los datos y el Clock. El Clock es una señal que indica al que escucha exactamente cuándo leer las líneas de datos, con lo que el problema de perdida de sincronía se elimina de raíz.

Para controlar el bus SPI es necesario usar los pines que específica cada tarjeta que este utilizando. Para la tarjeta Teensy 3.6 se ha utlizado los pines SCK2, MISO2, MOSI2, CS2. 

![Pines designado a la comunicacion SPI](https://raw.githubusercontent.com/SETISAEDU/Reproductor-de-audio-con-Teensy-3.6/master/card9b_rev1.png)



## Diseño de sistemas de audio.

Para el desarrollo de este proyecto utilizaremos la herramienta para diseñar sistemas de audio proporcionada por los fabricantes de la tarjeta Teensy. Esta herramienta de diseño nos permite dibujar nuestros sistemas de audio de una forma muy interactiva y exportar como código al software Arduino IDE. Además, la herramienta nos nuestra las funciones proporcionadas por los diferentes objetivos, las cuales pueden ser llamadas en el void setup o void loop.

El sistema de audio diseñado para el presente proyecto fue el siguiente:

El código generado se anexo al programa llamado `Reproductor.ino` que sera el programa que se cargará a la tarjeta Teensy 3.6




