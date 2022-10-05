#include <iostream>
#include "fname.h"

// 규칙 2. 인자의 타입이 "reference(T&)" 일때
// => 함수 인자가 가지고 있는 "reference" 를 제거하고 타입 결정
// => "const, volatile" 속성은 유지 한다.
template<typename T> void f2(T& arg)
{
	std::cout << _FNAME_ << std::endl;

	// T의 타입을 조사할때 "C++의 RTTI" 기술로 하지 마세요.
	// C++RTTI 기술은 "reference, const, volatile" 를 조사 못합니다.
//	std::cout << typeid(T).name() << std::endl;

	// 위처럼 "_FNAME_" 으로 조사하거나, "godbolt.org" 에서 확인하세요
}

int main()
{
	int  n = 10;
	int& r = n;
	const int  c = 10;
	const int& cr = c;

	f2(n);	// T = int			arg = int&
	f2(c);	// T = const int	arg = const int&
	f2(r);	// T = int			arg = int&
	f2(cr);	// T = const int	arg = const int&
}