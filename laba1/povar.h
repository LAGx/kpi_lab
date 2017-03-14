#pragma once
#include <cstddef>

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

	void change(const  char* name = NULL, const  char* secName = NULL);

	~Povar();
};//by K`VARK
