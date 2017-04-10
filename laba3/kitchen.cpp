#include "dish.h"
#include "povar.h"
#include <cstring>
#include <cstddef>
#include <iostream>
#include "config.h"
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
#ifdef OS_LINUX
	strcpy(this->name, name);
#endif
#ifdef OS_WIN
	strcpy_s(this->name, strlen(name) + 1, name);
#endif
}


void Povar::setSecName(const char* secName) {
	delete []this->secName;
	this->secName = new char[strlen(secName) + 1];
#ifdef OS_LINUX
	strcpy(this->secName, secName);
#endif
#ifdef OS_WIN
	strcpy_s(this->secName, strlen(secName) + 1, secName);
#endif
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
	if (name != nullptr)
		setName(name);

	if (secName != nullptr)
		setSecName(secName);
}

bool Povar::operator==(const Povar& p){
	return !(strcmp(name, p.name) + strcmp(secName, p.secName));
}

Povar::~Povar() {
	delete[] name;
	delete[] secName;
}

ostream& operator<<(ostream& stream, const Povar& povar){
	stream << "Name: " << povar.name << endl << "SecName: " << povar.secName << endl;
	return stream;
}
istream& operator>>(istream& stream, Povar& povar){
	char a[255], b[255];
	cout << "Input name: ";
	stream >> a;
	cout << "Input secName:";
	stream >> b;
	cout << endl;
	povar.change(a, b);
	return stream;
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////// Dish //////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////


Dish::Dish(const Dish& dish){
	this->name = new char[2];
	setName(dish.name);
	setPrice(dish.price);
	setMass(dish.mass);
	this->povar = new Povar("None", "None");
	setPovar(dish.povar);
}


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
#ifdef OS_LINUX
	strcpy(this->name, name);
#endif
#ifdef OS_WIN
	strcpy_s(this->name, strlen(name) + 1, name);
#endif

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

Dish Dish::operator++(){
	return Dish("None", ++price,0, "None", "None");
}
Dish Dish::operator++(int){
	return Dish("None", price++,0, "None", "None");
}
void Dish::operator=(const Dish& dish){
	setPrice(dish.price);
}
Dish Dish::operator+(const Dish& dish){
	return Dish("None", price+dish.price ,0, "None", "None");
}

ostream& operator<<(ostream& stream, const Dish& dish){
	stream << "Name: " << dish.name << endl;
	stream << "Price: " << dish.price << "$" << endl;
	stream << "Mass: " << dish.mass << " gr." << endl;
	stream << "Povar: \n" << *dish.povar << endl;
	return stream;
}
istream& operator>>(istream& stream, Dish& dish){
	char n[255]; int i;
	cout << "Name: ";
	stream >> n; dish.setName(n);
	cout << "Price: " ;
	stream >> i; dish.setPrice(i);
	cout  << "Mass: " ;
	stream >> i;dish.setMass(i);
	cout << "Povar: \n";
	stream >> *dish.povar;
	return stream;
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

bool ReadyDish::operator<(const ReadyDish& d){
	return timeToReady.minutes < d.timeToReady.minutes;
}
bool ReadyDish::operator>(const ReadyDish& d){
	return timeToReady.minutes > d.timeToReady.minutes;
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
#ifdef OS_LINUX
	strcpy(this->howToSave, howToSave);
#endif
#ifdef OS_WIN
	strcpy_s(this->howToSave, strlen(howToSave) + 1, howToSave);
#endif
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

/////////////////////////////////////////////////////////////////////////////////////////