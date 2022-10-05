#include <iostream>

// type traits 기술
// => 타입의 다양한 특성(특질)을 조사하는 기술
// => 1990년대 말에 처음 개발되었고,
// => C++11 표준에 추가된 기술

template<typename T>
void printv(const T& value)
{
	if ( T 가 포인터 타입이라면 )
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