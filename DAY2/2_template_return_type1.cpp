#include <iostream>

// add 를 템플릿으로 만들어 봅시다.

// 방법 1. 한개의 템플릿 인자
// => 2개의 인자를 같은 타입을 전달해야 한다
// => 2개의 인자를 다른 타입을 보내면 에러 - 타입 결정 못함
// => 해결책은 "타입을 명시적으로 전달"
template<typename T>
T add(const T& a, const T& b)
{
	return a + b;
}

int main()
{
	std::cout << add(3, 4) 		<< std::endl; // ok
	std::cout << add(3.1, 4.3) 	<< std::endl; // ok

//	std::cout << add(3, 4.3) << std::endl; // error

	std::cout << add<double>(3, 4.3) << std::endl; // ok
}



