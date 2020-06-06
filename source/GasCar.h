#pragma once
 
#include "Car.h"
 
class GasCar : public Car{
private:
	// attributes
	float tankSize;
	short mpg;
 
public:
	// constructors and destructor
	GasCar();
	GasCar(string vin, string make, string model, short year, double price, 
		short numDoors, bool hatchback, float tankSize, short mpg, 
		Engine motor);
	virtual ~GasCar();
 
	// behaviors
	string toString();
 
	// getters and setters
	float getTankSize();
	void setTankSize(float tankSize);
 
	short getMPG();
	void setMPG(short mpg);
};
