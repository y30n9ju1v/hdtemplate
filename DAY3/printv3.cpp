// printv3 - if_constexpr2.cpp
#include <iostream>
#include <type_traits>

// 방법 3. if constexpr 사용 - C++17

template<typename T>
void printv(const T& value)
{
	if constexpr ( std::is_pointer_v<T> )

		std::cout << value << " : " << *value << std::endl;
	else
		std::cout << value << std::endl;
}

int main()
{
	int n = 10;
	printv(&n); 
	printv(n);	
}
