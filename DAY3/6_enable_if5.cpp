#include <iostream>
#include <type_traits>

template<typename T>
? T�� �������� ��츸 ���
printv(const T& value)
{
	std::cout << value << " : " << *value << std::endl;
}

template<typename T>
? T�� �����Ͱ� �ƴ� ��츸 ���
printv(const T& value)
{
	std::cout << value << std::endl;
}



int main()
{
	int n = 10;
	printv(&n); 
	printv(n);	
}