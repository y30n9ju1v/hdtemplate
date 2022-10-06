#include <iostream>
#include <type_traits>

// 현재 C++은 "특정 타입" 에 따른 함수 오버로딩을
// 지원 합니다.
void foo(int)    {}
void foo(double) {}


// "타입"이 아닌 "특정 조건을 만족하는 타입들"에 따른 오버로딩은 있으면
// 좋지 않을까요 ?
// void goo(가상함수가있는클래스들) {}
// void goo(가상함수가없는클래스들) {}

template<typename T> 
void goo(T arg)
{
	std::cout << "가상함수가 있는 타입에 대한 알고리즘" << std::endl;
}

struct AAA
{
	virtual void foo() {}
};

int main()
{
	AAA a;
	int n;
	goo(a);
	goo(n);
}