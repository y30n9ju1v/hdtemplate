#include <iostream>

int hoo(int a) { return -a; }

void goo(int a, int b, int c) 
{
	printf("goo : %d, %d, %d\n", a, b, c);
}

template<typename ... Types> 
void foo(Types ... args)
{
	// args : 1, 2, 3 �� ��� �ֽ��ϴ�.

//	goo(args); // error. parameter pack �� �Լ� ���ڷ� �����Ҽ� �����ϴ�.

	goo(args...);	// ok.  pack expansion 
					// pack ���� ��� ��Ҹ� "," �� ����ؼ� ������ �޶�.
					// goo(1, 2, 3)
	// �ٽ� 1. pack expansion
	// "pack�� ����ϴ� ����" => "E1����", "E2����", "E3����"

	goo(args...);		// goo(E1, E2, E3)			��, goo(1,2,3)
	goo(++args...);		// goo(++E1, ++E2, ++E3)

//	goo(hoo(args...));  // goo(hoo(E1, E2, E3)) �ε�.
						// hoo() �� ���ڰ� �Ѱ��̹Ƿ�.. error

	goo( hoo(args)... );// goo(hoo(E1), hoo(E2), hoo(E3))
						// goo( -2, -3, -4)
}



int main()
{
	foo(1, 2, 3);
}
