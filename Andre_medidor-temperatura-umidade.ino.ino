#include <DHT.h>

#define DHTPIN D3
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
}

void loop() {
  int umidade = dht.readHumidity();
  int temperatura = dht.readTemperature(false);
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.print("°C");
  Serial.print("   ");
  Serial.print("Umidade: ");
  Serial.println(umidade);
  delay(5000);
}
