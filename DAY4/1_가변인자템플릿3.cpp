#include <iostream>

int hoo(int a) { return -a; }

void goo(int a, int b, int c) 
{
	printf("goo : %d, %d, %d\n", a, b, c);
}

template<typename ... Types> 
void foo(Types ... args)
{
	// args : 1, 2, 3 이 들어 있습니다.

//	goo(args); // error. parameter pack 을 함수 인자로 전달할수 없습니다.

	goo(args...);	// ok.  pack expansion 
					// pack 안의 모든 요소를 "," 를 사용해서 열거해 달라.
					// goo(1, 2, 3)
	// 핵심 1. pack expansion
	// "pack을 사용하는 패턴" => "E1패턴", "E2패턴", "E3패턴"

	goo(args...);		// goo(E1, E2, E3)			즉, goo(1,2,3)
	goo(++args...);		// goo(++E1, ++E2, ++E3)

//	goo(hoo(args...));  // goo(hoo(E1, E2, E3)) 인데.
						// hoo() 는 인자가 한개이므로.. error

	goo( hoo(args)... );// goo(hoo(E1), hoo(E2), hoo(E3))
						// goo( -2, -3, -4)
}



int main()
{
	foo(1, 2, 3);
}
