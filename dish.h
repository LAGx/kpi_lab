#ifndef DISH
#define DISH
#include "config.h"

#ifdef OS_WIN
#pragma once
#endif


#include "povar.h"
#include <iostream>

class Dish;


class Dish {
protected:
	char* name;
	float price;
	float mass;
	Povar *povar;

public:
	Dish(const Dish& dish);

	Dish(const char* name, float price,  float mass, Povar *pov);

	Dish(const char* name, float price, float mass, const char* povar_name, const char* povar_secName);

	void setName(const char *name);

	void setPrice(float price);

	void setMass(float mass);

	void setPovar(Povar *povar);

	void setPovar(const char* povar_name = nullptr, const char* povar_secName = nullptr);

	virtual void show();

	Dish operator++();
	Dish operator++(int);
	void operator=(const Dish& dish);
	Dish operator+(const Dish& dish);
	bool operator>(const Dish& dish)const;//by price
	bool operator<(const Dish& dish)const;//by price

	friend std::ostream& operator<<(std::ostream& stream, const Dish& dish);
	friend std::istream& operator>>(std::istream& stream, Dish& dish);

	struct DateForDish {
		bool isInit = 0;
		unsigned int year;
		unsigned int month;
		unsigned int day;
		unsigned int hour;
		unsigned int minutes;
		unsigned int seconds;
		void dateWarnings();
	};

	~Dish();
};//by K`VARK


class ReadyDish :public Dish {
private:
	DateForDish timeToReady;
	bool isPresent = 0;
public:
	ReadyDish(const char* name, float price, float mass, Povar *pov, int timeToReady = 0);

	ReadyDish(const char* name, float price, float mass, const char* povar_name, const char* povar_secName, int timeToReady = 0);

	void setPresent(bool present);

	void setTimeToReady(int timeToReady);

	bool operator<(const ReadyDish& d);
	bool operator>(const ReadyDish& d);  
	void  operator=(const ReadyDish& d);  

	void show();

	~ReadyDish();

};//by K`VARK


class PrepackDish :public Dish {
private:
	char* howToSave;
	DateForDish timeToSave;
public:
	PrepackDish(const char* name, float price, float mass, Povar *pov, char* howToSave = "None", DateForDish timeToSave = { 0 });

	PrepackDish(const char* name, float price, float mass, const char* povar_name, const char* povar_secName, char* howToSave = "None", DateForDish timeToSave = {0});

	void setHowToSave(char* howToSave);

	void setTimeToSave(DateForDish TimeToSave);

	void show();

	bool operator>(const PrepackDish& dish)const;//by price
	bool operator<(const PrepackDish& dish)const;//by price
	void  operator=(const PrepackDish& d);  

	~PrepackDish();

};//by K`VARK

#endif