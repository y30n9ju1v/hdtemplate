#include <iostream>

// 컴파일 하지 말고, 현재 코드에서 에러를 모두 찾아 보세요

template<typename T>
void foo(T arg)
{
	goo(arg);	// A
	goo();		// B
}

int main()
{

}