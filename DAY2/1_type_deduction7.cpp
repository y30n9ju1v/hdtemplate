// 2번 복사해오세요
#include <iostream>
#include "fname.h"

// 핵심 : template 과 배열 인자

template<typename T>
void f1(T a, T b)
{
	std::cout << _FNAME_ << std::endl;
}
template<typename T> 
void f2(T& a, T& b)
{
	std::cout << _FNAME_ << std::endl;
}
int main()
{
	// "orange" : const char[7]
	// "apple"  : const char[6]
	f1("orange", "apple");	// ok
							// 1, 2 번째 인자는 배열 인데.. 값으로 받으므로
							// const char*, const char* 로 받게 됩니다.

	f2("orange", "apple"); // error. 왜 에러일까요 ??
							// 배열을 참조로 받으면 "배열"로 받게 됩니다.
							// 1, 2번째 인자는 크기가 다른 배열 이므로
							// 다른 타입입니다.

	f3("orange", "banana"); // ok.. 문자열 길이가 같으므로 같은 타입

}
