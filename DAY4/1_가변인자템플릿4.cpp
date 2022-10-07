#include <iostream>

template<typename T> void printv(const T& a)
{
	std::cout << a << std::endl;
}

template<typename ... Types> void foo(Types ... args)
{
	// args : 1, 2, 3

//	printv(args...);	// printv(1, 2, 3) 의 의미.
						// printv() 는 인자가 한개 이므로 error

//	printv(args)...;	// printv(1), printv(2), printv(3) 의 의도.
						// 하지만. error

	// 핵심 1. pack expansion 을 할수 있는 위치는 정해져 있습니다.
	// 1. 함수 호출의 ()  : goo(args...)
	// 2. {} 초기화 구문  : int x[] = {args...};
	// 3. 템플릿 인자 <>  : tuple<Types...>  
	// 
//	args...;				// error
//	int x[] = { args... };	// ok.

	// args 의 모든 내용을 printv 에 보내기 위해
	// C++11 초창기에 사용했던 기술

	int dummy[] = { 0, (printv(args), 0)... };
			   // { (printv(1), 0), (printv(2), 0), (printv(3), 0) };
}

int main()
{
	foo(1, 2, 3);
	foo();
}

