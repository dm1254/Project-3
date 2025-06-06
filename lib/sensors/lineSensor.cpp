#include "lineSensor.h"
#include <Arduino.h>

const uint8_t leftSensor = 10;
const uint8_t rightSensor = 9;


void initSensorPins(){
	pinMode(leftSensor,INPUT);
	pinMode(rightSensor,INPUT);

}

int readLeftSensor(){
	int val = digitalRead(leftSensor);
	return val;
}
int readRightSensor(){
	int val = digitalRead(rightSensor);
	return val; 
}
