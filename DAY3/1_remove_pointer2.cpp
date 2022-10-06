#include <iostream>
#include <type_traits>


// ������ Ÿ���� ��� traits �� ����� ���

// 1. primary template �� ����� "using type = T" �� ��������

// 2. ���ϴ� Ÿ���� ������ �ֵ��� "�κ� Ư��ȭ ����"�� ����
//    Ÿ���� ���� �մϴ�.
//    "int*" ==> "int" �� "*" �� ����

template<typename T> struct remove_pointer
{
	using type = T;
};
template<typename T> struct remove_pointer<T*>
{
	using type = T;
};


int main()
{
	remove_pointer<int*>::type n; // int

	std::cout << typeid(n).name() << std::endl;
}