// 2번 복사해오세요
#include <iostream>
#include "fname.h"

// 핵심 : template 과 배열 인자

template<typename T> void f1(T arg)
{
	std::cout << _FNAME_ << std::endl;
}

template<typename T> void f2(T& arg)
{
	std::cout << _FNAME_ << std::endl;
}

int main()
{
	int x[3] = { 1,2,3 };

	f1(x);	// 1. f1( int arg[3]) 로 만들었다면 에러, 배열은 복사 될수 없다
			// 2. f1( int* arg ) <== 그래서 이 모양의 함수 생성

	f2(x);	// f2( int(&arg)[3] ). 즉 배열을 가리키는 참조
			// 에러 아님
			// T=int[3],  arg = int(&)[3] 으로 결정됨.

	// 정리. 배열을 템플릿에 전달하는 경우
	f1(x);  // T=int*   arg=int*
	f2(x);	// T=int[3] arg=int(&)[3]

	// f1 처럼. 배열을 전달할때 포인터로 변환 되어서 받는 것을
	// "decay" 라고 합니다

}
