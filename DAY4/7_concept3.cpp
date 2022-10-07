#include <concepts>
#include <iostream>
#include <vector>


template<typename T>
concept container = requires(T & c)
{
	std::begin(c);
	std::end(c);
};

// requires clauses 의 syntax sugar

// 1. 기본 모양.
template<typename T> requires container<T>
void f1(T a) 
{
	std::cout << "f1" << std::endl;
}

// 2. require 는 함수 () 뒤에 있어도 됩니다.
template<typename T> 
void f2(T a) requires container<T>
{
	std::cout << "f2" << std::endl;
}

// 3. typename 자리에 concept 이름 넣어도 됩니다.
//    단, type traits는 안됩니다.
template< container T> 
void f3(T a)
{
	std::cout << "f3" << std::endl;
}

// 4. template 없어도 됩니다. 
void f4(container auto a)  // 의미 : container 를 만족하는 임의의 타입
{
	std::cout << "f4" << std::endl;
}

// 5. 
void f5(auto a)  // 조건 없이 모든 타입!!  즉, 일반 템플릿
{
	std::cout << "f5" << std::endl;
}

int main()
{
	std::vector<int> v = { 1,2,3 };

	f1(v);
	f2(v);
	f3(v);
	f4(v);
	f5(v);
}