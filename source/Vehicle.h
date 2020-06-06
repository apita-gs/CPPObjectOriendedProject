#pragma once
 
#include <string>
#include "Engine.h"
using namespace std;
 
class Vehicle{
private:
	// attributes
	string vin;
	string make;
	string model;
	short year;
	double price;
	Engine motor;
 
public:
	// constructors and destructor
	Vehicle();
	Vehicle(string vin, string make, string model, short year, 
		double price, Engine motor);
	virtual ~Vehicle();
 
	// behaviors in the public section!
	virtual string toString();
	double discountPrice(float discountPercent);
 
	// accessors and mutators
	string getVin();
	void setVin(string vin);
 
	string getMake();
	void setMake(string make);
 
	string getModel();
	void setModel(string model);
 
	short getYear();
	void setYear(short year);
 
	double getPrice();
	void setPrice(double price);
 
	Engine getMotor();
	void setMotor(Engine motor);
};