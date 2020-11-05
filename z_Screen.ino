//LCD MENU LOGIC


int menuvalue = 0;

//SETEO DE MENUES

//String screens[numOfScreens][4]={{"-----------------","BIENVENIDO","HORA: ", "-----------------"},
//                                  {"---AMBIENTE---","Temperatura: ", "Humedad: ", "-----------------"},
//                                  {"---SUELO---","Tierra 1: ","Tierra 2: ", "Tierra 3: "}};

//navegación con botones
void menuButton(){
  //checkIfStandBy();
  menu(menuvalue);
  if(digitalRead(buttonDown)==HIGH){
    menuvalue--;
    menu(menuvalue);
    if (menuvalue<0){
      menuvalue=3;
      menu(menuvalue);
    }
  }
  else if(digitalRead(buttonUp)==HIGH){
    menuvalue++;
    menu(menuvalue);
    if (menuvalue>=3){
      menuvalue=0;
      menu(menuvalue);
    }
  }
}

//menu de navegación
void menu(int menuvalue){
  switch(menuvalue){
    case 0:
      ScreenTime();
      break;
    case 1:
      ScreenTempMoist();
      break;
    case 2:
      ScreenGround();
      break;
  }
}

//FALTA MODULO RTC
void  checkIfStandBy(){
  if((timer-standByScreen>0)){
    lcd.noBacklight();
    if(buttonDown==HIGH || buttonUp==HIGH){
      timer=0;
      lcd.backlight();
    }
  }
}

//pantalla de inicialización
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

//pantalla con sensor de humedad y temperatura
void ScreenTempMoist(){
  lcd.clear();
  readDHT();
  readTierra();
  lcd.setCursor(0,0);
  lcd.print("----TEMPERATURA---");
  lcd.setCursor(0,1);
  lcd.print("Temperatura: ");
  lcd.print(temp);
  lcd.print(" ");
  lcd.print((char)223);
  lcd.print("C");
  lcd.setCursor(0,2);
  lcd.print("Humedad: ");
  lcd.print(humedad);
  lcd.print(" %");
  lcd.setCursor(0,3);
  
  
}

//pantalla con sensores de tierra
void ScreenGround(){
  lcd.clear();
  readTierra();
  lcd.setCursor(0,0);
  lcd.print("---- Suelos -----");
  lcd.setCursor(0,1);
  lcd.print("Tierra 1: ");
  lcd.print(friendlyValue);
  lcd.setCursor(0,2);
  lcd.print("Tierra 2: ");
  lcd.print(friendlyValue2);
  lcd.setCursor(0,3);
  lcd.print("Tierra 3: ");
  lcd.print(friendlyValue3);
}

//Pantalla inicial, tiempo y riego
void ScreenTime(){
  lcd.clear();
  readTierra();
  lcd.setCursor(0,0);
  lcd.print("---- BIENVENIDO ----");
  lcd.setCursor(7,1);
  lcd.print("HORA");
  lcd.setCursor(1,2);
  lcd.print("Riego ");
  lcd.print(irrigation);
  lcd.setCursor(0,3);
  lcd.print("--------------------");
}
