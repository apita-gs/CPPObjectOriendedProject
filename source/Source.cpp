/*
--------------------------------
Developer: Allan Pita
Course: CIS247C
Program: Inheritance
Date: 06062020 (Week 5 Deliverable)
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
void saveToFile( ElectricCar* ptrElectricCar );
void saveToFile( GasCar* ptrGasCar );
void saveToFile( SUV* ptrSUV );
void saveToFile( Car* ptrCar );
void saveToFile( Vehicle* ptrVehicle );
 
int main()
{
	// create some Vehicle objects
	Vehicle veh1("V2345678901234567", "General Make", "General Model", 2000, 
		10000.0, Engine(4, 100));
	Car car1("X2345678901234567", "Toyota", "Supra", 2010, 8500.0, 
		2, false, Engine(8, 315));
	SUV suv1("S2345678901234567", "Infiniti", "G35", 2015, 15000.0, 
		8, 47.7f, Engine(6, 250));
	GasCar gas1("G2345678901234567", "Chevy", "Corvette", 2007, 
		16000.0, 2, false, 18, 19, Engine(8, 400));
	ElectricCar electric1("E2345678901234567", "Telsa", "Model 3", 
		2018, 35000.0, 4, false, 75, 240, 136, Engine(0, 271));
 
 
	// check the size
	cout << "Size of Car object: " << sizeof(car1) << endl;   // VERY LARGE
	cout << "Size of pointer to Car object: " << sizeof( &car1 ) << endl;	cout << endl;  // blank line
 
	// delete file if it exists
	remove("data.txt");
 
	// call the method to write your Car to the file
	saveToFile( &veh1 );   // notice the  &  which means "Address Of"
	saveToFile( &car1 );
	saveToFile( &suv1 );
	saveToFile( &gas1 );
	saveToFile( &electric1 );
 
	// pause
	cout << endl;
	system("pause");
 
	return 0;
}
 
void saveToFile(ElectricCar* ptrElectricCar)
{
	// open the pipe to the file
	ofstream outToFile("data.txt", ios::app);   // app means "Append"
 
	// if the file is open, write the data to the file
	if (outToFile.is_open())
	{
		// notice that we dereference the Car pointer using an arrow!
		outToFile << ptrElectricCar->getVin() << ',' << ptrElectricCar->getMake() << ','
			<< ptrElectricCar->getModel() << ',' << ptrElectricCar->getYear() << ','
			<< ptrElectricCar->getPrice() << ',' << ptrElectricCar->getNumDoors() << ','
			<< ptrElectricCar->getHatchback() << ','
			<< ptrElectricCar->getBatterySize() << ','
			<< ptrElectricCar->getRange() << ','
			<< ptrElectricCar->getMpgE() << ','
			<< ptrElectricCar->getMotor().getNumCylinders() << ','    // Notice the composition!
			<< ptrElectricCar->getMotor().getHorsePower() << endl;
 
		// close the pipe
		outToFile.close();
 
		// tell user that the data was written
		cout << ptrElectricCar->getMake() << " " << ptrElectricCar->getModel() << " was written to the file!" << endl;
	}
}
 
void saveToFile(GasCar* ptrGasCar)
{
	// open the pipe to the file
	ofstream outToFile("data.txt", ios::app);   // app means "Append"
 
												// if the file is open, write the data to the file
	if (outToFile.is_open())
	{
		// notice that we dereference the Car pointer using an arrow!
		outToFile << ptrGasCar->getVin() << ',' << ptrGasCar->getMake() << ','
			<< ptrGasCar->getModel() << ',' << ptrGasCar->getYear() << ','
			<< ptrGasCar->getPrice() << ',' << ptrGasCar->getNumDoors() << ','
			<< ptrGasCar->getHatchback() << ','
			<< ptrGasCar->getTankSize() << ','
			<< ptrGasCar->getMPG() << ','
			<< ptrGasCar->getMotor().getNumCylinders() << ','    // Notice the composition!
			<< ptrGasCar->getMotor().getHorsePower() << endl;
 
		// close the pipe
		outToFile.close();
 
		// tell user that the data was written
		cout << ptrGasCar->getMake() << " " << ptrGasCar->getModel() << " was written to the file!" << endl;
	}
}
void saveToFile(SUV* ptrSUV)
{
	// open the pipe to the file
	ofstream outToFile("data.txt", ios::app);   // app means "Append"
 
												// if the file is open, write the data to the file
	if (outToFile.is_open())
	{
		// notice that we dereference the Car pointer using an arrow!
		outToFile << ptrSUV->getVin() << ',' << ptrSUV->getMake() << ','
			<< ptrSUV->getModel() << ',' << ptrSUV->getYear() << ','
			<< ptrSUV->getPrice() << ',' << ptrSUV->getNumSeats() << ','
			<< ptrSUV->getCargoSize() << ','
			<< ptrSUV->getMotor().getNumCylinders() << ','    // Notice the composition!
			<< ptrSUV->getMotor().getHorsePower() << endl;
 
		// close the pipe
		outToFile.close();
 
		// tell user that the data was written
		cout << ptrSUV->getMake() << " " << ptrSUV->getModel() << " was written to the file!" << endl;
	}
}
 
void saveToFile(Car* ptrCar)
{
	// open the pipe to the file
	ofstream outToFile("data.txt", ios::app);   // app means "Append"
 
												// if the file is open, write the data to the file
	if (outToFile.is_open())
	{
		// notice that we dereference the Car pointer using an arrow!
		outToFile << ptrCar->getVin() << ',' << ptrCar->getMake() << ','
			<< ptrCar->getModel() << ',' << ptrCar->getYear() << ','
			<< ptrCar->getPrice() << ',' << ptrCar->getNumDoors() << ','
			<< ptrCar->getHatchback() << ','
			<< ptrCar->getMotor().getNumCylinders() << ','    // Notice the composition!
			<< ptrCar->getMotor().getHorsePower() << endl;
 
		// close the pipe
		outToFile.close();
 
		// tell user that the data was written
		cout << ptrCar->getMake() << " " << ptrCar->getModel() << " was written to the file!" << endl;
	}
}
void saveToFile(Vehicle* ptrVehicle)
{
	// open the pipe to the file
	ofstream outToFile("data.txt", ios::app);   // app means "Append"
 
												// if the file is open, write the data to the file
	if (outToFile.is_open())
	{
		// notice that we dereference the Car pointer using an arrow!
		outToFile << ptrVehicle->getVin() << ',' << ptrVehicle->getMake() << ','
			<< ptrVehicle->getModel() << ',' << ptrVehicle->getYear() << ','
			<< ptrVehicle->getPrice() << ',' 
			<< ptrVehicle->getMotor().getNumCylinders() << ','    // Notice the composition!
			<< ptrVehicle->getMotor().getHorsePower() << endl;
 
		// close the pipe
		outToFile.close();
 
		// tell user that the data was written
		cout << ptrVehicle->getMake() << " " << ptrVehicle->getModel() << " was written to the file!" << endl;
	}
}