🎮 Juego Simón Dice - Juego electrónico de memoria 

--------------

Nuestro proyecto "Juego Simón Dice" consiste en desarrollar un juego electrónico de memoria y reflejos inspirado en el clásico juego Simón / Signos.

El sistema está basado en Arduino y utiliza tres luces LED de diferentes colores, tres pulsadores, un buzzer, un potenciómetro y una pantalla LCD de 16x2.

El objetivo del juego es que el jugador memorice una secuencia de luces y sonidos generada por el sistema y luego la repita utilizando los botones correspondientes.

Cada vez que el jugador completa correctamente una ronda, el juego aumenta la dificultad y agrega nuevos elementos a la secuencia. El jugador debe recordar y repetir correctamente la secuencia para continuar avanzando.

--------------

INTEGRANTES DEL GRUPO:

- Alejandro Jesús Aloe — Correo: alejandroaloe24@gmail.com

- Nicolas Botto — Correo: nicolasbotto412@gmail.com

- Federico Ducret — Correo: fedeericoducret123@gmail.com
  
- Marcos Quispe — Correo: Canazajuan554@gmail.com

--------------

MATERIA Y DOCENTES:

- Laboratorio en Computación 1

- Rodrigo Casco y Pedro Iriso

--------------

DESCRIPCIÓN GENERAL Y FUNCIONALIDADES:

El juego comienza generando una secuencia aleatoria de luces. Cada color está asociado a un botón y a un sonido determinado. El jugador debe observar y escuchar la secuencia generada por Arduino y posteriormente repetirla utilizando los tres pulsadores.

Funcionamiento general:

- El sistema genera una secuencia aleatoria.

- Arduino enciende los LED siguiendo el orden de la secuencia.

- Cada LED se acompaña de un sonido emitido por el buzzer.

- El jugador debe repetir la secuencia presionando los botones correspondientes.

- Si la respuesta es correcta, el jugador supera la ronda.

- Al superar una ronda, se agrega una nueva parte a la secuencia.

- El juego cuenta con 4 niveles de dificultad, en los cuales aumenta la cantidad de elementos que el jugador debe recordar.

- El jugador dispone de un tiempo determinado para responder.

- Si se equivoca o supera el tiempo disponible, pierde la partida.

- Al perder, la pantalla muestra "GAME OVER" y el buzzer emite una señal sonora.

- El sistema permite comenzar una nueva partida.

--------------

INSTRUCCIONES DE USO Y EJECUCIÓN:

INICIO:

1- Conectar el Arduino y ejecutar el programa.

2- Encender la simulación o alimentar el circuito.

3- Seguir las indicaciones mostradas en la pantalla LCD.

4- Comenzar la partida.

DURANTE EL JUEGO:

1- Observar los LED mientras se reproduce la secuencia.

2- Memorizar el orden de los colores.

3- Esperar el turno del jugador.

4- Presionar los botones siguiendo el mismo orden.

5- Si la secuencia es correcta, avanza a una nueva secuencia.

6- Repetir el procedimiento hasta completar el nivel o perder.

CONDICIONES DE DERROTA:

La partida termina cuando:

- El jugador presiona un botón incorrecto.

- El jugador no responde dentro del tiempo establecido.

En ambos casos, el sistema muestra "GAME OVER" y reproduce una señal sonora mediante el buzzer.

DIFICULTAD: 

El juego posee cuatro niveles de dificultad. Cuanto mayor sea, aumenta la cantidad de elementos que debe memorizar y las secuencias que tiene que adivinar.

La dificultad se regula girando el potenciómetro de izquierda a derecha y viceversa.

--------------

REQUISITOS FUNCIONALES CUMPLIDOS:

El proyecto fue diseñado para cumplir con los requisitos mínimos establecidos para el trabajo práctico final.

CONTROL DE ENTRADAS Y SALIDAS: El sistema utiliza diferentes tipos de entradas y salidas.

- Entradas digitales: 3 pulsadores para recibir las acciones del jugador.

- Entradas analógicas: 1 potenciómetro para modificar la dificultad del juego.

- Salidas digitales: 3 LED para representar los diferentes elementos de la secuencia y 1 buzzer para reproducir sonidos.

- Salida mediante comunicación I2C: Pantalla LCD 16x2 para mostrar información al jugador.

CONTADOR DE FLANCOS: Los pulsadores permiten detectar cambios en el estado de las entradas digitales.

El programa identifica el cambio producido al presionar y soltar los botones, permitiendo registrar las acciones realizadas por el jugador.

Además, se utiliza un mecanismo de control para evitar que una misma pulsación sea interpretada varias veces debido al rebote físico del pulsador.

CONTROL LÓGICO POR TIEMPO:

El juego incorpora un control basado en temporizadores.

Cada vez que el sistema espera una respuesta del jugador, comienza a contar el tiempo utilizando la función millis() de Arduino.

Si el jugador presiona el botón correspondiente antes de que finalice el tiempo permitido, el juego continúa.

Si el tiempo se agota, la partida termina y se muestra el mensaje "GAME OVER".

CONTROL LÓGICO POR MAQUINA DE ESTADOS:

El funcionamiento del juego se divide en diferentes estados:

- Inicio.

- Generación de secuencia.

- Reproducción de secuencia.

- Espera de respuesta del jugador.

- Verificación de respuesta.

- Siguiente nivel.

- Game Over.

- Nueva partida.

El estado actual determina qué acción debe realizar el sistema y qué transición debe producirse según las acciones del jugador.

--------------

COMPONENTES UTILIZADOS:

Para construir el siguiente sistema se utilizaron los siguientes componentes:

| Componente | Cantidad | Función |
| :---: | :---: | :---: |
| Arduino Uno R3 | 1 | Control principal del sistema |
| Red LED | 1 | Representar un elemento de la secuencia |
| Yellow LED | 1 | Representar un elemento de la secuencia |
| Blue LED | 1 | Representar un elemento de la secuencia |
| Pushbutton | 3 | Permitir al jugador ingresar su respuesta |
| 1 kΩ Resistor | 3 | Limitar la corriente de los LED |
| Piezo | 1 | Reproducir sonidos |
| 250 kΩ Potentiometer | 1 | Modificar la dificultad |
| MCP23008-based, 32 (0x20) LCD 16 x 2 (I2C) | 1 | Mostrar información del juego |
| Breadboard Small | 1 | Realizar las conexiones |
| Cables jumper | Varios | Conectar los componentes |

--------------

ESQUEMA DEL CIRCUITO DEL JUEGO: 

La siguiente imagen muestra el circuito realizado en Tinkercad (plataforma web gratuita desarrollada por Autodesk, que permite simular circuitos electrónicos):

<img width="1494" height="812" alt="image" src="https://github.com/user-attachments/assets/cbef0cd8-7735-43f9-a1fa-293082281108" />

--------------

ESQUEMA ELÉCTRICO / DIAGRAMA DE CONEXIONES:

La siguiente imagen muestra el esquema eléctrico del juego, todos los componentes se encuentran conectados mediante una Breadboard Small al Arduino Uno R3:

<img width="1064" height="826" alt="image" src="https://github.com/user-attachments/assets/6bf00ba9-c220-4da5-85f1-bede9129c72f" />

--------------

LICENCIA Y CRÉDITOS:

El proyecto fue desarrollado como trabajo práctico final de la materia.

El concepto del juego está inspirado en el clásico juego de memoria Simón / Signos, adaptado para ser implementado mediante Arduino.

Se utilizaron herramientas como Arduino IDE, Visual Studio Code y Tinkercad Circuits para el desarrollo y simulación del sistema.

Este proyecto fue desarrollado con fines educativos y académicos.

El código y los esquemas pueden ser utilizados y modificados con fines educativos, manteniendo los créditos correspondientes a los integrantes del grupo.


