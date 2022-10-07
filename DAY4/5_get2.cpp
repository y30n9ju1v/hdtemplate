#include "tuple.h"
#include <iostream>

int main()
{
	tuple<int, double, char> t(1, 3.4, 'A');

	std::cout << t.value << std::endl; // 1

	std::cout << t.value << std::endl; // 3.4 나오게 해보세요
	
	std::cout << t.value << std::endl; // 'A' 나오게 해보세요.
}
