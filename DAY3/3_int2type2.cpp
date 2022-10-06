// if constexpr1.cpp ���� �ؼ� �ּ� ���� ������
#include <iostream>
#include <type_traits>

// �Լ� �����ε����� "� �Լ��� ���������� ������ �ð��� ����"
// => ������ ���� �Լ��� ���ø� �̶�� �ν��Ͻ�ȭ �ȵ�.

template<typename T> void printv_imp(const T& value, YES)
{
	std::cout << value << " : " << *value << std::endl;
}

template<typename T> void printv_imp(const T& value, NO)
{
	std::cout << value << std::endl;
}

template<typename T>
void printv(const T& value)
{
	// ����(T�� ������ �ΰ�) �� ���� �Լ� �����ε�
	printv_imp(value, std::is_pointer_v<T>  );
						// T�� ������ �̸� : true(1)
						// T�� �����;ƴϸ� : false(0)
						// => �Լ� �����ε��� "������ ������ Ÿ���� �޶�� �Ѵ�"
						// => �׷���, 0, 1 �� ���� Ÿ���̴�.

}



int main()
{
	int n = 10;
	printv(n);	// error.
}