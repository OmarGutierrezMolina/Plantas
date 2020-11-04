//variables

int dryValue = 1023;
int wetValue = 0;
int friendlyDryValue = 0;
int friendlyWetValue = 100;
int friendlyValue, friendlyValue2;

void readTierra(){
  int rawValue = analogRead(tierra1);
  int rawValue2 = analogRead(tierra2);
  friendlyValue = map(rawValue, dryValue, wetValue, friendlyDryValue, friendlyWetValue);
  friendlyValue2 = map(rawValue2, dryValue, wetValue, friendlyDryValue, friendlyWetValue);
}
