// Define as informações do template do projeto no Blynk
#define BLYNK_TEMPLATE_ID "TMPL2lf7fNhOG"
#define BLYNK_TEMPLATE_NAME "SE"


// Inclui as bibliotecas necessárias
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>


// Configuração das credenciais WiFi e token de autenticação
char auth[] = "x4_6CS8MvjAxR0cJvijl0qC57FdYiJyf";
char ssid[] = "CAYO";
char pass[] = "41140751";


// Define os pinos dos LEDs
#define LED_PIN 13  // Pino para o primeiro LED
#define LED_PIN1 15  // Pino para o segundo LED


// Função de configuração
void setup() {
  Serial.begin(115200);  // Inicia a comunicação serial
  Blynk.begin(auth, ssid, pass);  // Inicia a comunicação com o servidor Blynk
  pinMode(LED_PIN, OUTPUT);  // Configura o pino do primeiro LED como saída
  pinMode(LED_PIN1, OUTPUT);  // Configura o pino do segundo LED como saída
}


// Função de loop
void loop() {
  Blynk.run();  // Executa as operações necessárias do Blynk
}


// Função chamada quando o botão virtual V0 é pressionado ou solto
BLYNK_WRITE(V0) {
  int ledState = param.asInt();  // Obtém o valor do botão virtual
  
  if (ledState == 1) {
    digitalWrite(LED_PIN, HIGH);  // Liga o LED do primeiro pino
  } else {
    digitalWrite(LED_PIN, LOW);  // Desliga o LED do primeiro pino
  }
}


// Função chamada quando o slider virtual V1 é movido
BLYNK_WRITE(V1) { 
  int sliderValue = param.asInt();  // Obtém o valor do slider virtual
  analogWrite(LED_PIN1, sliderValue);  // Define a intensidade do LED do segundo pino com base no valor do slider
}
