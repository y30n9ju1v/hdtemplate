#include <iostream>

template<typename T> struct remove_pointer
{
	using type = T; 
};
template<typename T> struct remove_pointer<T*>
{
	using type = T;
};
// remove_pointer ���� ���� "����� ����(C++ǥ��ó��)" �Ϸ���
// const, volatile�� ��� ����ؾ� �մϴ�.
// ���� ���� is_pointer �� �����մϴ�.
template<typename T> struct remove_pointer<T* const>
{
	using type = T;
};
template<typename T> struct remove_pointer<T* volatile>
{
	using type = T;
};
template<typename T> struct remove_pointer<T* const volatile >
{
	using type = T;
};
// ���� :  const T* => �����ʹ� const �ƴ�. ���ü�� const 
//        T* const => �����Ͱ� const.     ���ü�� const �ƴ�

// const T* �� ������ ��ü�� const �ΰ��� �ƴϹǷ�, ��ó�� ���� �����ʿ�����ϴ�

template<typename T>
void fn(T& p)
{
	// remove_pointer ����Ҷ�, dependent name �̶�� 
	// "typename" ǥ���ؾ� �մϴ�.
	remove_pointer<T>::type n1; // error

	typename remove_pointer<T>::type n2; // ok
}


int main()
{
	std::cout << typeid(remove_pointer<int*>::type).name() 				  << std::endl;
	std::cout << typeid(remove_pointer<int* const>::type).name() 		  << std::endl;
	std::cout << typeid(remove_pointer<int* volatile>::type).name() 	  << std::endl;
	std::cout << typeid(remove_pointer<int* const volatile>::type).name() << std::endl;
}