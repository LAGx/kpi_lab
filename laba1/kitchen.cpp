#include "dish.h"
#include "povar.h"
#include <cstring>
#include <cstddef>
#include <iostream>


using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////    POVAR  ///////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
Povar::Povar(const char* name, const char* secName) {
	this->name = new char[2];
	this->secName = new char[2];
	setName(name);
	setSecName(secName);
}

Povar::Povar(Povar *pov){
	this->name = new char[2];
	this->secName = new char[2];
	setName(pov->name);
	setSecName(pov->secName);
}

void Povar::setName(const char* name) {
	delete []this->name;
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}


void Povar::setSecName(const char* secName) {
	delete []this->secName;
	this->secName = new char[strlen(secName) + 1];
	strcpy_s(this->secName, strlen(secName) + 1, secName);
}


void Povar::show(bool isBeauty) {
	if (isBeauty) {
		cout << "    Name: " << name << endl;
		cout << "    SecName: " << secName << endl;
	}
	else {
		cout << "Name: " << name << endl;
		cout << "SecName: " << secName << endl;
	}
}


void Povar::change(const char* name, const char* secName) {
	if (name != NULL)
		setName(name);

	if (secName != NULL)
		setSecName(secName);
}


Povar::~Povar() {
	delete[] name;
	delete[] secName;
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////// Dish //////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////





Dish::Dish(const char* name, float price, float mass, const char* povar_name, const char* povar_secName) {
	this->name = new char[2];
	setName(name);
	setPrice(price);
	setMass(mass);
	this->povar = new Povar("None", "None");
	setPovar(povar_name, povar_secName);
}


Dish::Dish(const char* name, float price, float mass, Povar* pov) {
	this->name = new char[2];
	setName(name);
	setPrice(price);
	setMass(mass);
	this->povar = new Povar("None", "None");
	setPovar(pov);
}


void Dish::setName(const char *name) {
	delete []this->name;
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}


void Dish::setPrice(float price) {
	this->price = price;
}


void Dish::setMass(float mass) {
	this->mass = mass;
}


void Dish::setPovar(const char* povar_name, const char* povar_secName) {
	this->povar->change(povar_name, povar_secName);
}

void Dish::setPovar(Povar *pov) {
	delete povar;
	povar = new Povar(pov);
}

void Dish::show() {
	cout << "--------------------------" << endl;
	cout << "Name: " << name << endl;
	cout << "Price: " << price << "$" << endl;
	cout << "Mass: " << mass << " gr." << endl;
	cout << "Povar: " << endl;
	povar->show(1);
}

Dish::~Dish() {
	delete povar;
	delete[] name;
}

void Dish::DateForDish::dateWarnings() {
	char err[] = "WARNING: ";
	if (month > 12) {
		cout << err << "month too long." << endl;
	}
	if (day > 31) {
		cout << err << "day too long." << endl;
	}
	if (hour > 24) {
		cout << err << "hour too long" << endl;
	}
	if (minutes > 60) {
		cout << err << "minutes too long" << endl;
	}
	if (seconds > 60) {
		cout << err << "seconds too long" << endl;
	}
}
///////////////////////////////////////////////////////////////////////////////
///////////////////////// ReadyDish //////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

ReadyDish::ReadyDish(const char* name, float price, float mass, Povar *pov, int timeToReady):Dish(name, price, mass, pov){
	setTimeToReady(timeToReady);
}

ReadyDish::ReadyDish(const char* name, float price, float mass, const char* povar_name, const char* povar_secName, int timeToReady):Dish(name, price, mass, povar_name, povar_secName){
	setTimeToReady(timeToReady);
}

void ReadyDish::setPresent(bool present) {
	isPresent = present;
}

void ReadyDish::setTimeToReady(int timeToReady) {
	if (!timeToReady) {
		this->timeToReady.isInit = 1;
		this->timeToReady.minutes = timeToReady;
	}
}

void ReadyDish::show() {
	if (isPresent) {
		Dish::show();
		if (timeToReady.isInit) {
			cout << "Time to ready: " << timeToReady.minutes << " min." << endl;
		}
		else {
			cout << "Unknown time." << endl;
		}
	}
	else {
		cout << "--------------------------" << endl;
		cout << "sorry, but " << name << " is not available now." << endl;
	}
}

ReadyDish::~ReadyDish() {

}

///////////////////////////////////////////////////////////////////////////////
///////////////////////// PrepackDish //////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

PrepackDish::PrepackDish(const char* name, float price, float mass, Povar *pov, char* howToSave, DateForDish timeToSave):Dish(name, price, mass, pov) {
	if (timeToSave.isInit) {
		setTimeToSave(timeToSave);
	}
	this->howToSave = new char[2];
	setHowToSave(howToSave);
}	

PrepackDish::PrepackDish(const char* name, float price, float mass, const char* povar_name, const char* povar_secName, char* howToSave, DateForDish timeToSave) : Dish(name, price, mass, povar_name, povar_secName) {
	if (timeToSave.isInit) {
		setTimeToSave(timeToSave);
	}
	this->howToSave = new char[strlen(howToSave) + 1];
	setHowToSave(howToSave);
}

void PrepackDish::setHowToSave(char* howToSave) {
	delete [] this->howToSave;
	this->howToSave = new char[strlen(howToSave) + 1];
	strcpy_s(this->howToSave, strlen(howToSave) + 1, howToSave);
}

void PrepackDish::setTimeToSave(DateForDish timeToSave) {
	this->timeToSave.isInit = 1;
	this->timeToSave = timeToSave;
}

void PrepackDish::show() {
	Dish::show();
	if (timeToSave.isInit) {
		cout << "Time to save: " << timeToSave.year << "y. "<< timeToSave.month << "m. " << timeToSave.day << "d." << endl;
	}
	else {
		cout << "Unknown time to save." << endl;
	}
	cout << "Recomends to save: " << howToSave << endl;
	timeToSave.dateWarnings();
}

PrepackDish::~PrepackDish() {
	delete[] this->howToSave;
}