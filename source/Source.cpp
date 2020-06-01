/*
--------------------------------
Developer: Allan Pita
Course: CIS247C
Program: Adding Composition
Date: 05302020 (Week 4 Deliverable)
--------------------------------
*/
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "Car.h"
using namespace std;
 
// Functions Prototypes
void saveToFile( Car* ptrCar );
 
int main()
{
	// create two Car objects -- use default and parameterized constructors
	Car firstCar;

	Engine motor(8, 315);
	Car secondCar("X2345678901234567", "Toyota", "Supra", 2020, 60000, 2, false, motor);
// check the size
	cout << "Comparing size between String Object and Pointer" << endl;
	cout << "Size of Car object: " << sizeof(firstCar) << endl;
	cout << "Size of pointer to Car object: " << sizeof( &firstCar ) << endl;  // MUCH smaller!
	cout << endl;  // blank line
 
	// deletes file if it exists
	remove("data.txt");
 
	// call the method to write your Car to the file
	cout << "File Operation Information: " << endl;
	saveToFile( &firstCar );   // notice the  &  which means "Address Of"
	saveToFile( &secondCar );
 
	// pause
	cout << endl;
	system("pause");
 
	return 0;
}
 
void saveToFile(Car* ptrCar)
{
  // open the pipe to the file
  ofstream outToFile("data.txt", ios::app);   // app means "Append"
 
  // if the file is open, write the data to the file
  if (outToFile.is_open())
  {
    // notice that we dereference the Car pointer using an arrow!
    outToFile << ptrCar->getVin() << endl;
    outToFile << ptrCar->getMake() << endl;
    outToFile << ptrCar->getModel() << endl;
    outToFile << ptrCar->getYear() << endl;
    outToFile << ptrCar->getPrice() << endl;
    outToFile << ptrCar->getNumDoors() << endl;
    outToFile << ptrCar->getHatchback() << endl;
    outToFile << ptrCar->getMotor().getNumCylinders() << endl;  // THIS IS COMPOSITION!!!
    outToFile << ptrCar->getMotor().getHorsePower() << endl;  // THIS IS COMPOSITION!!!
 
    // close the pipe
    outToFile.close();
 
    // tell user that the data was written
    cout << ptrCar->getMake() << " " << ptrCar->getModel() 
         << " was written to the file!" << endl;
  }
}