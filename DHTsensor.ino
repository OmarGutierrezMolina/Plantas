//lectura sensor DHT

void readDHT(){
  humedad=dht.readHumidity();
  temp=dht.readTemperature();
}
