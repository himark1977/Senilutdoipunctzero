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
  ProxyFata();
  
}

bool Motor(bool high){
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(in3Pin, OUTPUT);
  pinMode(in4Pin, OUTPUT);
  if(high){
    digitalWrite(in1Pin, HIGH);
    digitalWrite(in2Pin, LOW);
    digitalWrite(in3Pin, HIGH);
    digitalWrite(in4Pin, LOW);
  }
  else{
    digitalWrite(in1Pin, LOW);
    digitalWrite(in2Pin, HIGH);
    digitalWrite(in3Pin, LOW);
    digitalWrite(in4Pin, HIGH);
  }
  return high;
}

void ProxyFata(){
  // Start a new measurement:
  digitalWrite(F_Senzortrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(F_Senzortrig, LOW);
  // Read the result:
  int duration = pulseIn(F_SenzorEcho, HIGH) / 58;
  delay(1000);

  if(duration > 10){
    Serial.print("Senzor fata stanga: ");
    Serial.print(duration);
    Serial.println(" cm");
    Motor(true);
  }
}