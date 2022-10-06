#include <iostream>

class Test
{
public:
	int size() { return 10; }
};

template<typename T> void check( decltype( T().size() )*  ) 
{ 
	std::cout << "T" << std::endl; 
}

template<typename T> void check(...) 
{
	std::cout << "..." << std::endl;
}

int main()
{
	check<Test>(0);
}