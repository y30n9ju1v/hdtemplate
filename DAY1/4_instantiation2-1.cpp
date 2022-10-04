
// �ٽ� 1. ���ø��� �ݵ�� "��� ���Ͽ� �������� ����" �ؾ� �մϴ�.

// 2. ������ ������ "�ҽ� ����"�� �и��Ϸ��� �Ʒ� ó�� �ϴ� ����� �ֽ��ϴ�.

// square.h �� ����� �Ʒ� �ڵ� ��������
template<typename T> T square(T a);

//==================================================
// square.cpp �� ����� �Ʒ� �ڵ� ��������
#include "square.h"

template<typename T> T square(T a)
{
	return a * a;
}

// template �� ������ �������Ͽ� ��������
// �Ʒ� ó�� explicit instantiation �� ����ϸ� �˴ϴ�.
template int    square(int a);
template double square(double a);
//===========================================



// 4_instantiation2-1.cpp ���� �Ʒ� ó�� ���弼��
#include <iostream>
#include "square.h"

int main()
{
	// �Ʒ� 2���� �� �������� ������ ������.
	square(3);
	square(3.4);
}

