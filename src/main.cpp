#include <ArduinoBlue.h>
#include <lineSensor.h>
#include <motorControl.h>
#include <SoftwareSerial.h>
#include <Arduino.h>

const int Bluetooth_tx = 8;
const int Bluetooth_rx = 7;
bool isDriving = false;
SoftwareSerial bluetooth(Bluetooth_tx, Bluetooth_rx);
ArduinoBlue phone(bluetooth);


void drive(){
	int Rval = readRightSensor();
	int Lval = readLeftSensor();
	Serial.print("Right sensor:");
	Serial.println(Rval);
	Serial.print("Left sensor:");
	Serial.println(Lval);
	if(Rval == 0 && Lval == 0){
		motorForward();
	}
	else if(Rval == 1 && Lval ==0){
		motorRight();
	}
	else if(Rval == 0 && Lval == 1){
		motorLeft();
	}
	else{
		stop();

	}
}
void setup(){
	Serial.begin(9600);
	bluetooth.begin(9600);
	initMotorPins();
	initSensorPins();
}

void loop(){
	int button  = phone.getButton();
	if(button != -1){
		Serial.println(button);
		if(button == 0){
			isDriving = true;

		}else if(button == 1){
			isDriving = false;
		}
	}
	if(isDriving){
		drive(); 
	}else{
		stop();
	}

}
