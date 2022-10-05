#include <iostream>

// T가 포인터 인지 조사하는 도구
// T의 특성을 조사하는 traits 만드는 방법

// 1. primary template 을 만들고 false 반환(value = false라는 의미)
// 2. 조건을 만족하는 부분 특수화 버전을 만들고 true 반환(value = true)

// is_pointer 같은 것을 "컴파일 시간에 사용하는 메타 함수" 라고도 합니다.

template<typename T> struct is_pointer
{
//	bool value = false; // 1. C++이전에는 이렇게 직접 초기화 안됩니다.
						// 2. 이렇게 하면 value 는 상수가 아닌 "변수" 입니다.

//	enum { value = false }; // C++11 이전 사용하던 기술
							// C++98 시절에 구조체 안에서 초기화 되고
							// 컴파일 시간 상수로 사용하는 방법은
							// enum 밖에 없습니다. 
							// "enum hack" 이라고 합니다.

	static constexpr bool value = false; // C++11 스타일!!
							// 장점 : value 가 bool 타입 입니다.
							// static constexpr 은 외부 선언 필요없습니다.
};


template<typename T> struct is_pointer<T*>
{
//	enum { value = true };
	static constexpr bool value = true;
};



template<typename T> 
void fn(const T& arg)
{
	// 현재 T는 int, int* 
	if (  is_pointer<T>::value  )
		std::cout << "pointer" << std::endl;
	else
		std::cout << "not pointer" << std::endl;
}

int main()
{
	int n = 0;
	fn(n);
	fn(&n);
}