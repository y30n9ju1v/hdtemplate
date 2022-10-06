// if constexpr1.cpp ���� �ؼ� �ּ� ���� ������
#include <iostream>
#include <type_traits>

// �Ʒ� "pointer template" ��
// 1. ���ø� ��ü�� ������ ����.
// 2. T=int �϶� �ν��Ͻ�ȭ�� �Ǹ� ���� �̴�.(T=int* �϶��� �����ƴ�)
// 3. T=int �϶� �ν��Ͻ�ȭ�� ���� ������ ���� �ƴϴ�.

template<typename T> void pointer(const T& value)
{
	std::cout << value << " : " << *value << std::endl;
}

template<typename T> void not_pointer(const T& value)
{
	std::cout << value << std::endl;
}






template<typename T>
void printv(const T& value)
{
	if (std::is_pointer_v<T>)  

		std::cout << value << " : " << *value << std::endl;
	else
		std::cout << value << std::endl;
}

int main()
{
	int n = 10;
	printv(n);	// error.
}