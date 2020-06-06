#pragma once
#include "Vehicle.h"
 
class SUV : public Vehicle{
private:
	// attributes
	short numSeats;
	float cargoSize;
 
public:
	// constructors and destructor
	SUV();
	SUV(string vin, string make, string model, short year, double price,
		short numSeats, float cargoSize, Engine motor);
	virtual ~SUV();
 
	// behaviors
	string toString();
 
	// getters and setters
	short getNumSeats();
	void setNumSeats(short numSeats);
 
	float getCargoSize();
	void setCargoSize(float cargoSize);
};