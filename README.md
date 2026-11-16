🎮 Juego Simón Mudo - Juego electrónico de memoria 

--------------

Nuestro proyecto "Juego Simón Mudo" consiste en desarrollar un juego electrónico de memoria y reflejos inspirado en el clásico juego Simón Dice / Signos. 

El sistema está basado en un Arduino Uno y utiliza tres luces LED de diferentes colores, tres pulsadores, un buzzer, un potenciómetro y una pantalla LCD de 16x2.

El objetivo del juego es que el jugador observe y memorice una secuencia de luces generada por el sistema y luego la repita utilizando los botones correspondientes.

El juego cuenta con cuatro niveles de dificultad, que se seleccionan mediante el potenciómetro. Cada nivel modifica la cantidad de elementos de la secuencia, la cantidad de rondas que se deben superar y la velocidad con la que se reproduce la secuencia.

--------------

INTEGRANTES DEL GRUPO:

- Alejandro Jesús Aloe — Correo: alejandroaloe24@gmail.com

- Nicolas Botto — Correo: nicolasbotto412@gmail.com

- Federico Ducret — Correo: fedeericoducret123@gmail.com
  
- Marcos Quispe — Correo: Canazajuan554@gmail.com

--------------

MATERIA Y DOCENTES:

- Laboratorio en Computación 1 / Turno Noche

- Rodrigo Casco y Pedro Iriso

--------------

DESCRIPCIÓN GENERAL Y FUNCIONALIDADES:

Al comenzar una partida, Arduino genera una secuencia de colores de forma aleatoria. Cada color está asociado a un LED, un botón y un sonido determinado.

Primero, el sistema muestra la secuencia mediante los LEDs y el buzzer. Después, el jugador debe repetirla presionando los botones correspondientes en el mismo orden.

El funcionamiento general es:

- El sistema genera una secuencia aleatoria de colores.

- Arduino reproduce la secuencia utilizando los tres LEDs.

- Cada LED se acompaña con un sonido diferente mediante el buzzer.

- La pantalla LCD informa al jugador en qué etapa del juego se encuentra.

- El jugador debe repetir la secuencia utilizando los tres pulsadores.

- Cada pulsación es detectada por Arduino y comparada con la secuencia original.

- Si el jugador presiona el color correcto, puede continuar con el siguiente elemento.

- Si presiona un color incorrecto, pierde la partida.

- El jugador también tiene un tiempo máximo para responder.

- Si se supera ese tiempo, la partida termina.

- Si completa correctamente todas las rondas correspondientes al nivel seleccionado, el juego muestra un mensaje de victoria.

- Al finalizar la partida, el programa vuelve a comenzar una nueva partida.

A diferencia del Simón Dice clásico, en este proyecto la secuencia no se va haciendo más larga en cada ronda. La cantidad de elementos de la secuencia depende del nivel de dificultad seleccionado y cada ronda genera una nueva secuencia aleatoria.

--------------

INSTRUCCIONES DE USO Y EJECUCIÓN:

INICIO

- Conectar el Arduino y ejecutar el programa.

- Encender la simulación o alimentar el circuito.

- Seleccionar el nivel de dificultad girando el potenciómetro.

- Observar la información mostrada en la pantalla LCD.

- El juego comienza automáticamente.

DURANTE EL JUEGO

- Observar los LEDs mientras Arduino reproduce la secuencia.

- Escuchar los sonidos correspondientes a cada color.

- Memorizar el orden de la secuencia.

- Esperar a que comience el turno del jugador.

- Presionar los botones siguiendo el mismo orden de colores.

- Después de cada respuesta correcta, el tiempo disponible vuelve a comenzar.

- Si se completa correctamente la secuencia, se pasa a la siguiente ronda.

- Repetir el procedimiento hasta completar todas las rondas del nivel o perder.

CONDICIONES DE DERROTA

La partida termina cuando ocurre alguna de estas situaciones:

- El jugador presiona un botón correspondiente a un color incorrecto.

- El jugador supera el tiempo máximo disponible para responder.

En ambos casos, el sistema muestra “GAME OVER” en la pantalla LCD y reproduce una señal sonora mediante el buzzer.

DIFICULTAD

El juego posee cuatro niveles de dificultad, seleccionados mediante el potenciómetro.

Cada nivel modifica diferentes parámetros del juego:

| Nivel | Cantidad de elementos | Rondas | Tiempo de reproducción |
|:-----:|----------------------:|-------:|-----------------------:|
|   1   |                     3 |      6 |                1200 ms |
|   2   |                     6 |     10 |                1000 ms |
|   3   |                     9 |     14 |                 500 ms |
|   4   |                    12 |     20 |                 500 ms |

Además, los niveles superiores utilizan pausas más cortas entre los elementos de la secuencia, haciendo que resulte más difícil memorizarla.

El jugador puede cambiar el nivel girando el potenciómetro conectado a la entrada analógica A0. Arduino lee el valor del potenciómetro y lo divide en cuatro rangos para seleccionar el nivel correspondiente.

El tiempo máximo que el jugador tiene para responder durante su turno es de 5 segundos. Este tiempo se reinicia después de cada respuesta correcta.

--------------

REQUISITOS FUNCIONALES CUMPLIDOS:

El proyecto fue diseñado teniendo en cuenta los requisitos mínimos establecidos para el trabajo práctico final.

CONTROL DE ENTRADAS Y SALIDAS

El sistema utiliza diferentes tipos de entradas y salidas:

- Entradas digitales: 3 pulsadores para recibir las acciones del jugador.

- Entrada analógica: 1 potenciómetro conectado a A0 para seleccionar la dificultad.

- Salidas digitales: 3 LEDs para representar los diferentes colores de la secuencia.

- Salida sonora: 1 buzzer Piezo para reproducir los sonidos correspondientes a los colores y los sonidos de victoria o derrota.

- Comunicación I2C: una pantalla LCD 16x2 para mostrar información durante la partida.

De esta manera, el proyecto utiliza tanto entradas digitales como analógicas y diferentes tipos de salidas.

CONTADOR DE FLANCOS

Los tres pulsadores se utilizan para detectar cambios en las entradas digitales.

El programa no toma simplemente el estado instantáneo del botón, sino que detecta el cambio estable producido al realizar una pulsación. Cuando se detecta una transición de HIGH a LOW, correspondiente a la pulsación de un botón utilizando INPUT_PULLUP, se incrementa el contador de flancos.

El contador se almacena en la variable contadorFlancos y también se muestra en la pantalla LCD durante el turno del jugador.

Además, se utiliza un sistema de antirrebote mediante millis() para evitar que una única pulsación física sea interpretada como varias pulsaciones debido al rebote mecánico del botón.

CONTROL LÓGICO POR TIEMPO

El juego incorpora diferentes controles relacionados con el tiempo.

Para controlar el tiempo disponible para el jugador se utiliza la función millis() de Arduino. Cuando comienza el turno, se guarda el momento inicial en la variable inicioRespuesta.

Mientras el jugador está respondiendo, el programa calcula cuánto tiempo transcurrió desde el comienzo del turno.

Si transcurren 5 segundos sin una respuesta válida, se considera que el tiempo se agotó y la partida termina.

Además, después de que el jugador presiona correctamente un botón, el tiempo de respuesta vuelve a comenzar. De esta forma, el jugador dispone de un máximo de 5 segundos para realizar cada respuesta.

También se utilizan tiempos para controlar la duración de las luces y sonidos y las pausas entre los elementos de la secuencia.

--------------

MÁQUINA DE ESTADOS: 

El funcionamiento del juego puede representarse mediante el siguiente diagrama:

<img width="588" height="392" alt="image" src="https://github.com/user-attachments/assets/b3fc0e17-f95f-45da-903f-16d3823289c8" />

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

<img width="1184" height="759" alt="image" src="https://github.com/user-attachments/assets/51291da9-fb80-4659-a97f-4ef9fda6a666" />

Link del Tinkercad: https://www.tinkercad.com/things/87EELZXJIM5/editel?returnTo=%2Fdashboard&sharecode=2oPyUwejo4CUnHw1OMQuLJx6o0VlGKgVyMwxbaFSY9U

--------------

ESQUEMA ELÉCTRICO / DIAGRAMA DE CONEXIONES:

La siguiente imagen muestra el esquema eléctrico del juego, todos los componentes se encuentran conectados mediante una Breadboard Small al Arduino Uno R3:

<img width="1062" height="826" alt="image" src="https://github.com/user-attachments/assets/681dc644-5345-45a3-8145-5daa643c7db4" />

--------------

LICENCIA Y CRÉDITOS:

El proyecto fue desarrollado como trabajo práctico final de la materia.

El concepto del juego está inspirado en el clásico juego de memoria Simón Dice / Signos, pero fue adaptado y modificado para este proyecto bajo el nombre “Simón Mudo”.

Para el desarrollo, programación y simulación se utilizaron herramientas como Visual Studio Code, Arduino y Tinkercad Circuits.

El proyecto fue desarrollado con fines educativos y académicos.

El código y los esquemas pueden ser utilizados y modificados con fines educativos, manteniendo los créditos correspondientes a los integrantes del grupo.


