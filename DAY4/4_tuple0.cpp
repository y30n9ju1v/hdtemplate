#include <tuple>
#include <vector>
#include <iostream>

int main()
{
	// vector : "동일한 타입" 을 여러개 보관
	std::vector<int> v{1,2,3};

	
	// pair : "서로 다른 타입" 을 "2개" 보관
	std::pair<int, double> p1(1, 3.4);

	// pair 에 2개 이상 보관도 가능합니다.
	// => 하지만 복잡해 보입니다.
	std::pair<int, std::pair<double, char>> p2(1, { 3.4, 'A' } );


	// C++11 의 tuple : "서로 다른 타입"을 "N개" 보관

	std::tuple<int, double, char> t(3, 3.4, 'A');

	// tuple 의 요소 접근 : std::get 사용
	std::get<1>(t) = 9.9;

	std::cout << std::get<0>(t) << std::endl; // 3
	std::cout << std::get<1>(t) << std::endl; // 9.9
}
