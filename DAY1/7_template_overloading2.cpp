#include <iostream>
#include <concepts>

// overloading1 번은 
// => "int 타입" 과 "int가 아닌타입" 을 다르게 처리하는 코드입니다.

// "정수계열" 과 "실수계열"을 다르게 처리하고 싶다면.. 

template<typename T> 
T square(T a)
{
	std::cout << "integral" << std::endl;
	return a * a;
}

template<typename T> 
T square(T a)
{
	std::cout << "not integral" << std::endl;
	return a * a;
}

int main()
{
	square(3);  
	square(3.4);
}