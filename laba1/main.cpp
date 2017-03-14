/*
*	Maruda Yurii [KA-65]
*	laba #1, variant 10
*/
#include <iostream>
#include "dish.h"
#include "povar.h"

using namespace std;

int main() {

	Dish::DateForDish date = { true, 1999, 2, 3};
	PrepackDish fish("fish", 22, 54, "Ivan", "kazak", "alala", date);
	fish.show();

	system("pause");
	return 0;
}

