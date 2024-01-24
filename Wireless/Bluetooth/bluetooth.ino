#include <SoftwareSerial.h> //INCLUSÃO DE BIBLIOTECA
 
const int pinoRX = 13; //PINO DIGITAL 13 (RX) (D8)
const int pinoTX = 15; //PINO DIGITAL 15 (TX) (D7)
const int pinoLed = 12; //PINO DIGITAL UTILIZADO PELO LED
const int sensor = 4; //PINO DIGITAL USADO PELO SENSOR
int dadoBluetooth = 0; //VARIÁVEL QUE ARMAZENA O VALOR ENVIADO PELO BLUETOOTH
boolean loopLED = false; //VARIÁVEL BOOLEANA QUE FAZ O CONTROLE DE ATIVAÇÃO DO LOOP DO LED
 
bool detected = false;


SoftwareSerial bluetooth(pinoRX, pinoTX); //PINOS QUE EMULAM A SERIAL, ONDE O PINO 13 É O RX E O PINO 15 É O TX
 
void setup(){
  Serial.begin(9600); //INICIALIZA A SERIAL
  bluetooth.begin(9600); //INICIALIZA A SERIAL DO BLUETOOTH
  bluetooth.print("$"); //IMPRIME O CARACTERE
  delay(100); //INTERVALO DE 100 MILISSEGUNDOS
  pinMode(pinoLed, OUTPUT); //DEFINE O PINO COMO SAÍDA
  pinMode(sensor, INPUT);
}
 
void loop(){
   if(bluetooth.available()){ //SE O BLUETOOTH ESTIVER HABILITADO, FAZ
      int received = bluetooth.parseInt();
      bluetooth.readString();
      analogWrite(pinoLed, received); //LIGA O LED
  }


  if(!digitalRead(sensor)){
    if(!detected){
      bluetooth.write("SENSOR ATIVADO\n");
      detected = true;
    }
  }else{
     if(detected){
      bluetooth.write("PRESENÇA NÃO DETECTADA\n");
      detected = false;
    }
  }
 }
