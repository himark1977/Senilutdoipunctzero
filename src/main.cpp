#include <Arduino.h>
#include <header.h>
#define GPSRxPin 2
#define GPXTxPin 3
#define in1Pin 7
#define in2Pin 6
#define in3Pin 5
#define in4Pin 4

// Senzor proximitate fata stanga
#define FS_Senzortrig 10
#define FS_SenzorEcho 11
//Senzor proximitate fata
#define F_Senzortrig 12
#define F_SenzorEcho 13
//Senzor proximitate dreapta
#define FD_Senzortrig 14
#define FD_SenzorEcho 15

void setup() {
  Serial.begin(9600);
  // Motor 1
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  // Motor 2
  pinMode(in3Pin, OUTPUT);
  pinMode(in4Pin, OUTPUT);
  // Senzor JPS
  pinMode(GPXTxPin, INPUT);
  pinMode(GPSRxPin, INPUT);
  // Senzor proximitate fata stanga
  pinMode(FS_Senzortrig, OUTPUT);
  pinMode(FS_SenzorEcho, INPUT);
  // Senzor proximitate fata
  pinMode(F_Senzortrig, OUTPUT);
  pinMode(F_SenzorEcho, INPUT);
  // Senzor proximitate dreapta
  pinMode(FD_Senzortrig, OUTPUT);
  pinMode(FD_SenzorEcho, INPUT);
}

void loop() {
  ProxyFataStanga();
  
}


void ProxyFataStanga(){
  // Start a new measurement:
  digitalWrite(FS_Senzortrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(FS_Senzortrig, LOW);
  // Read the result:
  int duration = pulseIn(FS_SenzorEcho, HIGH) / 58;
  delay(1000);

  if(duration <= 10){
    Serial.print("Senzor fata stanga: ");
    Serial.print(duration);
  }
}