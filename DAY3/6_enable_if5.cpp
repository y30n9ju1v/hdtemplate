#include <iostream>
#include <type_traits>

template<typename T>
? T가 포인터인 경우만 사용
printv(const T& value)
{
	std::cout << value << " : " << *value << std::endl;
}

template<typename T>
? T가 포인터가 아닌 경우만 사용
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