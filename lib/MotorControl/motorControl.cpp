#include "motorControl.h"
#include <Arduino.h>
// Motor A
const uint8_t ENA = 11; 
const uint8_t IN1 = 12;
const uint8_t IN2 = 13;
//Motor B
const uint8_t ENB = 6;
const uint8_t IN3 = 5;
const uint8_t IN4 = 4;
void initMotorPins(){
	pinMode(ENA, OUTPUT);
	pinMode(ENB,OUTPUT);
	pinMode(IN1, OUTPUT);
	pinMode(IN2, OUTPUT);
	pinMode(IN3, OUTPUT);
	pinMode(IN4, OUTPUT);
}

void motorForward(){
  	digitalWrite(ENA, HIGH);
	digitalWrite(ENB, HIGH);
	digitalWrite(IN1,HIGH);
	digitalWrite(IN2,LOW);
	digitalWrite(IN3,HIGH);
	digitalWrite(IN4,LOW);	
}

void motorRight(){
  	digitalWrite(ENA, HIGH);
  	digitalWrite(ENB, HIGH);
	digitalWrite(IN1, LOW);
	digitalWrite(IN2, HIGH);
	digitalWrite(IN3, HIGH);
	digitalWrite(IN4, LOW);
}

void motorLeft(){
	digitalWrite(ENA, HIGH);
	digitalWrite(ENB, HIGH);
	digitalWrite(IN1, HIGH);
	digitalWrite(IN2, LOW);
	digitalWrite(IN3,LOW);
	digitalWrite(IN4,HIGH);

}

void stop(){
	digitalWrite(ENA, LOW);
	digitalWrite(ENB, LOW);
	digitalWrite(IN1, LOW);
	digitalWrite(IN2, LOW);
	digitalWrite(IN3,LOW);
	digitalWrite(IN4,LOW);

}
