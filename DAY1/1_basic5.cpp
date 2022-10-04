#include <iostream>

template<typename T> 
T square(T a)
{
	return a * a;
}

int main()
{
	printf("%p\n", &square );   // 될까요 ?? error
						// square 는 함수가 아닌 틀(템플릿) 입니다.
						// 틀은 메모리에 있지 않고, 
						// 컴파일 시에서 컴파일러가 사용합니다.
						// 따라서, 틀은 메모리 주소가 없습니다.

	printf("%p\n", &square<int> );		// ok
										// 1. square(int)를 생성하고
										// 2. 주소를 출력
	printf("%p\n", &square<double> );

	// 핵심. 
	square<int>(3);			// 이렇게 해도 함수가 생성되고
	auto p = &square<int>;	// 이렇게 해도 함수는 생성됩니다.

//	auto p2 = &square; // error.
}

