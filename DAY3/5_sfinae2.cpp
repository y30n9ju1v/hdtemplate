#include <iostream>

// fn이 여러개 있을때 어떤 함수를 사용할지 결정하는 것은
// "반환 타입" 이 아닌 "인자의 형태"를 보고 결정. 

// SFINAE : Substitution Failure Is Not An Error. 

// 1. 함수 템플릿을 사용하기로 결정했는데..
// 2. T 의 타입을 결정하고, 인스턴스화(함수 생성)하다가 실패 했다면..
// 3. 에러는 아니고 후보군에서 제외 된다는 의미
// 4. 동일 이름의 다른 함수가 있다면 사용될수 있다.

template<typename T> 
typename T::type fn(T  a) { std::cout << " T "; return 0; }
// int::type fn(int a) {....}  라고 함수를 생성(인스턴스화)


int fn(... ) { std::cout << "..."; return 0; }


int main()
{
	fn(3);
}
