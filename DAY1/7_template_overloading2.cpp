#include <iostream>
#include <concepts>

// overloading1 번은 
// => "int 타입" 과 "int가 아닌타입" 을 다르게 처리하는 코드입니다.


// "정수계열" 과 "실수계열"을 다르게 처리하고 싶다면.. 
// => 유명한 요구 조건 입니다.
// => C++20 이전 : enable_if, true_type/false_type, if constexpr로해결
// => C++20 : concept 으로 해결
// 모두 내일 부터 배우는 기술

// 아래 코드는 "C++20" 입니다. 
template<typename T> requires std::integral<T>
T square(T a)
{
	std::cout << "integral" << std::endl;
	return a * a;
}

template<typename T> requires (!std::integral<T>)
T square(T a)
{
	std::cout << "not integral" << std::endl;
	return a * a;
}

int main()
{
	square(3);  
	square(3.4);
	square(3.4f); // float 도 실수 계열이므로 아래 버전 사용
	
}