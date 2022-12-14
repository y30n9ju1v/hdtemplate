
// 핵심 1. 템플릿은 반드시 "헤더 파일에 구현까지 포함" 해야 합니다.

// 2. 구현을 별도의 "소스 파일"로 분리하려면 아래 처럼 하는 방법이 있습니다.

// square.h 를 만들고 아래 코드 넣으세요
template<typename T> T square(T a);

//==================================================
// square.cpp 를 만들고 아래 코드 넣으세요
#include "square.h"

template<typename T> T square(T a)
{
	return a * a;
}

// template 을 별도의 구현파일에 넣으려면
// 아래 처럼 explicit instantiation 을 사용하면 됩니다.
template int    square(int a);
template double square(double a);
//===========================================



// 4_instantiation2-1.cpp 에서 아래 처럼 만드세요
#include <iostream>
#include "square.h"

int main()
{
	// 아래 2줄인 왜 에러인지 생각해 보세요.
	square(3);
	square(3.4);
}

