#include <iostream>
#include "tuple.h"

template<int N, typename TP> struct tuple_element
{
	using type = TP;
};



// N == 0 
template<typename T, typename ... Types>
struct tuple_element<0, tuple<T, Types...> >
{
	// tuple<T, Types...> 의 0번째 요소 타입 : T
	// tuple<T, Types...> 의 0번째 요소를 저장하는 tuple 타입 : 자신, 즉, tuple<T, Types...>

	using type = T;
	using tupleType = tuple<T, Types...>;
};

// N != 0 
template<int N, typename T, typename ... Types>
struct tuple_element<N, tuple<T, Types...> >
{
	using type      = typename tuple_element<N - 1, tuple<Types...>>::type;
	using tupleType = typename tuple_element<N - 1, tuple<Types...>>::tupleType;
};

template<typename T>
void fn(T& tp)
{
	// T : tuple<int, double, char>

	typename tuple_element<1, T>::type n1; // double
	typename tuple_element<1, T>::tupleType n2; // tuple<double, char>

	std::cout << typeid(n1).name() << std::endl;
	std::cout << typeid(n2).name() << std::endl;
}

int main()
{
	tuple<int, double, char> t(1, 3.4, 'A');

	fn(t);
}