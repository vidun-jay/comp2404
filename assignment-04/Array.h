#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <string>
#include "defs.h"

using namespace std;

template<class T>

class Array {

	public:
		//constructor
		Array();

		//destructor
		// ~Array();

		//other
		void add(const T& t);
		void remove(const T& t);
		int size() const;
		bool isFull();

		T& operator[](int index);
		const T& operator[](int index) const;

		Array<T>& operator+=(const T& t);
		Array<T>& operator-=(const T& t);
		void clear();

	private:
		int numElements;
		T* elements;

};

template<class T>
Array<T>::Array(){
	elements = new T[MAX_ARR];
	numElements = 0;
}

// template<class T>
// Array<T>::~Array(){
// 	delete [] elements;
// }

template<class T>
void Array<T>::add(const T& t){
	if (numElements >= MAX_ARR)   return;
  	elements[numElements++] = t;
}

template<class T>
void Array<T>::remove(const T& t){
	int index = 0;
	while (index < numElements){
		if (t == elements[index]){
			--numElements;
			break;
		}
		++index;
	}

	while (index < numElements){
		elements[index] = elements[index + 1];
		++index;
	}
}

template<class T>
int Array<T>::size() const {
	return numElements;
}

template<class T>
bool Array<T>::isFull(){
	return numElements >= MAX_ARR;
}

template<class T>
T& Array<T>::operator[](int index) {
	if (index < 0 || index >= numElements) {
		cerr << "Index out of bounds" << endl;
		exit(1);
	} return elements[index];
}

template<class T>
const T& Array<T>::operator[](int index) const {
	if (index < 0 || index >= numElements) {
		cerr << "Index out of bounds" << endl;
		exit(1);
	} return elements[index];
}

template<class T>
Array<T>& Array<T>::operator+=(const T& t) {
	add(t);
	return *this;
}

template<class T>
Array<T>& Array<T>::operator-=(const T& t) {
	remove(t);
	return *this;
}

template<class T>
void Array<T>::clear() {
    numElements = 0;
}

#endif