/*
*	Maruda Yurii [KA-65]
*	variant 10
*	c++ 14
*/

#include "config.h"
#include <iostream>
#include "povar.h"
#include "dish.h"

using namespace std;

int main() {

	Dish::DateForDish date = { true, 1999, 2, 3};
	Dish fish("fish", 20, 50, "Ivan", "kazak");
	Dish fish1("fish1", 40, 100, "Ivan", "kazak");
	Dish fish2("fish2", 10, 30, "Ivan", "kazak");

	cout << fish << fish1;
	cin >> fish;
	cout << fish << fish1;
	
#ifdef OS_WIN
	system("pause");
#endif

	return 0;
}

