#include <iostream>
#include "tuple.h"

int main()
{
//	tuple<			   char>				 // 2번째 기반, 'A'보관
//	tuple<     double, char>				 // 1번째 기반, 3.4보관
	tuple<int, double, char> t(1, 3.4, 'A'); // 1보관

	std::cout << t.value << std::endl; // 1

	std::cout << static_cast<tuple<double, char>&>(t).value << std::endl; // 3.4 나오게 해보세요
	
	std::cout << static_cast<tuple<char>&>(t).value << std::endl; // 'A' 나오게 해보세요.

	// 핵심 1. t 의 N 번째 요소를 접근려면
	//        t 를 "N 번째 기반 클래스 타입&" 로 캐스팅해서 value 를 접근하면 됩니다.

	get<1>(t) = 9.9;
}
// get 의 모양
template<int N, typename TP>
?
get(TP& tp)
{
	return static_cast<?>(tp).value;
}
