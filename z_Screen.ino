//LCD MENU LOGIC

const int numOfScreens = 3; //hora, temperatura, suelo
const int numOfInputs = 4; //numero de botones
const int inputPins[numOfInputs] = {4,5,6,7}; //pines de botones
int lastInputState[numOfInputs] = {LOW,LOW,LOW,LOW};
int currentScreen = 0;
int menuvalue = 0;

//SETEO DE MENUES

String screens[numOfScreens][4]={{"-----------------","BIENVENIDO","HORA: ", "-----------------"},
                                  {"---AMBIENTE---","Temperatura: ", "Humedad: ", "-----------------"},
                                  {"---SUELO---","Tierra 1: ","Tierra 2: ", "Tierra 3: "}};





void menu(int menuvalue){
  switch(menuvalue){
    case 0:
      ScreenTime();
    case 1:
      ScreenTempMoist();
    case 2:
      ScreenGround();
  }
}



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
  lcd.print(" ");
  lcd.print(friendlyValue3);
}

void ScreenTime(){
  lcd.clear();
  readTierra();
  lcd.setCursor(0,0);
  lcd.print("---- BIENVENIDO -----");
  lcd.setCursor(7,1);
  lcd.print("HORA");
  lcd.setCursor(0,3);
  lcd.print("--------------------");
}
