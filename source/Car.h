#pragma once
#include <string>
using namespace std;
 
class Car{
private:
	// attributes
	string vin;
	string make;
	string model;
	short year;
	double price;
	short numDoors;
	bool hatchback;
 
public:
	// constructors and destructor
	Car();
	Car(string vin, string make, string model, short year, double price,
           short numDoors, bool hatchback);
	~Car();
 
	// behaviors in the public section!
	string toString();
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
 
	short getNumDoors();
	void setNumDoors(short numDoors);
 
	bool getHatchback();
	void setHatchback(bool isHatchback);
};