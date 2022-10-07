// get3.cpp
#include <iostream>
#include "tuple.h"


template<typename T>
void fn(T& tp)
{
	typename tuple_element<1, T>::type n1;

	std::cout << typeid(n1).name() << std::endl; 
}

int main()
{
	tuple<int, double, char> t(1, 3.4, 'A');

	fn(t);
}