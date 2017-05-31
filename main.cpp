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

//LABA 5
template<class Cont, class Elem>
void  insertSort(Cont& con, Elem el, char mode){
	if(con.size() == 0){
		con.insert(con.begin(),el);
	}else{
		if(mode == '<'){
			typename Cont::iterator i ;
			for( i = con.begin(); i != con.end(); ++i){
				if(*i > el && el < *i){
					con.insert(i, el);
					return;
				}
			}
		con.push_back(el);
		}else if(mode == '>'){
			typename Cont::iterator i ;
			for( i = con.begin(); i != con.end(); ++i){
				if(*i < el && el > *i){
					con.insert(i, el);
					return;
				}
			}
		con.push_back(el);
		}else{
			throw  "invalid mode" ;
		}
	}
}
/////////

int main() {

	Price<Dish> d;

for(int i = 10;i > 0; i -= 2){
	Dish dish2("None", i, i, "None", "None");
	d.insert(d.end(), dish2);
}

/////LABA5
Dish el("INSERT", 3, 3, "INSERT", "Ivanov");
insertSort(d, el, '>');
//////

for(int i = 0;i < 6; i++)
	d[i]->show();


	
#ifdef OS_WIN
	system("pause");
#endif
	return 0;
}

