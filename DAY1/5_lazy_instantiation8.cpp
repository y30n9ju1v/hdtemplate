#include <iostream>

// ������ ���� ����, ���� �ڵ忡�� ������ ��� ã�� ������

template<typename T>
void foo(T arg)
{
	goo(arg);	// A
	goo();		// B
}

int main()
{

}