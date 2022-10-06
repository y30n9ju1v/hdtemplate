#include <iostream>
#include <type_traits>

// 160 page
// traits �� ����
// 1. Ÿ�Կ� ���� Ư���� ���� : std::is_pointer<T>::value
// 2. ������ Ÿ�� ���       : std::remove_pointer<T>::type

int main()
{
	bool b = std::is_pointer<int*>::value;

	std::remove_pointer<int*>::type n; // int

	std::cout << typeid(n).name() << std::endl;
}