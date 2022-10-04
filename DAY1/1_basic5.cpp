#include <iostream>

template<typename T> 
T square(T a)
{
	return a * a;
}

int main()
{
	printf("%p\n", &square );   // �ɱ�� ?? error
						// square �� �Լ��� �ƴ� Ʋ(���ø�) �Դϴ�.
						// Ʋ�� �޸𸮿� ���� �ʰ�, 
						// ������ �ÿ��� �����Ϸ��� ����մϴ�.
						// ����, Ʋ�� �޸� �ּҰ� �����ϴ�.

	printf("%p\n", &square<int> );		// ok
										// 1. square(int)�� �����ϰ�
										// 2. �ּҸ� ���
	printf("%p\n", &square<double> );

	// �ٽ�. 
	square<int>(3);			// �̷��� �ص� �Լ��� �����ǰ�
	auto p = &square<int>;	// �̷��� �ص� �Լ��� �����˴ϴ�.

//	auto p2 = &square; // error.
}

