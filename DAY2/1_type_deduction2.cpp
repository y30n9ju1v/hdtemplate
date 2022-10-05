#include <iostream>
#include "fname.h"

// 규칙 1. 인자가 "값 타입(T arg)" 일때
// => 인자가 가지고 있는 "const, reference, volatile" 속성을 모두 제거하고
//    타입 결정
template<typename T> void f1(T arg)
{
	std::cout << _FNAME_ << std::endl;
}

int main()
{
	int  n = 10;
	int& r = n;
	const int  c = 10;
	const int& cr = c;

	f1(n);	// T = int
	f1(c);	// T = int
	f1(r);  // T = int
	f1(cr); // T = int
}