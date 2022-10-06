#include <iostream>

template<int N> struct int2type
{
	enum { value = N };
};

// C++11 만들때 "int2type" 을 더욱 발전 시켜서 C++11 표준에 추가했습니다.
// int 뿐 아니라 모든 정수형 타입의 상수 들을 타입화 할수 있도록 아래처럼 변경
// => 단, 실수는 C++20 부터 지원되므로 C++11 만들때는 고려하지 않음

template<typename T, T N> struct integral_constant
{
	static constexpr T value = N;
};

int main()
{
	// 아래 코드는 0, 1을 다른 타입으로 만든것
	int2type<0> t1;
	int2type<1> t2; 

	// 아래 코드는 c1, c2, c3 가 모두 다른 타입
	integral_constant<int, 0> c1;
	integral_constant<int, 1> c2;
	integral_constant<short, 1> c3;

	// true/false 는 참/거짓을 나타내는 값 입니다. 같은 타입 입니다.
	// b1, b2는 다른 타입 입니다.
	integral_constant<bool, true>  b1;
	integral_constant<bool, false> b2;

	// true_type/false_type 는 참/거짓을 나타내는 타입 입니다.
	// 서로 다른 타입
	using true_type  = integral_constant<bool, true>;
	using false_type = integral_constant<bool, false>;
}