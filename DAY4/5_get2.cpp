#include "tuple.h"
#include <iostream>

int main()
{
	tuple<int, double, char> t(1, 3.4, 'A');

	std::cout << t.value << std::endl; // 1

	std::cout << t.value << std::endl; // 3.4 ������ �غ�����
	
	std::cout << t.value << std::endl; // 'A' ������ �غ�����.
}
