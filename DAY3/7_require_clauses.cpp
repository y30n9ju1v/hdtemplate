// enable_if5 ���� �ϼ���
#include <iostream>
#include <type_traits>

// �Ʒ� printv ó��, enable_if �� ����� 
// �Լ� ���ø� �����ε��� ���� �θ� ���Ǿ����ϴ�.
// => �׷���, �ڵ尡 �ʹ� ������ ���Դϴ�.

// �׷��� C++20 ���� "requires clauses expression" �̶�� ���ο� ��������

// "C++20 Concept" �̶�� ������ "���� ����" �Դϴ�.

template<typename T> requires std::is_pointer_v<T>
void printv(const T& value)
{
	std::cout << value << " : " << *value << std::endl;
}

template<typename T> requires (!std::is_pointer_v<T>)
void printv(const T& value)
{
	std::cout << value << std::endl;
}

int main()
{
	int n = 10;
	printv(&n);
	printv(n);
}