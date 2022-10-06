#include <iostream>

int foo(int a, int b) ;// { return 0; }

int main()
{
	int a = 10;

	int n1 = sizeof(a);		// sizeof(변수)   4 byte
	int n2 = sizeof(int);	// sizeof(타입)   4 byte
	int n3 = sizeof(&foo);	// 함수 주소의 크기( 32bit:4byte, 64bit:8byte)
	
//	int n4 = sizeof(foo); // ?? 함수의 크기 ?? error

	// 핵심 : sizeof(함수 호출식)
	// => 함수 호출 결과의 크기
	// => 반환 타입의 크기
	// => 실제 함수를 호출하는 것은 아니므로, 함수 선언만 있어도 된다.
	int n5 = sizeof( foo(1, 3) ); // int 를 반환하므로 4

	// 평가 되지 않은 표현식( unevaluated expression )
	// => 어떠한 표현식(함수호출등)이 실행시간에는 수행되지 않고,
	//    컴파일 시간에만 컴파일러에의해 사용되는것
	// => C++에는 4개가 있습니다.

	sizeof( foo(1, 1) );	// 4
	decltype( foo(1, 1) );	// int
	noexcept( foo(1, 1) );	// false
	typeid( foo(1, 1) );	// int 타입에 대한 타입정보를 담은 
							// type_info객체. 
}