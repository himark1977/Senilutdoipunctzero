#include <Arduino.h>
#define GPSRxPin 2
#define GPXTxPin 3
#define in1Pin 7
#define in2Pin 6
#define in3Pin 5
#define in4Pin 4

// Proxy sensor front left
#define FS_Sensortrig 10
#define FS_SensorEcho 11
//Proxy sensor front left
#define F_Sensortrig 12
#define F_SensorEcho 13
// Proxy sensor front right
#define FD_Sensortrig 14
#define FD_SensorEcho 15

int distanceFL;
int distanceF;
int distanceFR;
bool obstacleFL = false;
bool obstacleF= false;
bool obstacleFR= false;

void setup() {
  Serial.begin(9600);
  // Motor 1
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  // Motor 2
  pinMode(in3Pin, OUTPUT);
  pinMode(in4Pin, OUTPUT);
  // GPS Sensor
  pinMode(GPXTxPin, INPUT);
  pinMode(GPSRxPin, INPUT);
  // Proxy sensor front left
  pinMode(FS_Sensortrig, OUTPUT);
  pinMode(FS_SensorEcho, INPUT);
  // Proxy sensor front
  pinMode(F_Sensortrig, OUTPUT);
  pinMode(F_SensorEcho, INPUT);
  // Proxy sensor front right
  pinMode(FD_Sensortrig, OUTPUT);
  pinMode(FD_SensorEcho, INPUT);
  // Initializate motor
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(in3Pin, OUTPUT);
  pinMode(in4Pin, OUTPUT);
}

void loop() {

  // Proxy F
  // Start a new measurement:
  digitalWrite(F_Sensortrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(F_Sensortrig, LOW);
  // Read the result:
 distanceF = pulseIn(F_SensorEcho, HIGH) / 58;
  delay(1000);
  if(distanceF< 20) {
      Serial.println("Obstacle detected on front");
      delay(1000);
      obstacleF=true;
  }


//ProxyFront
  // Start a new measurement:
  digitalWrite(F_Sensortrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(F_Sensortrig, LOW);
  // Read the result:
 distanceFL = pulseIn(F_SensorEcho, HIGH) / 58;
  delay(1000);
  if(distanceFL < 20) {
      Serial.println("Obstacle detected on the left");
      delay(1000);
      obstacleFL=true;
  }


//ProxyFrontR
  // Start a new measurement:
  digitalWrite(F_Sensortrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(F_Sensortrig, LOW);
  // Read the result:
 distanceFR = pulseIn(F_SensorEcho, HIGH) / 58;
  delay(1000);
  if(distanceFR < 20) {
      Serial.println("Obstacle detected on the right");
      delay(1000);
      obstacleFR=true;
  }


//AutoDrive
    // TO DO
  if(obstacleF == true){
    if(distanceFL<distanceFR){
      Serial.print("Going Right");
    } else{
      Serial.print("Going Left");
    }
  } 

  if(obstacleFL == true){
    if(distanceF<distanceFR){
      Serial.print("Going Right");
    } else {
      Serial.print("Going Straight");
      digitalWrite(in1Pin, HIGH);
      digitalWrite(in3Pin, HIGH);
    } 
  }

  if(obstacleFR == true){
    if(distanceF<distanceFL){
      Serial.print("Going Left");
    } else {
      Serial.print("Going Straight");
      digitalWrite(in1Pin, HIGH);
      digitalWrite(in3Pin, HIGH);
    } 
  }


}