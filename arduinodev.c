#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <stdio.h>
#include <string.h>
#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd(0);

int dificultad;
int cant;//cantidad de luces q se encienden
int tiempo;//cuanto tiempo quedan prendidas
int secuencias;//cuantas secuencias tiene cada dificultad para ganar el nivel
int pausa;//pausa entre cada luz q se enciende
long valor;
int dificultadAnterior=0;

enum estado{MOSTRAR_SECUENCIA, ESPERAR, GANASTE, PERDISTE};
//mostrar prende las luces, esperar espera al usuario
estado estadojuego = MOSTRAR_SECUENCIA;//el juego empieza en ese estado

int secuencia[12];//para crear la secuencia de colores
int pasoActual=0;//en que paso de secuencia esta el usuario
int rondaActual=0;//cuantas rondas gano el usuario  

void dificultades(int nivel){
  switch (nivel){
    case 1:
    cant=3;
    tiempo=1200;
    secuencias=6;
    pausa=400;
    break;
    
    case 2:
    cant=6;
    tiempo=1000;
    secuencias=10;
    pausa=400;
    break;
    
    case 3:
    cant=9;
    tiempo=500;
    secuencias=14;
    pausa=250;
    break;
    
    case 4:
    cant=12;
    tiempo=500;
    secuencias=20;
    pausa=250;
    break;
  }
}

#define ROJO 2
#define AMARILLO 3
#define AZUL 4
#define BOTONR 5
#define BOTONAM 6
#define BOTONAZ 7

const int leds[] = {ROJO, AMARILLO, AZUL};
const int botones[] = {BOTONR, BOTONAM, BOTONAZ};
const int CANTIDAD = 3;

int lecturaAnterior[] = {HIGH, HIGH, HIGH};
int estadoEstable[] = {HIGH, HIGH, HIGH};
unsigned long millisBoton[] = {0, 0, 0};

int estadoLed[] = {LOW, LOW, LOW};

// Inicializar pantalla
void initLCD() {

  lcd.begin(16, 2);

  lcd.setBacklight(1);

  delay(50);
}

// Limpiar pantalla
void lcd_clear() {
  lcd.clear();
}
// Volver al inicio
void lcd_home() {
  lcd.setCursor(0, 0);
}
// Posicionar cursor
void lcd_setCursor(int col, int row) {
  lcd.setCursor(col, row);
}
// Imprimir texto
void lcd_print(const char* texto) {
  lcd.print(texto);
}

void setup()
{
  /*Serial.begin(9600);
  Serial.println("elije dificultad");*/
int i;

    for (i = 0; i < CANTIDAD; i++) {
        pinMode(leds[i], OUTPUT);
        pinMode(botones[i], INPUT_PULLUP);
    }
    Serial.begin(9600);
	
  // Inicializar pantalla
  initLCD();

  lcd_clear();

  lcd_setCursor(0, 0);
  lcd_print("SIMON 3 COLORES");

  lcd_setCursor(0, 1);
  lcd_print("PANTALLA LISTA");
  
}

void loop()
{
  int i;

    for (i = 0; i < CANTIDAD; i++) {

        int estadoBoton = digitalRead(botones[i]);

        if (estadoBoton != lecturaAnterior[i]) {

            millisBoton[i] = millis();
        }


        if (millis() - millisBoton[i] > 10) {

            if (estadoBoton != estadoEstable[i]) {

                estadoEstable[i] = estadoBoton;

                if (estadoEstable[i] == LOW) {

                    digitalWrite(leds[i], HIGH);

                    Serial.print("Boton ");
                    Serial.print(i);
                    Serial.println(" presionado");
                }

                else {

                    digitalWrite(leds[i], LOW);
                }
            }
        }

        lecturaAnterior[i] = estadoBoton;
    }
  
  valor=analogRead(A0);
  
  if (valor>= 0 && valor<=255){
    dificultad=1;
  }
  
  if (valor>255 && valor<=511){
    dificultad=2;
  }
  
  if (valor>511 && valor<=767){
    dificultad=3;
  }
  
  if (valor>767 && valor<=1023){
    dificultad=4;
  }
  
  if(dificultad!=dificultadAnterior){
  	dificultadAnterior=dificultad;
    dificultades(dificultad);
    rondaActual=0;
    estadojuego=MOSTRAR_SECUENCIA;
  }
  
  void mostrarEstadoJuego() {
  static int estadoAnterior = -1;
  if (estadoAnterior != estadojuego) {
    lcd_clear();}
  }  
  
  switch (estadojuego){
  	case MOSTRAR_SECUENCIA:    
     lcd_setCursor(0, 0);
     lcd_print("SIMON 3 COLORES");
     lcd_setCursor(0, 1);
     lcd_print("OBSERVA LA SERIE");
    
    for (int t=0 ; t<cant; t++){
    secuencia[t]= random(0,3);
    }
    
    for (int j=0; j<cant ; j++){
    	int ledA_encender = secuencia[j];
      	digitalWrite(leds[ledA_encender], HIGH);
      	delay(tiempo);
      	digitalWrite(leds[ledA_encender], LOW);
      	delay(pausa);
    }
    estadojuego= ESPERAR;
  break;
    
    case ESPERAR:
     lcd_setCursor(0, 0);
     lcd_print("TU TURNO");
     lcd_setCursor(0, 1);
     lcd_print("REPITE LA SERIE");
    
    for (int i = 0; i < CANTIDAD; i++) {
    int estadoBoton = digitalRead(botones[i]);
    if (estadoBoton != lecturaAnterior[i]) {
      millisBoton[i] = millis();
    }
    if (millis() - millisBoton[i] > 10) {
      if (estadoBoton != estadoEstable[i]) {
        estadoEstable[i] = estadoBoton;
        if (estadoEstable[i] == LOW) {
         digitalWrite(leds[i], HIGH);
		 delay(200); 
		 digitalWrite(leds[i], LOW);
          if(i==secuencia[pasoActual]){
            pasoActual++; if(pasoActual>=cant){
            estadojuego=GANASTE;
            }
          }   else{
          		estadojuego=PERDISTE;
          }  
        }
      }
    }
    lecturaAnterior[i] = estadoBoton;
  }
   break;
    
    case GANASTE:
     lcd_setCursor(0, 0);
     lcd_print("FELICITACIONES");
     lcd_setCursor(0, 1);
     lcd_print("NIVEL COMPLETADO");
   break;
    
    case PERDISTE:
      lcd_setCursor(0, 0);
      lcd_print("GAME OVER");
      lcd_setCursor(0, 1);
      lcd_print("INTENTA OTRA VEZ");
   break; 
  }
}