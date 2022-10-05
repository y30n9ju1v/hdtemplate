#include <iostream>

template<typename T, int N> 
struct Object
{
	T buff[N];	// 템플릿 인자는 항상 컴파일 시간에 크기를 알수 있기 때문에
				// 배열 크기로 사용가능
};
int main()
{
	int n = 10;
	Object<int,  n> obj1;	// error. 템플릿 인자값은 반드시
							// 컴파일 시간에 알아야 합니다.
	Object<int, 10> obj2;	// ok. 

	const int c1 = 10;	// 컴파일 시간 상수 ( 컴파일러가 초기값을 알고 있다)
	const int c2 = n;	// 실행시간 상수( 컴파일러는 초기값을 알수 없다)

	Object<int, c1> obj3; // ok
	Object<int, c2> obj4; // error.

	// 그래서 C++11 에서 "컴파일 시간 상수"를 다루는 또다른 키워드 제공
	constexpr int c3 = 10; // ok
	constexpr int c4 = n;  // error. 
	
	// 결론 : constexpr 상수는 항상 템플릿 인자로 사용가능.
}


