// printv1.cpp - integral_constant2.cpp �����ϼ���
#include <iostream>
#include <type_traits> 

// ��� 1. true_type/false_type �� ����� �Լ� �����ε� - C++11 ���

template<typename T> void printv_imp(const T& value, std::true_type)
{
	std::cout << value << " : " << *value << std::endl;
}

template<typename T> void printv_imp(const T& value, std::false_type)
{
	std::cout << value << std::endl;
}

template<typename T>
void printv(const T& value)
{
	printv_imp(value, std::is_pointer<T>());
}

int main()
{
	int n = 10;
	printv(n);
}
