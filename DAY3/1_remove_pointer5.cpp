#include <iostream>

// traits 기술 정리
// 핵심 1. 헤더 파일은 "<type_traits>", C++11
#include <type_traits>


// C++14 에서 아래 도구가 표준에 추가 됩니다.
// => using template 사용.

template<typename T>
using remove_pointer_t = typename std::remove_pointer<T>::type ;

// C++17 부터 아래 도구가 표준에 추가 됩니다.
// => variable template 을 사용하는 기술

template<typename T>
constexpr bool is_pointer_v = std::is_pointer<T>::value;


template<typename T>
void fn(const T& arg)
{
	// 핵심 2. 타입의 특성 조사
	bool b1 = std::is_pointer<T>::value;
	bool b2 = std::is_pointer_v<T>;	// C++17 부터 지원
									// VC는 C++14 옵션에서도 컴파일됩니다.


	// 핵심 3. 변형 타입얻기
	typename std::remove_pointer<T>::type n1;

	std::remove_pointer_t<T> n2;	// 이 코드가 위와 동일합니다.
}




int main()
{
	int n = 0;
	fn(&n);
}