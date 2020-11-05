//lectura sensores de tierra
//variables

int dryValue = 1023;
int wetValue = 0;
int friendlyDryValue = 0;
int friendlyWetValue = 100;
int minMoist = 30;
int maxMoist = 60;

String irrigation = "Inactivo"; 

//leer valores de sensores, transformación a variables amigables
void readTierra(){
  int rawValue = analogRead(tierra1);
  int rawValue2 = analogRead(tierra2);
  int rawValue3 = analogRead(tierra3);
  friendlyValue = map(rawValue, dryValue, wetValue, friendlyDryValue, friendlyWetValue);
  friendlyValue2 = map(rawValue2, dryValue, wetValue, friendlyDryValue, friendlyWetValue);
  friendlyValue3 = map(rawValue3, dryValue, wetValue, friendlyDryValue, friendlyWetValue);
  checkMoist();
}

//cambio de actividad de riego
void checkMoist(){
  if((friendlyValue<=minMoist)||(friendlyValue2<=minMoist)||(friendlyValue3<=minMoist)){
    irrigation="Activo";
    digitalWrite(relay,HIGH);
  }
  else if((friendlyValue>=maxMoist)||(friendlyValue2>=maxMoist)||(friendlyValue3>=maxMoist)){
    irrigation = "Inactivo"; 
    digitalWrite(relay,LOW);
  }
  
}
