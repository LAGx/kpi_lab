/*
*	Maruda Yurii [KA-65]
*	variant 10
*	c++ 14
*/
#include "config.h"
#include <iostream>
#include "price.h"
#include "dish.h"

using namespace std;


int main() {

	Price* price1 = new Price;
	
for(int i = 0; i <3; i++){
	ReadyDish dish("hello", i, i, "pov", "pov", i);
	price1->push_back(dish);
}


for(int i = 0 ; i< price1->length();i++)
	(*price1)[i].show();



delete price1;

	
#ifdef OS_WIN
	system("pause");
#endif
	return 0;
}

