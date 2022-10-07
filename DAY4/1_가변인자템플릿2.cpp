#include <iostream>

// 아래 코드를 "godbolt.org" 에서 확인해 보세요.

template<typename ... Types> 
void foo(Types ... args)
{
	// 핵심 1. 용어 알아 두세요
	// Types : template parameter pack ( "타입들" 이 있습니다.)
	// args  : function parameter pack ( "값들" 이 있습니다.)

	// 핵심 2. sizeof...
	std::cout << sizeof...(Types) << std::endl;
	std::cout << sizeof...(args)  << std::endl;


}

int main()
{
	foo(1, 2, 3); // Types : int, int, int
				  // args  : 1,   2,   3
}