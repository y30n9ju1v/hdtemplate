#include <iostream>

// template instantiation(템플릿 인스턴스화)
// => 템플릿(틀) 로 부터 실제 "함수/클래스"를 만드는 과정

// template instantitaion 결과 확인 하는 방법 - 12 page
// 1. godbolt.org		=> 가장 권장하는 방법.. !
// 2. cppinsights.io

// 3. 직접 컴파일러를 사용해서 어셈블리 코드를 만들어서 확인 - 12page 참고
//    => g++ 소스이름.cpp -S  하면 "소스이름.s" 파일 생성됩니다.
//    => cl  소스이름.cpp /FAs    "소스이름.asm" 

// 4. 함수 이름을 출력해 보는 방법

// 5. C++20 의 std::source_location 클래스 사용
//  => basic4.cpp 예제..

#include "fname.h"  // _FNAME_ 이 이 헤더에 있습니다.
template<typename T> 
T square(T a)
{
	// __func__ : 현재 함수의 이름을 담은 C++ 표준 매크로
	//			  단, 인자의 모양이 출력되지 않습니다.
	//std::cout << __func__ << std::endl;

	// __FUNCSIG__         : 함수 이름 (signature 포함). C++ 표준 아님. VC전용
	// __PRETTY_FUNCTION__ : 함수 이름 (signature 포함). C++ 표준 아님. g++전용
	//std::cout << __FUNCSIG__ << std::endl;


	std::cout << _FNAME_ << std::endl;

	return a * a;
}

int main()
{
	square<int>(3);			// int square(int) 함수 생성
	square<double>(3.3);
	square(3);
}

