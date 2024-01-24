#include "ESP.h"

#define LED_1   D1
#define LED_2   D2
#define LED_3   D3
#define LED_4   D7
#define BUTTON  D5
#define POT A0

#define TEMPO_LONGO 3000
#define TEMPO_CURTO 100


int buttonState = 0;
int potValue = 0;
int pwmValue = 0;
int previousValue = -1; // Valor anterior digitado
long tempoInicial;
long tempoFinal;

int tempo_inicial = -1;

void setup()
{
  // Declarações
  Serial.begin(9600);
  pinMode(LED_1, OUTPUT);
  digitalWrite(LED_1, LOW);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  pinMode(LED_4, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);
  pinMode(POT, INPUT);
  ESP.wdtDisable();
  ESP.wdtEnable(2000);
  attachInterrupt(digitalPinToInterrupt(BUTTON), Ligaled, CHANGE);
}

void loop(){
  byte valor = digitalRead(BUTTON);
  potValue = analogRead(POT);
  pwmValue = map(potValue, 0, 1023, 0, 255);
  analogWrite(LED_2, pwmValue);

// verificando se há valores disponíveis na serial
  if (Serial.available() > 0) {
    // lendo valor enviado pela serial
    int val = Serial.parseInt();
    // verificando se o valor está dentro do intervalo válido (0-255)
    if (val >= 0 && val <= 255) {
      // enviando valor para o LED3
      analogWrite(LED_3, val);

    } else {
      // informando valor inválido
      Serial.println("Valor fora do intervalo permitido (0-255)");
    }
  }
}   


ICACHE_RAM_ATTR void Ligaled() {
 
  if(tempo_inicial == -1  && buttonState == HIGH){
    tempo_inicial = millis();
  }

  int tempo_final = millis();

  if(digitalRead(BUTTON) == LOW) {
    digitalWrite(LED_1, HIGH);

    tempo_final = millis();

    if ((tempo_final - tempo_inicial) >= TEMPO_LONGO){
      Serial.println("Restartando");
      digitalWrite(LED_4, HIGH);
      delay(250);
      digitalWrite(LED_4, LOW);
      ESP.restart();
    }
  }else{
    tempo_inicial = -1;
    digitalWrite(LED_1, LOW);
  }
}

