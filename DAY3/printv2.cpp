// printv2 
#include <iostream>
#include <type_traits>

// 방법 2. std::enable_if 를 사용하는 기술 - C++11

template<typename T>
std::enable_if_t< std::is_pointer_v<T> >
printv(const T& value)
{
	std::cout << value << " : " << *value << std::endl;
}
template<typename T>
std::enable_if_t< !std::is_pointer_v<T> >
printv(const T& value)
{
	std::cout << value << std::endl;
}
int main()
{
	int n = 10;
	printv(&n);
	printv(n);
}