#include <iostream>

// 핵심 : 문법 연습

template<typename T, typename U> struct Object
{
	static void fn() { std::cout << "T, U" << std::endl; }
};

// T*, U*
template<typename T, typename U> struct Object<T*, U*>
{
	static void fn() { std::cout << "T*, U*" << std::endl; }
};

// T*, U
template<typename T, typename U> struct Object<T*, U>
{
	static void fn() { std::cout << "T*, U" << std::endl; }
};

// 핵심 : T, T , 즉, 2개타입이 동일 타입일때

// primary template 의 타입인자가 2개 라면

// 1. 사용자는 반드시 타입인자를 2개 표기해야 합니다. : Object<int, double>

// 2. 부분 특수화의 오른쪽 끝(A부분)도 꼭 2개 표기해야 합니다.

// 3. 하지만, 부분 특수화 버전의 템플릿 인자 갯수를 2개가 아닐수도 있습니다.

template<typename T> struct Object<T, T>   // <=== "A"
{
	static void fn() { std::cout << "T, T" << std::endl; }
};

// int, U 만들어 보세요
template<typename U> struct Object<int, U>
{
	static void fn() { std::cout << "int, U" << std::endl; }
};

// int, short
// => 이 경우는 "부분 특수화가 아닙니다."
// => 특수화(specialization) 입니다. 모든 타입이 확정된 경우.
template<> struct Object<int, short>
{
	static void fn() { std::cout << "int, short" << std::endl; }
};

template<typename A, typename B, typename C> struct Object<A, Object<B,C>>
{
	static void fn() { std::cout << "A, Object<B, C>" << std::endl; }
};

int main()
{
	Object<char, double>::fn();	  // T, U
	Object<char*, double*>::fn(); // T*, U*	
	Object<short*, double>::fn(); // T*, U
	Object<float,  float>::fn();  // T, T
	Object<int,    float>::fn();  // int, U
	Object<int, short>::fn();	  // int, short

	Object<short, Object<char, int>>::fn();
					// A, Object<B, C> 로 출력해 보세요

}