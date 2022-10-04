#include <iostream>
#include <functional>
#include <type_traits> // std::type_identity

template<typename T>
void foo(T a, T b)
{
}

// C++20 �ȵǽô� ���� "type_identity" ������ ������
template<typename T>
void goo(T a, typename std::type_identity<T>::type  b)
{
}

int main()
{
	foo(3.4, 10);	// error. Ÿ�� ������ �������Ƿ� "�Լ����ڷ� ����"�ؾ� �ϴµ�
					// 1��° ���ڸ� ���� "double"
					// 2��° ���ڸ� ���� "int" �̹Ƿ� Ÿ�� ���� �ȵ�

	goo(3.4, 10);	// ok.. 1��° ���ڷθ� Ÿ�� ����
					// 2��° ������ Ÿ���� ������ 1��°�� ���� Ÿ��
					// goo(double, double) �� ����
					// 2��° ���ڴ� "10" �� double�� ���� ����
}