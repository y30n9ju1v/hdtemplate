#include <iostream>

// default parameter

template<typename T1 = int, typename T2 = double>
struct Object
{
	Object()
	{
		std::cout << typeid(T1).name() << std::endl;
		std::cout << typeid(T2).name() << std::endl;
	}
};

int main()
{
	Object<int, double> obj1; // int, double
	Object<int>         obj2; // int, double

	Object<> obj3;	// ��� ���ڸ� ����Ʈ �� ����� �޶�.(C++98)
					// int, double

	Object obj4; // C++17 ���ʹ� <> �� ���������մϴ�.

}