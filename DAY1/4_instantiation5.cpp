#include <iostream>
#include <functional>
#include <type_traits> // std::type_identity

// 27page. identity

template<typename T> void foo(T a)
{
}

template<typename T> struct type_identity
{
	using type = T;
};
// type_identity<int>::type => int
// 구조체 템플릿은 
// 1. 타입을 명시적으로 전달하거나
// 2. 생성자로 추론할수 있거나(C++17)
// 3. deduction guide 가 있어야 합니다.

// 아래 기술은 함수 템플릿의 "타입인자 생략을 할수 없도록 하는 기술" 입니다.
// C++20 이전 : "identity" 라는 이름으로 개발자들이 만들어서 사용
// C++20 에서 : "std::type_identity" 라는 이름으로 C++표준에 추가됨.
//template<typename T> void goo( typename type_identity<T>::type a)

template<typename T> void goo(typename std::type_identity<T>::type a)
{
}

int main()
{
	foo(10);		// ok. 타입 생략해도 되고
	foo<int>(10);	// ok. 전달해도 됩니다.

	goo(10);	  // error. 타입을 생략하면 error 를 내고 싶다.
	goo<int>(10); // ok
}