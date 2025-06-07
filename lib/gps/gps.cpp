#include "Arduino.h"
#include <SoftwareSerial.h>
#include "TinyGPS++.h"

SoftwareSerial gpsSerial(RX,TX);
TinyGPSPlus gps;

void readGPSData(){
	while(gpsSerial.available() > 0) gps.encode(gpsSerial.read());

	if(gps.location.isValid()){
		
	}

}


