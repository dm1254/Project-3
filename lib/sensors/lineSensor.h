#ifndef SENSOR_H
#define SENSOR_H

//Sensor pins definitions
//Accelerometer pin definitions
//const uint8_t xAxis = A0;
//const uint8_t yAxis = A1;
//MPU 6050 using I2C
//const uint8_t scl = A5;
//cont uint8_t sda = A4;

void initSensorPins();
int readLeftSensor();
int readRightSensor();

#endif
