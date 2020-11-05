#include <DHT.h>
#include <DHT_U.h>
#include <Wire.h>

#include <LiquidCrystal_I2C.h>

//variables globales
int temp, humedad;
int friendlyValue, friendlyValue2, friendlyValue3;
int timer=0; //FALTA MODULO RTC

//sensor humedad y temperatura
#define sensorDht 2
//rele
#define relay 3
//botones
#define buttonDown 4
#define buttonUp 5
//sensores de tierra
#define tierra1 A0 
#define tierra2 A1
#define tierra3 A2
#define standByScreen 10


//variables globales de sensores
DHT dht(sensorDht, DHT11);
LiquidCrystal_I2C lcd(0x27, 20,4);

 // Crea un Objeto LC. Parametros: (rs, enable, d4, d5, d6, d7)
void setup() {   
  Serial.begin(9600);
  //inicialización de sensores
  dht.begin();
  pinMode(buttonDown, INPUT);
  pinMode(buttonUp, INPUT);
  pinMode(relay, OUTPUT);
  Start();
}

void loop() { 
  menuButton();
  timer=millis()/1000;
  delay(500);
 }
