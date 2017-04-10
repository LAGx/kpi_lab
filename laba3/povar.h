#ifndef POVAR
#define POVAR

#include "config.h"

#ifdef OS_WIN
#pragma once
#endif
#include <iostream>

class Povar;


class Povar {
private:
	char *name;
	char *secName;

	void setName(const char* name);
	void setSecName(const char* secName);
public:

	Povar(Povar *pov); 

	Povar(const char* name, const char* secName);

	void show(bool isBeauty = false); //parametr true make tabulation

	void change(const  char* name = nullptr, const  char* secName = nullptr);

	bool operator==(const Povar& p);

	friend std::ostream& operator<<(std::ostream& stream, const Povar& povar);
	friend std::istream& operator>>(std::istream& stream, Povar& povar);

	~Povar();
};//by K`VARK

#endif