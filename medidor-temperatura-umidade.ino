#include <ACROBOTIC_SSD1306.h>

// --- DHT ---
#include <DHT.h>
#define DHTPIN D3
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);
int umidade;
int temperatura;

// --- DISPLAY ---

#include <Adafruit_SSD1306.h>
#define OLED_RESET LED_BUILTIN

#define BUZZER D6

void setup() {
  pinMode(BUZZER, OUTPUT);
  Wire.begin();  
  oled.init();                      // Initialze SSD1306 OLED display
}

void loop() {
  medirTemperaturaUmidade();
  mostrarTemperaturaUmidade();
}

void medirTemperaturaUmidade() {
  umidade = dht.readHumidity();
  temperatura = dht.readTemperature(false);
  delay(2000);
}

void mostrarTemperaturaUmidade() {
  mostrarMensagemNoDisplay("Temperatura", (temperatura), " C");
  if(temperatura > 28){
    tone(BUZZER, 100);  
  }
  mostrarMensagemNoDisplay("Umidade", (umidade), " %");
}

void mostrarMensagemNoDisplay(const char* texto1, int medicao, const char* texto2) {
  oled.clearDisplay();              // Clear screen
  oled.setTextXY(0,3);              // Set cursor position, start of line 0
  oled.putString(texto1);
  oled.setTextXY(1,0);              // Set cursor position, start of line 2
  oled.putString(texto2);
  oled.setTextXY(1,2);
  oled.putString(String(medicao));
  delay(1000);
}

