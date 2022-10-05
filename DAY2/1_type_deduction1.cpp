// 42 page
#include <iostream>
#include "fname.h"

template<typename T> 
void fn(T arg)
{
	while (--arg) {};
}
int main()
{
	int 	n = 10;
	double 	d = 3.4;
	const int c = 10;

	fn<int>(3); // 타입을 명시적으로 전달
				// 무조건 사용자가 전달한 타입으로 함수생성
				// T=int
	// 타입을 전달하지 않으면 "함수 인자"를 보고 타입을 결정
	fn(n);	// T=int	
	fn(d);	// T=double
	fn(c);	// T=const int ?? T=int	=> 답은 int
			// 만약 T=const int 로 했다면, 
			// 개발자 입장에서는 "불편하다."
}


