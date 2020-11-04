#include <DHT.h>
#include <DHT_U.h>

#include <Wire.h>

#include <LiquidCrystal_I2C.h>

int sensorDht=2;
int temp, humedad;
int valorTierra1 = 0;
#define tierra1 A0


DHT dht(sensorDht, DHT11);

LiquidCrystal_I2C lcd(0x27, 20,4); // Crea un Objeto LC. Parametros: (rs, enable, d4, d5, d6, d7)
void setup() {   
  Serial.begin(9600);
  //inicialización de sensores
  dht.begin();
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("------------------");
  lcd.setCursor(1,1);
  lcd.print("Iniciando sensores");
  lcd.setCursor(1,2);
  lcd.print("Porfavor, espere");
  lcd.setCursor(1,3);
  lcd.print("------------------");
  delay(3000);
  lcd.clear();
}
void loop() { 
  
  
  humedad=dht.readHumidity();
  temp=dht.readTemperature();
  valorTierra1 = analogRead(tierra1);
  lcd.setCursor(1,0);
  lcd.print("------------------");
  lcd.setCursor(1,1);
  lcd.print("Temperatura: ");
  lcd.print(temp);
  lcd.print(" ");
  lcd.print((char)223);
  lcd.print("C");
  lcd.setCursor(1,2);
  lcd.print("Humedad: ");
  lcd.print(humedad);
  lcd.print(" %");
  lcd.setCursor(0,3);
  lcd.print("Humedad tierra: ");
  lcd.print(valorTierra1);
  
  Serial.print("Humedad suelo: ");
  Serial.println(valorTierra1);
  delay(2000);
  
  

  
  
  
  
  
  
 }
