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

	Price<ReadyDish>* price1 = new Price<ReadyDish>;
	
for(int i = 0; i <5; i++){
	ReadyDish dish("hello", i, i, "pov", "pov", 1);
	dish.setPresent(true);
	price1->push_back(dish);
}

Price<ReadyDish>::iterator it(price1->begin());

it++;
it++;

ReadyDish dish("heADSADAllo", 5, 5, "pov", "pov", 1);
dish.setPresent(true);

price1->insert(it, dish);

for(int i = 0 ; i< price1->size();i++)
	(*price1)[i].show();



delete price1;

	
#ifdef OS_WIN
	system("pause");
#endif
	return 0;
}

