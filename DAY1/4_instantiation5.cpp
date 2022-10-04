#include <iostream>
#include <functional>
#include <type_traits> // std::type_identity

// 27page. identity

template<typename T> void foo(T a)
{
}

template<typename T> struct type_identity
{
	using type = T;
};
// type_identity<int>::type => int
// ����ü ���ø��� 
// 1. Ÿ���� ��������� �����ϰų�
// 2. �����ڷ� �߷��Ҽ� �ְų�(C++17)
// 3. deduction guide �� �־�� �մϴ�.

// �Ʒ� ����� �Լ� ���ø��� "Ÿ������ ������ �Ҽ� ������ �ϴ� ���" �Դϴ�.
// C++20 ���� : "identity" ��� �̸����� �����ڵ��� ���� ���
// C++20 ���� : "std::type_identity" ��� �̸����� C++ǥ�ؿ� �߰���.
//template<typename T> void goo( typename type_identity<T>::type a)

template<typename T> void goo(typename std::type_identity<T>::type a)
{
}

int main()
{
	foo(10);		// ok. Ÿ�� �����ص� �ǰ�
	foo<int>(10);	// ok. �����ص� �˴ϴ�.

	goo(10);	  // error. Ÿ���� �����ϸ� error �� ���� �ʹ�.
	goo<int>(10); // ok
}