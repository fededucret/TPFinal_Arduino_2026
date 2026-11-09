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

COMPONENTES UTILIZADOS:

Para construir el siguiente sistema se utilizaron los siguientes componentes:

| Componente | Cantidad | Función |
| :--- | :---: | ---: |
| Arduino Uno | 1 | Control principal del sistema |
| LED rojo | 1 | Representar un elemento de la secuencia |
| LED verde | 1 | Representar un elemento de la secuencia |
| LED azul | 1 | Representar un elemento de la secuencia |
| Pulsadores | 3 | Permitir al jugador ingresar su respuesta |
| Resistencias | 3 | Limitar la corriente de los LED |
| Buzzer | 1 | Reproducir sonidos |
| Potenciómetro | 1 | Modificar la dificultad |
| LCD 16x2 | 1 | Mostrar información del juego |
| Protoboard | 1 | Realizar las conexiones |
| Cables jumper | Varios | Conectar los componentes |

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

IMÁGEN DEL PROYECTO: 

La siguiente imagen muestra el circuito realizado en Tinkercad (plataforma web gratuita desarrollada por Autodesk, que permite simular circuitos electrónicos):

<img width="1542" height="788" alt="image" src="https://github.com/user-attachments/assets/30d14a88-315f-42fd-99f5-c2be70c8ed8d" />

--------------

LICENCIA Y CRÉDITOS:

El proyecto fue desarrollado como trabajo práctico final de la materia.

El concepto del juego está inspirado en el clásico juego de memoria Simón / Signos, adaptado para ser implementado mediante Arduino.

Se utilizaron herramientas como Arduino IDE, Visual Studio Code y Tinkercad Circuits para el desarrollo y simulación del sistema.

Este proyecto fue desarrollado con fines educativos y académicos.

El código y los esquemas pueden ser utilizados y modificados con fines educativos, manteniendo los créditos correspondientes a los integrantes del grupo.


