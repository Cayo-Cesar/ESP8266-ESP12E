//Código Sensor

#include <SoftwareSerial.h>

#define SENSOR 5 

SoftwareSerial mySerial(1, 3); // RX, TX

void setup()
{
  // Open serial communications and wait for port to open:
  Serial.begin(115200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Native USB only
  }

  pinMode(SENSOR, INPUT);

  // set the data rate for the SoftwareSerial port
  mySerial.begin(38400);
}

void loop() // run over and over
{
  int sensorValue = digitalRead(SENSOR); 
  mySerial.write(sensorValue);
}

