#include <iostream>

// �Ʒ� �ڵ带 "godbolt.org" ���� Ȯ���� ������.

template<typename ... Types> 
void foo(Types ... args)
{
	// �ٽ� 1. ��� �˾� �μ���
	// Types : template parameter pack ( "Ÿ�Ե�" �� �ֽ��ϴ�.)
	// args  : function parameter pack ( "����" �� �ֽ��ϴ�.)

	// �ٽ� 2. sizeof...
	std::cout << sizeof...(Types) << std::endl;
	std::cout << sizeof...(args)  << std::endl;


}

int main()
{
	foo(1, 2, 3); // Types : int, int, int
				  // args  : 1,   2,   3
}