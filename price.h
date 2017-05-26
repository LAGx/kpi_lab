#ifndef PRICE
#define PRICE
#include "config.h"
#include "dish.h"

#ifdef OS_WIN
#pragma once
#endif

using namespace std;

template<class T>
class Price{
private:

	bool activeList = 1;
	T** dishList[2] = {nullptr, nullptr};


	int len = 0;

public:
	class iterator;

	int size();

	Price(){
	}

	Price(Price<T> &price){
		*this = price;
	}

	void insert(iterator i, T& el);

	void erase(int index);
	void push_back(T &dish);
	
	T& operator[](int i);
	void  operator=(Price<T> &price);

	iterator begin() {return iterator(dishList[activeList]); };
	iterator end(){return iterator(dishList[activeList]+len); };
	
	~Price(){
		for(int i = 0;i<len;i++)
		delete dishList[activeList][i];
		if(dishList[activeList] != nullptr)
		delete [] dishList[activeList];
	}

	class iterator{
		T** curr;

	public:

		iterator(T** begin = nullptr): curr(begin){
		}

		iterator(const Price<T>::iterator& begin):curr(begin.curr){
		}

		T** operator+(int n){ return curr+n;}

		T* operator++(int){return *(curr++);}
		T* operator--(int){return *(curr--); }
		T* operator++(){return *(++curr);}
		T* operator--(){return *(--curr);}

		bool operator=(const iterator& it){return curr = it.curr; }

		bool operator!=(const iterator& it){return curr != it.curr; }
		bool operator==(const iterator& it){return curr == it.curr; }

		T* operator*(){return *curr;}
	};

};


template<class T>
void Price<T>::insert(iterator it, T& el){

               iterator end_original(it);
	dishList[!activeList] = new T*[this->size()];

	int i = 0;
	for(i = 0;end_original != this->end();end_original++, i++){
		dishList[!activeList][i] = new T(*(*end_original));
	}


	delete *it;
	T* temp = *it;
	temp = new T(el); 

	push_back(el);
int a = 0;
	for(it++;it != this->end(); it++, a++)
		*(*it) = *dishList[!activeList][a];
	


	for(;i >= 0;i-- )
		delete dishList[!activeList][i];

   	delete  [] dishList[!activeList];

	len++;	

}


template<class T>
int Price<T>::size(){
	return len;
}


template<class T>
void Price<T>::erase(int index){

	if(index >= len)
		throw out_of_range("Price[] : index is out of range");

	dishList[!activeList] = new T*[len-1];
	int plus = 0;
	for(int i = 0;i<len-1;i++){
		if(i == index)
			plus = 1;
		dishList[!activeList][i] = new T(*dishList[activeList][i+plus]);
		delete dishList[activeList][i];
	}

	if(dishList[activeList] != nullptr)
		delete [] dishList[activeList];

	activeList = !activeList;
	len -= 1;
}

template<class T>
void Price<T>::push_back(T &dish){
	len++;

	dishList[!activeList] = new T*[len];

	for(int i = 0;i<len-1;i++){
		dishList[!activeList][i] = new T(*dishList[activeList][i]);
		delete dishList[activeList][i];
	}

	dishList[!activeList][len-1] = new T(dish);

	if(dishList[activeList] != nullptr)
		delete [] dishList[activeList];

	activeList = !activeList;
}

template<class T>	
T& Price<T>::operator[](int index){
	if(index >= len)
		throw out_of_range("Price[] : index is out of range");
	return *dishList[activeList][index];
}

template<class T>
void  Price<T>::operator=(Price &price){
	for(int i = 0;i < price.length();i++){
		this->push_back(price[i]);
		this->len = price.len;
	}
}

#endif