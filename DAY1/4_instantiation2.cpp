#include <iostream>

// implicit instantiation
// 15 page

// 핵심 1. 용어 정리
// 인스턴스화(template instantiation)
// => 템플릿으로 부터 실제 "함수/클래스"를 만드는 과정

// 핵심 2. 인스턴스화 방법
// 1. implicit instantiation : 템플릿을 사용하는 코드를 보고 인스턴스화
//    => 타입을 명시적으로 전달하는 경우
//    => 타입을 명시적으로 전달하지 않은 경우.
// 
// 2. explicit instantiation

template<typename T>
T square(T a)
{
	return a * a;
}

// explicit instantiation 
// => 사용하는 코드가 없어도 인스턴스화 해달라는 의미.
// => godbolt.org 에서 확인해 보세요.
template int    square<int>(int a);
template double square<>(double a); // 타입인자 생략가능
template float  square(float a);    // <> 자체도 생략가능

int main()
{

}

