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

// explicit instantiation 
// => ����ϴ� �ڵ尡 ��� �ν��Ͻ�ȭ �ش޶�� �ǹ�.
// => godbolt.org ���� Ȯ���� ������.
template int    square<int>(int a);
template double square<>(double a); // Ÿ������ ��������
template float  square(float a);    // <> ��ü�� ��������

int main()
{

}

