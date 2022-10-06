#include <iostream>


// 일반 전역 변수(상수)
constexpr int made_year1 = -1;


// C++17, variable template
template<typename T>
constexpr int made_year2 = -1;

int main()
{
	std::cout << made_year1 << std::endl;  // -1

	std::cout << made_year2 << std::endl;	// error. 타입인자가 없다.

	std::cout << made_year2<int>    << std::endl;	// ok. -1
	std::cout << made_year2<double> << std::endl;	// ok. -1
	
}



