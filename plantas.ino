#include <DHT.h>
#include <DHT_U.h>
#include <Wire.h>

#include <LiquidCrystal_I2C.h>


int sensorDht=2;
int temp, humedad;
int valorTierra1, valorTierra2;
int friendlyValue, friendlyValue2, friendlyValue3;
#define tierra1 A0
#define tierra2 A1


DHT dht(sensorDht, DHT11);
LiquidCrystal_I2C lcd(0x27, 20,4);

 // Crea un Objeto LC. Parametros: (rs, enable, d4, d5, d6, d7)
void setup() {   
  Serial.begin(9600);
  //inicialización de sensores
  dht.begin();
  Start();
}

void loop() { 
  ScreenTempMoist();
  Serial.print("Humedad suelo: ");
  Serial.println(friendlyValue);
  delay(2000);
 }
