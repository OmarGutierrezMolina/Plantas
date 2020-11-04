
void Start(){
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

void ScreenTempMoist(){
  readDHT();
  readTierra();
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
  lcd.print("Tierra: ");
  lcd.print(friendlyValue);
  lcd.print(" ");
  //lcd.print(friendlyValue2);
}
