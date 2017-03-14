#pragma once
#include <cstddef>
#include "povar.h"

class Dish {
protected:
	char* name;
	float price;
	float mass;
	Povar *povar;

public:

	Dish(const char* name, float price,  float mass, Povar *pov);

	Dish(const char* name, float price, float mass, const char* povar_name, const char* povar_secName);

	void setName(const char *name);

	void setPrice(float price);

	void setMass(float mass);

	void setPovar(Povar *povar);

	void setPovar(const char* povar_name = NULL, const char* povar_secName = NULL);

	void show();

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

	~PrepackDish();

};//by K`VARK