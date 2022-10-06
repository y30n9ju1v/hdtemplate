#include <iostream>

template<typename T> struct remove_all_pointer
{
	using type = T;
};

template<typename T> struct remove_all_pointer<T*>
{
	// ��͸� ����ؼ� �����͸� �Ѱ��� ����
	// => ����� ����� "������ �ܰ迡�� T=int" �̹Ƿ� �����Ͱ� �ƴϴ�.
	//    primary template ���

	using type = typename remove_all_pointer<T>::type;

	// ���� : C++ǥ�ؿ��� "remove_all_pointer" �� �����ϴ�.
};


int main()
{
//	std::remove_pointer<int***>::type n; // int**

	remove_all_pointer<int***>::type n; // int

	std::cout << typeid(n).name() << std::endl;
}