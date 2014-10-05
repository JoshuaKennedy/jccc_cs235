// *********************************************************
//
//  truck.cpp
//
//  This program implements a base class Vehicle, a Truck
//  class that is derived from Vehicle, and a Person class.
//  The main function is a driver that tests the Truck and
//  Person classes.
//
// *********************************************************

#include <iostream>
#include <string>

using namespace std;

//===============================
//  Declaration of Person Class
//===============================
class Person
{
public:
    Person();
    Person (string theName);
    Person (const Person& theObject);
    string getName() const;
    void setName(string newName);
    Person& operator=(const Person& rtSide);
    friend istream& operator >>(istream& inStream,
                                Person& personObject);
    friend ostream& operator <<(ostream& outStream,
                                const Person& personObject);
private:
    string name;
};


//================================
//  Declaration of Vehicle Class
//================================
class Vehicle
{
public:
    Vehicle();
    Vehicle(string m, int cyl, Person p);
    Vehicle(const Vehicle& theObject);
    string getManufacturer() const;
    int getCylinders() const;
    Person getOwner() const;
    void setManufacturer(string maker);
    void setCylinders(int cylinders);
    void setOwner (Person p);
    
    void output();
    // Outputs the data members of the class appropriately labeled
    
    Vehicle& operator=(const Vehicle& rtSide);
private:
    string manufacturer;
    int numCylinders;
    Person owner;
};


//===============================
//  Declaration of Truck Class
//===============================
class Truck : public Vehicle
{
public:
    Truck();
    Truck(string m, int cyl, Person p, double load, int tow);
    Truck(const Truck& theObject);
    double getLoadCapacity() const;
    int getTowingCapacity() const;
    void setLoadCapacity(double newLoad);
    void setTowingCapacity(int newTowing);
    
    void output();
    // Outputs the data members appropriately labeled.
    
    Truck& operator=(const Truck& rtSide);
private:
    double loadCapacity;
    int towingCapacity;
};


//===================
//   main function
//===================
int main()
{
    //
    // Variable declarations
    //
    string ownerName;
    string manufacturerName;
    int numCyl;
    double load;
    int towingCapacity;
    
    cout << endl;
    cout << "Testing Truck and Person classes..." << endl;
    cout << endl;
    
    cout << "First create 3 trucks..." << endl;
    cout << "Truck A ... " << endl;
    cout << "Enter the name of the owner: ";
    cin >> ownerName;
    cout << "Enter the number of cylinders: ";
    cin >> numCyl;
    cout << "Enter the name of the manufacturer: ";
    cin >> manufacturerName;
    cout << "Enter the load capacity: ";
    cin >> load;
    cout << "Enter the towing capacity: ";
    cin >> towingCapacity;
    
    Truck truckA;
    Person ownerA;
    cout << "Using the mutator functions to set up the owner "
    << "and truck A..." << endl;
    ownerA.setName(ownerName);
    truckA.setOwner(ownerA);
    truckA.setManufacturer(manufacturerName);
    truckA.setCylinders(numCyl);
    truckA.setLoadCapacity(load);
    truckA.setTowingCapacity(towingCapacity);
    
    cout << endl;
    cout << "Enter data for Truck B ... " << endl;
    cout << "Enter the name of the owner: ";
    cin >> ownerName;
    cout << "Enter the number of cylinders: ";
    cin >> numCyl;
    cout << "Enter the name of the manufacturer: ";
    cin >> manufacturerName;
    cout << "Enter the load capacity: ";
    cin >> load;
    cout << "Enter the towing capacity: ";
    cin >> towingCapacity;
    cout << endl;
    
    cout << "Using the constructor with 5 arguments to "
    << "create Truck B..." << endl;
    Person ownerB(ownerName);
    Truck truckB(manufacturerName, numCyl, ownerB, load, towingCapacity);
    
    cout << "Using the copy constructor to create Truck C as a copy "
    << "of Truck A..." << endl;
    Truck truckC(truckA);
    
    cout << "Using the accessor functions to print the truck info ..." << endl;
    cout << endl;
    cout << "Truck A ..." << endl;
    cout << "Owner: " << truckA.getOwner() << endl;
    cout << "Manufacturer: " << truckA.getManufacturer() << endl;
    cout << "Number of Cylinders: " << truckA.getCylinders() << endl;
    cout << "Load Capacity: " << truckA.getLoadCapacity() << endl;
    cout << "Towing Capacity: " << truckA.getTowingCapacity() << endl;
    cout << endl;
    
    cout << "Truck B ..." << endl;
    cout << "Owner: " << truckB.getOwner() << endl;
    cout << "Manufacturer: " << truckB.getManufacturer() << endl;
    cout << "Number of Cylinders: " << truckB.getCylinders() << endl;
    cout << "Load Capacity: " << truckB.getLoadCapacity() << endl;
    cout << "Towing Capacity: " << truckB.getTowingCapacity() << endl;
    cout << endl;
    
    cout << "Truck C ..." << endl;
    cout << "Owner: " << truckC.getOwner() << endl;
    cout << "Manufacturer: " << truckC.getManufacturer() << endl;
    cout << "Number of Cylinders: " << truckC.getCylinders() << endl;
    cout << "Load Capacity: " << truckC.getLoadCapacity() << endl;
    cout << "Towing Capacity: " << truckC.getTowingCapacity() << endl;
    cout << endl;
    
    cout << "Enter a new owner name for Truck C: ";
    Person ownerC;
    cin >> ownerC;
    truckC.setOwner(ownerC);
    
    cout << "Enter a new towing capacity for Truck C: ";
    cin >> towingCapacity;
    truckC.setTowingCapacity(towingCapacity);
    
    cout << "Enter a new manufacturer for Truck B: ";
    cin >> manufacturerName;
    truckB.setManufacturer(manufacturerName);
    cout << endl << endl;
    
    cout << "Truck B after the changes..." << endl;
    truckB.output();
    cout << endl;
    
    cout << "Truck C after the changes..." << endl;
    truckC.output();
    cout << endl;
    
    cout << "Testing the assignment operators..." << endl;
    cout << "Testing truckA = truckB" << endl;
    cout << endl;
    
    truckA = truckB;
    
    cout << "Press any letter to see the results...";
    cin >> ownerName;
    cout << endl;
    
    cout << "Truck A " << endl;
    truckA.output();
    cout << endl;
    
    cout << "Truck B" << endl;
    truckB.output();
    cout << endl;
    
    cout << "Making some changes..." << endl;
    cout << "Enter a load capacity for truck A: ";
    cin >> load;
    truckA.setLoadCapacity(load);
    cout << "Setting the owner of truck A to Bo" << endl;
    truckA.setOwner(Person ("Bo"));
    cout << "Changing owner of truck B to the ower of truck C" << endl;
    ownerB = ownerC;
    truckB.setOwner(ownerB);
    cout << "Enter a new number of cylinders for truck B: ";
    cin >> numCyl;
    truckB.setCylinders(numCyl);
    cout << endl;
    
    cout << "After the changes ..." << endl;
    
    cout << "Truck A " << endl;
    truckA.output();
    cout << endl;
    
    cout << "Truck B" << endl;
    truckB.output();
    
    cout << endl << "The end..." << endl;
    
    return 0;
}

//================================
//   Vehicle Class Definitions
//================================

Vehicle::Vehicle()
{
}


Vehicle::Vehicle (string m, int cyl, Person p): manufacturer(m),
numCylinders(cyl), owner(p)
{
}


Vehicle::Vehicle(const Vehicle& theObject)
{
    manufacturer = theObject.manufacturer;
    numCylinders = theObject.numCylinders;
    owner = theObject.owner;
}


string Vehicle::getManufacturer() const
{
    return manufacturer;
}


int Vehicle::getCylinders() const
{
    return numCylinders;
}


Person Vehicle::getOwner() const
{
    return owner;
}


void Vehicle::setManufacturer (string m)
{
    manufacturer = m;
}


void Vehicle::setCylinders(int n)
{
    numCylinders = n;
}


void Vehicle::setOwner(Person p)
{
    owner = p;
}

void Vehicle::output()
{
    cout << "Owner: " << owner << endl;
    cout << "Manufacturer: " << manufacturer << endl;
    cout << "Number of Cylinders: " << numCylinders << endl;
}


Vehicle& Vehicle::operator=(const Vehicle& rtSide)
{
    manufacturer = rtSide.manufacturer;
    numCylinders = rtSide.numCylinders;
    owner = rtSide.owner;
    
    return *this;
}


//==============================
//   Truck Class Definitions
//==============================


// --------------------------------
// ----- ENTER YOUR CODE HERE -----
// --------------------------------

// constructor (default)
Truck::Truck() : loadCapacity(0.0),towingCapacity(0), Vehicle() {
	// member initialization list used
}

// constructor (full)
Truck::Truck(string m, int cyl, Person p, double load, int tow) : loadCapacity(load), towingCapacity(tow), Vehicle(m, cyl, p) {
	// member initialization list used
}

// constructor (copy)
Truck::Truck(const Truck& theObject) : loadCapacity(theObject.loadCapacity), towingCapacity(theObject.towingCapacity), Vehicle(theObject) {
	// member initialization list used
}

double Truck::getLoadCapacity() const {
	return this->loadCapacity;
}

int Truck::getTowingCapacity() const {
	return this->towingCapacity;
}

void Truck::setLoadCapacity(double newLoad) {
	this->loadCapacity = newLoad;
}

void Truck::setTowingCapacity(int newTowing) {
	this->towingCapacity = newTowing;
}

void Truck::output() {
	// Outputs the data members appropriately labeled.
	cout << "Truck object:\nLoad Capacity: " << this->getLoadCapacity() << "\nTowing Capacity: " << this->getTowingCapacity() << endl;
	this->Vehicle::output();
}

Truck& Truck::operator=(const Truck& rtSide) {
	
	// efficiency check
	if ( this == &rtSide ) return *this;
    
	this->loadCapacity = rtSide.loadCapacity;
	this->towingCapacity = rtSide.towingCapacity;
	// copy Vehicle to Vehicle object
	(*this).Vehicle::operator=(rtSide);
	return *this;
}

//==============================
//   Person Class Definitions
//==============================

// constructor (default)
Person::Person() : name("N/A") {
}

// constructor (full)
Person::Person (string theName) : name(theName) {
}

// constructory (copy)
Person::Person (const Person& theObject) : name(theObject.name) {
}

string Person::getName() const {
	return name;
}

void Person::setName(string newName) {
	name = newName;
}

Person& Person::operator=(const Person& rtSide) {
	this->name = rtSide.name;
	return *this;
}

istream& operator >>(istream& inStream, Person& personObject) {
    
	inStream >> personObject.name;
	return inStream;
	
}

ostream& operator <<(ostream& outStream, const Person& personObject) {
    
	outStream << personObject.name;
	return outStream;
    
}
// --------------------------------
// --------- END USER CODE --------
// --------------------------------
