// printv1.cpp - integral_constant2.cpp 복사하세요
#include <iostream>
#include <type_traits> 

// 방법 1. true_type/false_type 을 사용한 함수 오버로딩 - C++11 기술

template<typename T> void printv_imp(const T& value, std::true_type)
{
	std::cout << value << " : " << *value << std::endl;
}

template<typename T> void printv_imp(const T& value, std::false_type)
{
	std::cout << value << std::endl;
}

template<typename T>
void printv(const T& value)
{
	printv_imp(value, std::is_pointer<T>());
}

int main()
{
	int n = 10;
	printv(n);
}
