#include <iostream>
#include <concepts>

// overloading1 ���� 
// => "int Ÿ��" �� "int�� �ƴ�Ÿ��" �� �ٸ��� ó���ϴ� �ڵ��Դϴ�.

// "�����迭" �� "�Ǽ��迭"�� �ٸ��� ó���ϰ� �ʹٸ�.. 

template<typename T> 
T square(T a)
{
	std::cout << "integral" << std::endl;
	return a * a;
}

template<typename T> 
T square(T a)
{
	std::cout << "not integral" << std::endl;
	return a * a;
}

int main()
{
	square(3);  
	square(3.4);
}