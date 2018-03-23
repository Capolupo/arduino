// --- Biblioteca Sensor Temperatura umidade DHT ---
#include <DHT.h>


//COPIADO PARA FUNCIONAR O DISPLAY
#include <Arduino.h>
#include <U8x8lib.h>

//#ifdef U8X8_HAVE_HW_SPI
//#include <SPI.h>
//#endif

#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif
//COPIADO PARA FUNCIONAR O DISPLAY

// --- Definições Sensor Temperatura umidade DHT ---
#define DHTPIN D3
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

// --- Definições Display
U8X8_SH1106_128X64_NONAME_HW_I2C u8x8(/* reset=*/ U8X8_PIN_NONE);

 int umidade;
 int temperatura;
 
//--DISPLAY Adafruit, não utilizado neste projeto
//#include<Adafruit_SSD1306.h>
//#define OLED_RESET LED_BUILTIN 
//Adafruit_SSD1306 display(OLED_RESET);
 
//--SETUP
void setup() {
  Serial.begin(115200);  
  configurarDisplay();
  //pinMode(LED_BUILTIN, OUTPUT);     // Initialize the LED_BUILTIN pin as an output
}

//--LOOP
void loop() {
  medirTemperaturaUmidade();
  mostrarTemperaturaUmidade(); 

  //analogWrite(6, 100);
  
}



//*************************//
//*                        // 
//*---FUNÇÕES AUXILIARES---//
//*                        //
//*************************//

//--CONFIGURA O DISPLAY
void configurarDisplay(){
  //display.begin(SSD1306_SWITCHCAPVCC, 0x3C);// Refrencia arduino IC2 na web para fazer pesquisa desta porta
  //display.setTextColor(WHITE);
  //display.clearDisplay();  
  
  u8x8.begin();
  u8x8.setFont(u8x8_font_amstrad_cpc_extended_f);    
  u8x8.clear();

  //u8x8.inverse();
  //u8x8.print(" U8x8 Library ");
  //u8x8.setFont(u8x8_font_chroma48medium8_r);  
  //u8x8.noInverse();
  //u8x8.setCursor(0,1);  
  
}

// --MEDIÇÃO DE TEMPERATURA E UMIDADE
void medirTemperaturaUmidade() {
  umidade = dht.readHumidity();
  temperatura = dht.readTemperature(false);
    
  //digitalWrite(LED_BUILTIN, LOW);   // Turn the LED on (Note that LOW is the voltage level
  //delay(1000);   

  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.print("°C");
  Serial.print("   ");
  Serial.print("Umidade: ");
  Serial.println(umidade);

  //digitalWrite(LED_BUILTIN, HIGH);  // Turn the LED off by making the voltage HIGH
  
  delay(2000); 
}

void mostrarMensagemNoDisplay(const char* texto1, int medicao, const char* texto2) {
 /*
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.print(texto1);
  display.setTextSize(5);
  display.setCursor(20, 20);
  display.print(medicao);
  display.setTextSize(2);
  display.print(texto2);
  display.display();
  delay(2000);
  */

  //int i;
  u8x8.clearDisplay();
  u8x8.setCursor(0, 0);
  u8x8.print(texto1);
  u8x8.setCursor(0, 4);
  u8x8.draw2x2String(0, 5, "40");
  //u8x8.print(medicao);
  u8x8.print(texto2);
  u8x8.display();
  delay(5000);

//  for( i = 19; i > 0; i-- )
//  {
//    u8x8.setCursor(3,2);
//    u8x8.print(i);
//    u8x8.print("  ");
//    delay(200);
//  } 
}

void mostrarTemperaturaUmidade() {
  mostrarMensagemNoDisplay("Temperatura", (temperatura), " C");
  mostrarMensagemNoDisplay("Umidade", (umidade), " %");

}
