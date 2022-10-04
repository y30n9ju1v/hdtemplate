#include <iostream>

// implicit instantiation
// 15 page

// �ٽ� 1. ��� ����
// �ν��Ͻ�ȭ(template instantiation)
// => ���ø����� ���� ���� "�Լ�/Ŭ����"�� ����� ����

// �ٽ� 2. �ν��Ͻ�ȭ ���
// 1. implicit instantiation : ���ø��� ����ϴ� �ڵ带 ���� �ν��Ͻ�ȭ
//    => Ÿ���� ��������� �����ϴ� ���
//    => Ÿ���� ��������� �������� ���� ���.
// 
// 2. explicit instantiation

template<typename T>
T square(T a)
{
	return a * a;
}

int main()
{
	// �Ʒ� �ڵ�� ��� "implicit instantiation" �Դϴ�.
	square<int>(3);
	square<double>(3.3);	// Ÿ�� ����
	square(3);				// Ÿ�� ����
}

