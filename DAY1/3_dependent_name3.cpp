// 3_dependent_name3
#include <iostream>

template<typename T>
struct Object
{
	template<typename U>
	static void mf()
	{
		std::cout << "template mf" << std::endl;
	}
};
int main()
{
	Object<int>::mf<int>();
	Object<double>::mf<int>();
	Object<char>::mf<int>();
}