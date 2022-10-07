#include <iostream>
#include "tuple.h"

template<int N, typename TP> struct tuple_element;

template<typename T, typename ... Types>
struct tuple_element<0, tuple<T, Types...> >
{
	using type = T;
	using tupleType = tuple<T, Types...>;
};

template<int N, typename T, typename ... Types>
struct tuple_element<N, tuple<T, Types...> >
{
	using type = typename tuple_element<N - 1, tuple<Types...>>::type;
	using tupleType = typename tuple_element<N - 1, tuple<Types...>>::tupleType;
};

template<int N, typename TP>
typename tuple_element<N, TP>::type&
get(TP& tp)
{
	return static_cast<typename tuple_element<N, TP>::tupleType&>(tp).value;
}

int main()
{
	tuple<int, double, char> t(1, 3.4, 'A');

	get<1>(t) = 9.9;

	std::cout << get<0>(t) << std::endl;	// 1
	std::cout << get<1>(t) << std::endl;	// 9.9
	std::cout << get<2>(t) << std::endl;	// 'A'

	// 결국 tuple 의 생성과, get() 호출의 과정은 실행시간 오버헤드는 
	// 거의 없습니다.
	// 대부분의 작업은 컴파일 시간에 수행됩니다.(캐스팅도 컴파일 시간에 수행)
}