#include <iostream>
#include "tuple.h"

template<int N, typename TP> struct tuple_element
{
	using type = TP;
};



// N == 0 일때 타입을 구하기 위한 부분 특수화
template<typename T, typename ... Types> 
struct tuple_element<0, tuple<T, Types...> >
{
	using type = T;
};







template<typename T>
void fn(T& tp)
{
	// T : tuple<int, double, char>

	typename tuple_element<0, T>::type n1; // int
	typename tuple_element<1, T>::type n2; // double

	std::cout << typeid(n1).name() << std::endl;
	std::cout << typeid(n2).name() << std::endl;
}

int main()
{
	tuple<int, double, char> t(1, 3.4, 'A');

	fn(t);
}