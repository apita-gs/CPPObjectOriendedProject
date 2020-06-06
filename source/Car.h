#pragma once
 
#include <string>
#include "Vehicle.h"
using namespace std;
 
class Car : public Vehicle
{
private:
	// attributes
	short numDoors;
	bool hatchback;
 
public:
	// constructors and destructor
	Car();
	Car(string vin, string make, string model, short year, double price, 
             short numDoors, bool hatchback, Engine motor);
	~Car();
 
	// behaviors in the public section!
	string toString();
 
	// getters and setters
	short getNumDoors();
	void setNumDoors(short numDoors);
 
	bool getHatchback();
	void setHatchback(bool isHatchback);
};