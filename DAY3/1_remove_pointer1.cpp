#include <iostream>
#include <type_traits>

// 160 page
// traits 의 종류
// 1. 타입에 대한 특성을 질의 : std::is_pointer<T>::value
// 2. 변형된 타입 얻기       : std::remove_pointer<T>::type

int main()
{
	bool b = std::is_pointer<int*>::value;

	std::remove_pointer<int*>::type n; // int

	std::cout << typeid(n).name() << std::endl;
}