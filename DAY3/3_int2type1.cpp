// if constexpr1.cpp 복사 해서 주석 지워 보세요
#include <iostream>
#include <type_traits>

// 아래 "pointer template" 은
// 1. 템플릿 자체는 에러가 없다.
// 2. T=int 일때 인스턴스화가 되면 에러 이다.(T=int* 일때는 에러아님)
// 3. T=int 일때 인스턴스화가 되지 않으면 에러 아니다.

template<typename T> void pointer(const T& value)
{
	std::cout << value << " : " << *value << std::endl;
}

template<typename T> void not_pointer(const T& value)
{
	std::cout << value << std::endl;
}






template<typename T>
void printv(const T& value)
{
	if (std::is_pointer_v<T>)  

		std::cout << value << " : " << *value << std::endl;
	else
		std::cout << value << std::endl;
}

int main()
{
	int n = 10;
	printv(n);	// error.
}