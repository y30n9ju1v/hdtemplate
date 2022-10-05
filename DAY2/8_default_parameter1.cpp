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

	Object<> obj3;	// 모든 인자를 디폴트 값 사용해 달라.(C++98)
					// int, double

	Object obj4; // C++17 부터는 <> 도 생략가능합니다.

}