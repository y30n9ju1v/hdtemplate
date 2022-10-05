#include <iostream>
#include <type_traits>

// 방법 3. 2개의 템플릿 인자
// 반환 타입 표기 1. 사용자가 전달한다.
// => 아래 처럼 만들면, "T1, T2" 는 함수 인자로 추론 되지만
// => R은 컴파일러가 추론 할수 없습니다. 반드시 전달해야 합니다.
template<typename R, typename T1, typename T2>
R add(const T1 & a, const T2 & b)
{
	return a + b;
}

int main()
{
	std::cout << add<int>(3, 4) << std::endl;   // int, int
	std::cout << add<double>(3, 4.3) << std::endl; // int, double
}



