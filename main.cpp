#include <iostream>
#include <vector>
#include <list>
#include <deque>
using namespace std;


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



template<class C, class N>
void useSomeContainer(C em, N n, char mode){
	for(auto i:em)
		cout << i << "  ";
	cout << endl;

	insertSort(em, n, mode);

	for(auto i:em)
		cout << i << "  ";
	cout << endl;
}


template<class N>
void forTestUp(N n){

	//list<N> em = {1,2,5,5,20,40};
	vector<N> em  = {1 ,2,3,8,9,10};
	//deque<N> em = {1 ,2, 40,100,500};

	useSomeContainer(em, n, '<');
}
template<class N>
void forTestDown(N n){

	//list<N> em = {500,200,6,3,1];
	vector<N> em  = {10,9,8,2,1};
	//deque<N> em = {32,12,6,5,4,3,2,1};

	useSomeContainer(em, n, '>');
}



int main(){

int number = 12;

forTestDown(number);


return 0;
}