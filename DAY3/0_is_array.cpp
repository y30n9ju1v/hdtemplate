#include <iostream>
#include <type_traits>

template<typename T> 
void fn(T& arg)
{
	// 핵심 1. C++ 표준에 "std::is_array" 있습니다.
	std::cout << std::is_array<T>::value << std::endl;

	// 핵심 2. 어제 수업은 "is_array<T>::size" 로 크기 구했습니다.
	// => 하지만, 표준에서는 아래처럼 배열의 크기를 구해야 합니다.
	std::cout << std::extent<T, 0>::value << std::endl; // 3	
	std::cout << std::extent<T, 1>::value << std::endl; // 2

	// 1차배열인 경우는 아래 처럼 구해도 됩니다.
	std::cout << std::size(arg) << std::endl; // 3
}
// 주의 !! 아래 처럼 "value" 로 받는 경우
// 배열을 보내면 포인터로 받게 되므로 "is_array<T>::value" 는 항상 false입니다.
template<typename T>
void fn2(T arg)
{
	std::cout << std::is_array<T>::value << std::endl;  // 0
	std::cout << std::is_pointer<T>::value << std::endl;// 1
}

int main()
{
	int x[3][2] = { 0 };
	fn(x);
	fn2(x);
}
