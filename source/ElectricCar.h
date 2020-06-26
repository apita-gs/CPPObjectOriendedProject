#pragma once
 
#include "Car.h"
 
class ElectricCar : public Car{
private:
	// attributes
	float batterySize;
	short range;
	short mpgE;
 
public:
	// constructors and destructor
	ElectricCar();
	ElectricCar(string vin, string make, string model, short year, double price, 
		short numDoors, bool hatchback, float batterySize, short range, 
		short mpgE, Engine motor);	
	
	virtual ~ElectricCar();
 
	// behaviors
	string toString();
 
	// getters and setters
	float getBatterySize();
	void setBatterySize(float batterySize);
 
	short getRange();
	void setRange(short range);
 
	short getMpgE();
	void setMpgE(short mpgE);
};
