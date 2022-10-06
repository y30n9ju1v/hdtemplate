#include <iostream>

int foo(int a, int b) ;// { return 0; }

int main()
{
	int a = 10;

	int n1 = sizeof(a);		// sizeof(����)   4 byte
	int n2 = sizeof(int);	// sizeof(Ÿ��)   4 byte
	int n3 = sizeof(&foo);	// �Լ� �ּ��� ũ��( 32bit:4byte, 64bit:8byte)
	
//	int n4 = sizeof(foo); // ?? �Լ��� ũ�� ?? error

	// �ٽ� : sizeof(�Լ� ȣ���)
	// => �Լ� ȣ�� ����� ũ��
	// => ��ȯ Ÿ���� ũ��
	// => ���� �Լ��� ȣ���ϴ� ���� �ƴϹǷ�, �Լ� ���� �־ �ȴ�.
	int n5 = sizeof( foo(1, 3) ); // int �� ��ȯ�ϹǷ� 4

	// �� ���� ���� ǥ����( unevaluated expression )
	// => ��� ǥ����(�Լ�ȣ���)�� ����ð����� ������� �ʰ�,
	//    ������ �ð����� �����Ϸ������� ���Ǵ°�
	// => C++���� 4���� �ֽ��ϴ�.

	sizeof( foo(1, 1) );	// 4
	decltype( foo(1, 1) );	// int
	noexcept( foo(1, 1) );	// false
	typeid( foo(1, 1) );	// int Ÿ�Կ� ���� Ÿ�������� ���� 
							// type_info��ü. 
}