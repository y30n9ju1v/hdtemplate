#include <iostream>
#include "fname.h"

// 규칙 3. 인자의 타입이 "forwarding reference(T&&)" 인 경우
// => C++11 에서 나온 "완벽한 전달"을 위한 기술
// => 인자가 lvalue 이면 "T 는 reference type"
//    인자가 rvaleu 이면 "T 는 value type"
// => "modern C++ 과정 참고"

template<typename T> void f3(T&& arg)
{
	std::cout << _FNAME_ << std::endl;
}

int main()
{
	int  n = 10;
	int& r = n;
	const int  c = 10;
	const int& cr = c;

	f3(3);	// 3 은 rvalue, T = int,    arg = int&& (rvalue reference )
	f3(n);	// n 은 lvalue, T = int&    arg = int& && => int& 
	
	f3(c);	// c 는 const lvalue, T= const int&,  arg =const int& &&
			//											const int&

	f3(r);	// r 은 lvalue, T=int&   arg = int& && => int&
	
	f3(cr); // cr 은 const lvalue
			// T = const int&		arg = const int& && => const int&

}