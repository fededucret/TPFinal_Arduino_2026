#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

#define ROJO 2
#define AMARILLO 3
#define AZUL 4

#define BOTONR 5
#define BOTONAM 6
#define BOTONAZ 7

#define BUZZER 10

#define NUM_LED 3

const int leds[] = {ROJO, AMARILLO, AZUL};
const int botones[] = {BOTONR, BOTONAM, BOTONAZ};

const int tonos[] = {
  262,
  330,
  392
};

const int potPin = A0;

//variables de las dificultades

int dificultad = 1;

int cant;
int tiempo;
int secuencias;
int pausa;

int dificultadAnterior = 0;

long valor;

//variables secuencia
int secuencia[12];
int pasoActual = 0;
int rondaActual = 0;

//tiempo max y antirrebote
const unsigned long TIEMPO_MAX = 5000;
const unsigned long ANTIRREBOTE = 30;
unsigned long inicioRespuesta = 0;
unsigned long contadorFlancos = 0;
bool tiempoAgotado = false;

// Variables para detectar flancos
int lecturaAnterior[NUM_LED] = {HIGH, HIGH, HIGH};
int estadoEstable[NUM_LED] = {HIGH, HIGH, HIGH};
unsigned long millisBoton[NUM_LED] = {0, 0, 0};

//configuracion dificultades
void dificultades(int nivel) {
  switch (nivel) {
    case 1:
      cant = 3;
      tiempo = 1200;
      secuencias = 6;
      pausa = 400;
      break;

    case 2:
      cant = 6;
      tiempo = 1000;
      secuencias = 10;
      pausa = 400;
      break;

    case 3:
      cant = 9;
      tiempo = 500;
      secuencias = 14;
      pausa = 250;
      break;

    case 4:
      cant = 12;
      tiempo = 500;
      secuencias = 20;
      pausa = 250;
      break;
  }
}

//funciones pantalla lcd
void initLCD() {

  lcd.init();

  lcd.backlight();

  delay(50);
}

void lcd_clear() {
  lcd.clear();
}

void lcd_setCursor(int col, int row) {
  lcd.setCursor(col, row);
}

void lcd_print(const char* texto) {
  lcd.print(texto);
}

//mensajes
void mostrarBienvenida() {

  lcd_clear();

  lcd_setCursor(0, 0);
  lcd_print("SIMON MUDO");

  lcd_setCursor(0, 1);
  lcd_print("Bienvenido!");

  delay(2000);

}

void mostrarDificultad() {

  lcd_clear();

  lcd_setCursor(0, 0);
  lcd_print("Dificultad:");

  lcd_setCursor(0, 1);

  switch (dificultad) {

    case 1:
      lcd_print("Nivel 1: Noob");
      break;

    case 2:
      lcd_print("Nivel 2: Std");
      break;

    case 3:
      lcd_print("Nivel 3: Hard");
      break;

    case 4:
      lcd_print("Nivel 4: Insane");
      break;
  }

  delay(1000);
}

void mostrarMemorizacion() {

  lcd_clear();

  lcd_setCursor(0, 0);
  lcd_print("OBSERVA LA SERIE");

  lcd_setCursor(0, 1);
  lcd_print("Nivel: ");
  lcd.print(dificultad);

}

void mostrarTurno() {

  lcd_clear();

  lcd_setCursor(0, 0);
  lcd_print("TU TURNO");

  lcd_setCursor(0, 1);
  lcd_print("REPITE LA SERIE");

}

void mostrarGameOver() {

  lcd_clear();

  lcd_setCursor(0, 0);
  lcd_print("GAME OVER!");

  lcd_setCursor(0, 1);

  if (tiempoAgotado) {
    lcd_print("Tiempo agotado");
  }
  else {
    lcd_print("Error de color");
  }

  tone(BUZZER, 100, 1000);

  delay(1200);

  noTone(BUZZER);

  delay(1500);

}

void mostrarVictoria() {

  lcd_clear();

  lcd_setCursor(0, 0);
  lcd_print("FELICIDADES!");

  lcd_setCursor(0, 1);
  lcd_print("NIVEL COMPLETO");

  tone(BUZZER, 523, 200);
  delay(250);

  tone(BUZZER, 659, 200);
  delay(250);

  tone(BUZZER, 784, 500);
  delay(600);

  noTone(BUZZER);

  delay(2000);

}

//funciones led y buzzer
void apagarLuces() {

  for (int i = 0; i < NUM_LED; i++) {
    digitalWrite(leds[i], LOW);
  }

}

void sonidoColor(int color, int duracion) {

  tone(BUZZER, tonos[color]);

  digitalWrite(leds[color], HIGH);

  delay(duracion);

  digitalWrite(leds[color], LOW);

  noTone(BUZZER);

}

//botones
int detectarBoton() {

  for (int i = 0; i < NUM_LED; i++) {

    int estadoBoton = digitalRead(botones[i]);

    // Detectar cambio de estado
    if (estadoBoton != lecturaAnterior[i]) {

      millisBoton[i] = millis();

      lecturaAnterior[i] = estadoBoton;
    }

    // Comprobar antirrebote
    if (millis() - millisBoton[i] >= ANTIRREBOTE) {

      if (estadoBoton != estadoEstable[i]) {

        estadoEstable[i] = estadoBoton;

        // INPUT_PULLUP:
        // HIGH -> LOW significa pulsacion

        if (estadoEstable[i] == LOW) {

          contadorFlancos++;

          Serial.print("Flancos detectados: ");
          Serial.println(contadorFlancos);

          return i;
        }
      }
    }
  }

  return -1;
}

//funcion para mostrar la secuencia de colores
void mostrarSecuencia() {

  mostrarMemorizacion();

  delay(1000);

  for (int i = 0; i < cant; i++) {

    int color = secuencia[i];

    sonidoColor(color, tiempo);

    delay(pausa);
  }

  delay(300);

}

//turno usuario 
bool turnoJugador() {

  mostrarTurno();

  pasoActual = 0;

  inicioRespuesta = millis();

  while (pasoActual < cant) {

    // Calcular tiempo transcurrido
    unsigned long transcurrido = millis() - inicioRespuesta;

    // Comprobar tiempo maximo
    if (transcurrido >= TIEMPO_MAX) {

      tiempoAgotado = true;

      return false;
    }

    // Mostrar tiempo y contador en pantalla
    int segundosRestantes =
      (TIEMPO_MAX - transcurrido + 999) / 1000;

    lcd_setCursor(0, 1);

    lcd.print("T:");
    lcd.print(segundosRestantes);
    lcd.print("s F:");
    lcd.print(contadorFlancos);
    lcd.print("    ");

    // Detectar pulsacion
    int respuesta = detectarBoton();

    if (respuesta != -1) {

      sonidoColor(respuesta, 150);

      // Comprobar si el color es correcto
      if (respuesta != secuencia[pasoActual]) {

        return false;
      }

      pasoActual++;

      // Reiniciar tiempo para el siguiente boton
      inicioRespuesta = millis();

    }

    delay(5);
  }

  return true;
}

//funcion juego principal
void jugar() {

  pasoActual = 0;

  bool correcto = true;

  tiempoAgotado = false;

  contadorFlancos = 0;

  rondaActual = 0;

  // Jugar hasta completar la cantidad de secuencias
  while (rondaActual < secuencias && correcto) {

    // Generar nueva secuencia
    for (int i = 0; i < cant; i++) {

      secuencia[i] = random(0, NUM_LED);

    }

    // Mostrar secuencia
    mostrarSecuencia();

    // Esperar respuesta
    correcto = turnoJugador();

    // Si se equivoca o se acaba el tiempo
    if (!correcto) {

      mostrarGameOver();

      return;
    }

    // Si responde correctamente
    rondaActual++;

    lcd_clear();

    lcd_setCursor(0, 0);
    lcd_print("CORRECTO!");

    lcd_setCursor(0, 1);
    lcd.print("Ronda ");
    lcd.print(rondaActual);
    lcd.print("/");
    lcd.print(secuencias);

    delay(1000);

  }

  if (correcto) {

    mostrarVictoria();

  }

}

void setup() {

  Serial.begin(9600);

  // Configurar LEDs y botones
  for (int i = 0; i < NUM_LED; i++) {

    pinMode(leds[i], OUTPUT);

    pinMode(botones[i], INPUT_PULLUP);

    digitalWrite(leds[i], LOW);

    lecturaAnterior[i] = HIGH;

    estadoEstable[i] = HIGH;

    millisBoton[i] = millis();

  }

  pinMode(BUZZER, OUTPUT);

  // Inicializar LCD para Tinkercad
  initLCD();

  // Inicializar aleatoriedad
  randomSeed(analogRead(A1));

  // Inicializar dificultad
  dificultad = 1;

  dificultades(dificultad);

  // Mensaje de bienvenida
  mostrarBienvenida();

}

void loop() {

  // Leer potenciometro
  valor = analogRead(potPin);

  int nuevaDificultad;

  if (valor <= 255) {
    nuevaDificultad = 1;
  }
  else if (valor <= 511) {
    nuevaDificultad = 2;
  }
  else if (valor <= 767) {
    nuevaDificultad = 3;
  }
  else {
    nuevaDificultad = 4;
  }

  // Detectar cambio de dificultad
  if (nuevaDificultad != dificultadAnterior) {

    dificultad = nuevaDificultad;

    dificultadAnterior = nuevaDificultad;

    dificultades(dificultad);

    mostrarDificultad();

    Serial.print("Potenciometro: ");
    Serial.println(valor);

    Serial.print("Dificultad: ");
    Serial.println(dificultad);

  }

  // Ejecutar juego
  jugar();

}
