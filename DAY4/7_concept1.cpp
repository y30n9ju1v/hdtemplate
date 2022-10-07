#include <iostream>
#include <vector>
#include <type_traits>

// Concept : C++20 의 Big4 중 한개.  1~2 번째 기술로 꼽히는 핵심중의 핵심
// 
// C++20 Big4 : Concept, Module(#include 대신 import), coroutine, range


template<typename T> void check(T& c)
{
	// T 가 포인터 타입 인지 알고 싶다.

	bool b = std::is_pointer_v<T>;
	// => type traits 기술
	// => 대부분 템플릿 특수화, 부분 특수화로 구현
	// => C++11 기술


	// T 가 컨테이너 인지 알고 싶다. ??
	// => 어떻게 구현해야 할까 ? 가 중요한게 아니라!!
	// => "컨테이너"의 정의를 어떻게 해야 할까? 가 중요 합니다.

	// C++20 이전, "named requirement" 
	// => 문서화로 정의
	// => cppreference.com 에서 "왼쪽에서 named requirement"

	// C++20 Concept
	// => 타입이 가져야 하는 요구조건을 "문서화"가 아닌 코드로 표현하는 문법
}



int main()
{
	int n = 0;
	std::vector<int> v = { 1,2,3 };
	int x[3] = { 1,2,3 };

	check(n);	
	check(v);	
	check(x);   
}