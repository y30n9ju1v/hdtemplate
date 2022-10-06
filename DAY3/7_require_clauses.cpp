// enable_if5 복사 하세요
#include <iostream>
#include <type_traits>

// 아래 printv 처럼, enable_if 를 사용한 
// 함수 템플릿 오버로딩은 아주 널리 사용되었습니다.
// => 그런데, 코드가 너무 복잡해 보입니다.

// 그래서 C++20 에서 "requires clauses expression" 이라는 새로운 문법도입

// "C++20 Concept" 이라는 문법의 "하위 문법" 입니다.

template<typename T> requires std::is_pointer_v<T>
void printv(const T& value)
{
	std::cout << value << " : " << *value << std::endl;
}

template<typename T> requires (!std::is_pointer_v<T>)
void printv(const T& value)
{
	std::cout << value << std::endl;
}

int main()
{
	int n = 10;
	printv(&n);
	printv(n);
}