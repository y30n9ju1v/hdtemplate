#include <iostream>
#include <type_traits>

// 기존 템플릿 개념 : 모든 타입에 동작하는 함수
//                 (모든 타입에 대한 함수 생성)
// 
// enable_if 개념 : 조건을 만족하는 타입에 대해 동작하는 함수
//					(조건을 만족하는 타입에 대해서만 함수를 생성)
//					조건을 만족하지 않으면 에러가 아니라, 사용안함!

template<typename T>
std::enable_if_t< std::is_pointer_v<T> >
printv(const T& value)
{
	std::cout << value << " : " << *value << std::endl;
}

template<typename T>
std::enable_if_t< !std::is_pointer_v<T> >
printv(const T& value)
{
	std::cout << value << std::endl;
}

int main()
{
	int n = 10;
	printv(&n); 
	printv(n);	
}