#ifndef GPS_H
#define GPS_H

const uint8_t RX = 2;
const uint8_t TX = 3;

void readGPSData();
void calculateBearing(double latitude, double longitude);
