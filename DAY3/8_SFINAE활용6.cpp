#include <iostream>

class Test
{
public:
	Test(int a) {}	

	int size() { return 10; }
};
//-------------------------------
template<typename T> int check(decltype(std::declval<T>().size())*);

template<typename T> char check(...);

int main()
{
	int ret = sizeof( check<Test>(0) );

	if (ret == sizeof(int))
		std::cout << "has size()" << std::endl;
	else 
		std::cout << "size() ¾øÀ½" << std::endl;
}