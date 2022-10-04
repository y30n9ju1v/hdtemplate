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
	foo(3.4, 10);
	goo(3.4, 10);
}