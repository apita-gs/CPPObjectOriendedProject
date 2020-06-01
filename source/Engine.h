#pragma once
 
#include <string>
using namespace std;
 
class Engine
{
private:
	// attributes
	short numCylinders;
	short horsePower;
 
public:
	// constructors
	Engine();
	Engine(short numCylinders, short horsePower);
	~Engine();
 
	// behaviors
	string toString();
 
	// accessors and mutators
	short getNumCylinders();
	void setNumCylinders(short numCylinders);
 
	short getHorsePower();
	void setHorsePower(short horsePower);
};