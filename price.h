#ifndef PRICE
#define PRICE
#include "config.h"
#ifdef OS_WIN
#pragma once
#endif
#include <iostream>
#include <cstddef>
using namespace std;

template<class T>
class Price{
private:

	T** arr = nullptr;

	size_t len = 0;


public:
	class iterator;

	Price()
	{};

	Price(Price<T>& pr){
	//	*this = pr;
	};


	void insert(iterator i, T& el);
	void push_back(T &el);
	size_t size(){
		return len;
	}
	
	T* operator[](int i){
		return arr[i];
	}
	void operator=(Price<T> &price){
		delete [] price.arr;
		price.arr = new T*[size()];
		price.len = size();

		for(int i = 0;i < size();i++){
			price.arr[i] = new T(*arr[i]);
		} 
	}

	iterator begin() {return iterator(arr); };
	iterator end(){return iterator(arr+len); };

	~Price(){
		if(arr != nullptr){
			for(int i = 0;i < size();i++)
				delete arr[i];
			delete [] arr;
		}
	}


	class iterator{
	private:
		T** curr;
	public:
		iterator(T** begin = nullptr): curr(begin)
		{}

		iterator(const Price<T>::iterator& begin):curr(begin.curr)
		{}

		T* operator+(int n){ return *(curr+n);}

		T* operator++(int){return *(curr++);}
		T* operator--(int){return *(curr--); }
		T* operator++(){return *(++curr);}
		T* operator--(){return *(--curr);}

		void operator=(const iterator& it){curr = it.curr; }

		bool operator!=(const iterator& it){return curr != it.curr; }
		bool operator==(const iterator& it){return curr == it.curr; }

		T& operator*(){return **curr;}

	};

};

template<class T>
void Price<T>::insert(iterator i, T& el){

	int normal_pos = 0;
	for(iterator tempi = begin();tempi != i; tempi++, normal_pos++);

	T** temp = new T*[size()];
	for(int i = 0;i < size();i++){
		temp[i] = new T(*arr[i]);
		delete arr[i];
	}
	delete [] arr;

	len++;
	this->arr = new T*[size()];

	for(int i = 0;i < size() ;i++){
		if(i < normal_pos){
			arr[i] = new T(*temp[i]);
			delete temp[i];
		}
		else if(i == normal_pos){
			arr[i] = new T(el);
		}
		else if(i > normal_pos){
			arr[i] = new T(*temp[i-1]);
			delete temp[i-1];
		}
	}

	delete [] temp;
}

template<class T>
void Price<T>::push_back(T &el){
	insert(this->end(), el);
}


#endif