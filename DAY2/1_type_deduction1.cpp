// 42 page
#include <iostream>
#include "fname.h"

template<typename T> 
void fn(T arg)
{
	while (--arg) {};
}
int main()
{
	int 	n = 10;
	double 	d = 3.4;
	const int c = 10;

	fn<int>(3); // Ÿ���� ��������� ����
				// ������ ����ڰ� ������ Ÿ������ �Լ�����
				// T=int
	// Ÿ���� �������� ������ "�Լ� ����"�� ���� Ÿ���� ����
	fn(n);	// T=int	
	fn(d);	// T=double
	fn(c);	// T=const int ?? T=int	=> ���� int
			// ���� T=const int �� �ߴٸ�, 
			// ������ ���忡���� "�����ϴ�."
}


