#include <iostream>

// T가 포인터 인지 조사하는 도구
// T의 특성을 조사하는 traits 만드는 방법

// 1. primary template 을 만들고 false 반환(value = false라는 의미)

// 2. 조건을 만족하는 부분 특수화 버전을 만들고 true 반환(value = true)

template<typename T> struct is_pointer
{
	enum { value = false };
};

template<typename T> struct is_pointer<T*>
{
	enum { value = true };
};



template<typename T> 
void fn(const T& arg)
{
	// 현재 T는 int, int* 
	if (  is_pointer<T>::value  )
		std::cout << "pointer" << std::endl;
	else
		std::cout << "not pointer" << std::endl;
}

int main()
{
	int n = 0;
	fn(n);
	fn(&n);
}