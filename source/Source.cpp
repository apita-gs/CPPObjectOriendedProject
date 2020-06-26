/*
--------------------------------
Developer: Allan Pita
Course: CIS247C
Program: Polymorphism
Date: 06142020 (Week 6 Deliverable)
--------------------------------
*/
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "Vehicle.h"
#include "Car.h"
#include "SUV.h"
#include "GasCar.h"
#include "ElectricCar.h"
using namespace std;
 
// Functions Prototypes (not using polymorphism yet. Will update to reflect)
void saveToFile( Vehicle* ptrVehicle );
string determineChildType(Vehicle* ptrVehicle);
 
/// Entry point for the application
int main()
{
	// create some Vehicle objects
	const int NUM_CARS = 4;
	Vehicle* vehicles[NUM_CARS];
	vehicles[0] = new Car("X2345678901234567", "Ford", "Mustang", 2010, 8500.0,
		2, false, Engine(8, 315));
	vehicles[1] = new SUV("S2345678901234567", "Honda", "Pilot", 2015, 15000.0,
		8, 47.7f, Engine(6, 250));
	vehicles[2] = new GasCar("G2345678901234567", "Chevy", "Corvette", 2007,
		16000.0, 2, false, 18, 19, Engine(8, 400));
	vehicles[3] = new ElectricCar("E2345678901234567", "Telsa", "Model 3",
		2018, 35000.0, 4, false, 75, 240, 136, Engine(0, 271));
 
	// check the size
	cout << "Size of Vehicle pointer: " 
		<< sizeof(vehicles[0]) << endl;  // MUCH smaller!
	cout << "Size of Vehicle object (dereferenced): " 
		<< sizeof( *vehicles[0] ) << endl;
	cout << endl;  // blank line
 
 
	// delete file if it exists
	remove("data.txt");
 
	// call the method to write your Car to the file
	for (int i = 0; i < NUM_CARS; i++)
	{
		saveToFile(vehicles[i]);  // using positions in the pointer array
	}
 
	// clean our heap memory!
	for	(int i = 0; i < NUM_CARS; i++)
	{
		delete vehicles[i];
	}
 
	// pause
	cout << endl;
	system("pause");
 
	return 0;
}

string determineChildType(Vehicle * ptrVehicle)
{
	ElectricCar* e1 = dynamic_cast<ElectricCar*>(ptrVehicle);
	if (e1 != nullptr)
		return "ElectricCar";
 
	GasCar* g1 = dynamic_cast<GasCar*>(ptrVehicle);
	if (g1 != nullptr)
		return "GasCar";
 
	Car* c1 = dynamic_cast<Car*>(ptrVehicle);
	if (c1 != nullptr)
		return "Car";
 
	SUV* s1 = dynamic_cast<SUV*>(ptrVehicle);
	if (s1 != nullptr)
		return "SUV";
 
	return "Error";
}

void saveToFile(Vehicle* ptrVehicle)
{
	// open the pipe to the file
	ofstream outToFile("data.txt", ios::app);   // app means "Append"
 
	// determine the child type and write the child data
	string childType = determineChildType(ptrVehicle);
 
	// if the file is open, write the data to the file
	if (outToFile.is_open())
	{
		// write the child type AND STAY ON THE SAME OUTPUT LINE
		outToFile << childType << ',';
 
		// ON THE SAME LINE, write parent information using the parent refence
		outToFile << ptrVehicle->getVin() << ',' << ptrVehicle->getMake() << ','
			<< ptrVehicle->getModel() << ',' << ptrVehicle->getYear() << ','
			<< ptrVehicle->getPrice() << ',' 
			<< ptrVehicle->getMotor().getNumCylinders() << ','
			<< ptrVehicle->getMotor().getHorsePower();
 
		// dynamic cast to get child object and write child info ON SAME LINE
		if (childType == "SUV")
		{
			SUV* s1 = dynamic_cast<SUV*>(ptrVehicle);
			outToFile << ',' << s1->getNumSeats() 
				<< ',' << s1->getCargoSize();
		}
 
		if (childType == "Car")
		{
			// write info if Car or child of Car (GasCar or ElectricCar)
			Car* c1 = dynamic_cast<Car*>(ptrVehicle);
			outToFile << ',' << c1->getNumDoors() 
				<< ',' << c1->getHatchback();
		}
 
		if (childType == "ElectricCar")
		{
			ElectricCar* e1 = dynamic_cast<ElectricCar*>(ptrVehicle);
			outToFile << ',' << e1->getBatterySize() << ','
				<< e1->getRange() << ',' << e1->getMpgE();
		}
 
		else if (childType == "GasCar")
		{
			GasCar* g1 = dynamic_cast<GasCar*>(ptrVehicle);
			outToFile << ',' << g1->getTankSize() << ',' << g1->getMPG();
		}
 
		// drop down to next line in file so we are ready for the next record
		outToFile << endl;
 
		// close the pipe
		outToFile.close();
 
		// tell user that the data was written
		cout << ptrVehicle->getMake() << " " << ptrVehicle->getModel() 
			<< " was written to the file!" << endl;
	}
}