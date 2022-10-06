#include <iostream>

// C++11 constexpr  함수
// => 인자 값을 컴파일 시간에 알수 있고, 함수 호출하는 곳이
// => 컴파일 시간에 결과를 알아야 하는 곳이라면
// => 컴파일 시간에 수행해달라.

constexpr std::size_t factorial(std::size_t n)
{
	return n == 1 ? 1 : n * factorial(n-1);
}

int main()
{
	int x[ factorial(5) ]; // 배열의 크기는 컴파일 시간에 알아야 합니다.

	int n = 5;
	int x1[factorial(n)];	// error. n이 변수 이므로 
							// 컴파일 시간 실행 안됨

	int ret = factorial(n); // 호출하는 곳이 컴파일 시간을 요구하지 않는다.
							// 실행시간 호출
}