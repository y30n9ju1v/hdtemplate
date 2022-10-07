#include <iostream>

// 핵심 1. 선언문에서 이름만 제거하면 "타입" 이 됩니다.

// "int f(int a, double b)" => int(int, double)

int f(int a, double b) { return 0; }

// 함수의 반환 타입 구하기

// 1. result 템플릿을 만들고 "using type = T" 를 넣습니다
template<typename T> struct result
{
	using type = T;
};

// 2. 원하는 타입을 얻을수 있도록 부분 특수화 합니다.
// "int(int, double)" => int 와 나머지타입들 로 분리 해야 합니다.
template<typename R, typename A1, typename A2>
struct result<R(A1, A2)>
{
	using type = ? ;
};


template<typename T> void foo(T& a) 
{
	// T : int(int, double) 입니다.
	typename result<T>::type n;  // int 

	std::cout << typeid(n).name() << std::endl;  
}


int main()
{
	foo(f);
}