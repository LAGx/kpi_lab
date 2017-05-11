#include "price.h"
#include <iostream>

using namespace std;

Price::Price(){}

Price::Price(Price &price){
	*this = price;
}

int Price::length(){
	return size;
}

void Price::erase(int index){

	if(index >= size)
		throw out_of_range("Price[] : index is out of range");

	dishList[!activeList] = new Dish*[size-1];
	int plus = 0;
	for(int i = 0;i<size-1;i++){
		if(i == index)
			plus = 1;
		dishList[!activeList][i] = new Dish(*dishList[activeList][i+plus]);
		delete dishList[activeList][i];
	}

	if(dishList[activeList] != nullptr)
		delete [] dishList[activeList];

	activeList = !activeList;
	size -= 1;
}


void Price::push_back(Dish &dish){
	size++;

	dishList[!activeList] = new Dish*[size];

	for(int i = 0;i<size-1;i++){
		dishList[!activeList][i] = new Dish(*dishList[activeList][i]);
		delete dishList[activeList][i];
	}

	dishList[!activeList][size-1] = new Dish(dish);

	if(dishList[activeList] != nullptr)
		delete [] dishList[activeList];

	activeList = !activeList;
}

	
Dish& Price::operator[](int index){
	if(index >= size)
		throw out_of_range("Price[] : index is out of range");
	return *dishList[activeList][index];
}


void  Price::operator=(Price &price){
	for(int i = 0;i < price.length();i++){
		this->push_back(price[i]);
	}
}

	
Price::~Price(){
	for(int i = 0;i<size;i++)
		delete dishList[activeList][i];
	if(dishList[activeList] != nullptr)
		delete [] dishList[activeList];
}