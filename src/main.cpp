#include <Arduino.h>
#define in1Pin 7
#define in2Pin 6
#define in3Pin 5
#define in4Pin 4

// Proxy sensor front left
#define FL_Sensortrig 10
#define FL_SensorEcho 11
//Proxy sensor front
#define F_Sensortrig 12
#define F_SensorEcho 13
// Proxy sensor front right
#define FR_Sensortrig 9
#define FR_SensorEcho 8

int distanceFL;
int distanceF;
int distanceFR;
bool obstacle;


void proxy() {
  //ProxyFront
  // Start a new measurement:
  digitalWrite(F_Sensortrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(F_Sensortrig, LOW);
  // Read the result:
 distanceF = pulseIn(F_SensorEcho, HIGH) / 58;
  delayMicroseconds(10);
  if(distanceF < 30) {
    Serial.println(" obstacle detected ");
      delay(1);
      obstacle=true;
  } else {
    obstacle = false;
     digitalWrite(in1Pin, HIGH);
    digitalWrite(in3Pin, HIGH);
  }


  // Start a new measurement:
  digitalWrite(FL_Sensortrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(FL_Sensortrig, LOW);
  // Read the result:
 distanceFL = pulseIn(FL_SensorEcho, HIGH) / 58;
  delayMicroseconds(10);

  // Start a new measurement:
  digitalWrite(FR_Sensortrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(FR_Sensortrig, LOW);
  // Read the result:
 distanceFR = pulseIn(FR_SensorEcho, HIGH) / 58;
  delayMicroseconds(10);
}

void autodrive() {
  //AutoDrive
    // TO DO
  if(obstacle == true){
    if(distanceFL<distanceFR){
      Serial.print("Going Right");
      digitalWrite(in1Pin, HIGH);
      digitalWrite(in3Pin, LOW);
  delayMicroseconds(10);
    } else{
      Serial.print("Going Left");
      digitalWrite(in1Pin, LOW);
      digitalWrite(in3Pin, HIGH);
  delayMicroseconds(10);
    }
  } 
}

void setup() {
  Serial.begin(9600);
  // Motor 1
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  // Motor 2
  pinMode(in3Pin, OUTPUT);
  pinMode(in4Pin, OUTPUT);

  // Proxy sensor front
  pinMode(F_Sensortrig, OUTPUT);
  pinMode(F_SensorEcho, INPUT);
   // Proxy sensor front
  pinMode(FL_Sensortrig, OUTPUT);
  pinMode(FL_SensorEcho, INPUT);
   // Proxy sensor front
  pinMode(FR_Sensortrig, OUTPUT);
  pinMode(FR_SensorEcho, INPUT);
 
}

void loop() {
proxy();
autodrive();
}