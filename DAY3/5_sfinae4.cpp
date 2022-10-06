#include <iostream>

// SFINAE 가 적용되는 3가지 경우

void fn(...) { std::cout << "..." << std::endl; }

// 1. 함수의 리턴 타입이 실패할때 "SFINAE" 적용
// => T=int 라면 아래 코드는 "함수 생성에 실패", 하지만 에러는 아니고, 
//    fn(...) 사용
//template<typename T> 
//typename T::type fn(T a) { }


// 2. 함수의 인자 모양
// template<typename T>
//void fn(T a, typename T::type b) { }
	// (int a, int::type b)

// 3. 템플릿 인자의 모양
// => 생성자는 "반환 타입"이 없습니다.
// => 생성자에 "SFINAE" 기술을 적용할때 이 방법을 주로 사용.
template<typename T, typename T2 = typename T::type >
void fn(T a) { }

int main()
{
	fn(3);
}
