#include <iostream>

template<typename T>
constexpr int made_year = -1;

// 라이브러리에 다양한 클래스가 있는데, 언제 만들어 졌는지 버전관리를 하고 싶다.
// => 각 클래스 설계자가 "made_year" variable template 을 특수화 하기로 약속
class AAA {};
template<> constexpr int made_year<AAA> = 2002;


class BBB {};
template<> constexpr int made_year<BBB> = 2020;

int main()
{
	std::cout << made_year<AAA> << std::endl;
	std::cout << made_year<BBB> << std::endl;
	std::cout << made_year<int> << std::endl;

}



