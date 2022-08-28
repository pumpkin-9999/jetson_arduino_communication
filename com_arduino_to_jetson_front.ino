#include <Arduino.h>

const int trigPin1 = D2;
const int echoPin1 = D3;
const int trigPin2 = D4;
const int echoPin2 = D5;
long duration1, distance1 = 0;
long duration2, distance2 = 0;


void setup() {
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  Serial.begin(9600);
}

long Distance(long time){
  long DistanceCalc;
  DistanceCalc = ((time * 0.034) / 2); // centimeters
  return DistanceCalc;
} 

void loop() {
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = Distance(duration1);

  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = Distance(duration2);

  Serial.print("Right Distance = "); 
  Serial.print(distance1); 
  Serial.println (" cm");

  Serial.print("Left Distance = "); 
  Serial.print(distance2); 
  Serial.println (" cm");

  // case
  if (Serial.available()){
    if (distance1 < distance2 && distance2 < 100) {
      if (distance1 > 70 && distance2 > 70) Serial.println("turn left 20 degrees");
      else if (distance1 > 50 && distance2 > 50) Serial.println("turn left 30 degrees");
      else if (distance1 > 30 & distance2 > 30) Serial.println("turn left 50 degrees");
      else Serial.println("go backwards");
    }
    else if (distance2 < distance1 && distance1 < 100) {
      if (distance1 > 70 && distance2 > 70) Serial.println("turn 20 right degrees");
      else if (distance1 > 50 && distance2 > 50) Serial.println("turn 30 right degrees");
      else if (distance1 > 30 & distance2 > 30) Serial.println("turn 50 right degrees");
      else Serial.println("go backwards");
    }
    else if (distance1 < 100) {
      if (distance1 > 70) Serial.println("turn left 10 degrees");
      else if (distance1 > 50) Serial.println("turn left 20 degrees");
      else if (distance1 > 30) Serial.println("turn left 30 degrees");
      else if (distance1 > 10) Serial.println("turn left 40 degrees");
      else Serial.println("go backwards");
    }
    else if (distance2 < 100) {
      if (distance2 > 70) Serial.println("turn right 10 degrees");
      else if (distance2 > 50) Serial.println("turn right 20 degrees");
      else if (distance2 > 30) Serial.println("turn right 30 degrees");
      else if (distance2 > 10) Serial.println("turn right 40 degrees");
      else Serial.println("go backwards");
    }
    
  }
  
  delay(1000); 

}
