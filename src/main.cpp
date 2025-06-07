#include <ArduinoBlue.h>
#include <lineSensor.h>
#include <motorControl.h>
#include <SoftwareSerial.h>
#include <Arduino.h>
#include <string.h>
//#include <TInyGPS++.h>
//#include <gps.h>

const int Bluetooth_tx = 8;
const int Bluetooth_rx = 7;
bool isDriving = false;
//SoftwareSerial gpsSerial(RX,TX);
//TinyGPSPlus gps;

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
//	gpsSerial.begin(9600);
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
	String str = phone.getText();
	char buffer[30];
	str.toCharArray(buffer, sizeof(buffer));
	double latitude;
	double longitude;
	char* token = strtok(buffer, ",");
	if(token != NULL){
		latitude = atof(token);
	}
	token = strtok(NULL, ",");
	if(token != NULL){
		longitude = atof(token);
	}
	if(str != ""){
		Serial.println(latitude,6);
		Serial.println(longitude,6);
	}
	/*
	if(toPoint){

		while(gpsSerial.available() > 0) gps.encode(gpsSerial.read());

		if(gps.location.isValid()){
			
		}

	}
	*/
}
