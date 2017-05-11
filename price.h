#ifndef PRICE
#define PRICE
#include "config.h"
#include "dish.h"

#ifdef OS_WIN
#pragma once
#endif


class Price{
private:

	bool activeList = 1;
	Dish** dishList[2] = {nullptr, nullptr};


	int size = 0;

public:

	int length();

	Price();
	Price(Price &price);

	void erase(int index);
	void push_back(Dish &dish);
	
	Dish& operator[](int i);
	void  operator=(Price &price);
	
	~Price();

};


#endif