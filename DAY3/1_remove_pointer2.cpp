#include <iostream>
#include <type_traits>


// 변형된 타입을 얻는 traits 를 만드는 방법

// 1. primary template 을 만들고 "using type = T" 를 넣으세요

// 2. 원하는 타입을 얻을수 있도록 "부분 특수화 버전"을 만들어서
//    타입을 분할 합니다.
//    "int*" ==> "int" 와 "*" 로 분할

template<typename T> struct remove_pointer
{
	using type = T;
};
template<typename T> struct remove_pointer<T*>
{
	using type = T;
};


int main()
{
	remove_pointer<int*>::type n; // int

	std::cout << typeid(n).name() << std::endl;
}