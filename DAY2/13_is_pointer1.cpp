#include <iostream>

// type traits ���
// => Ÿ���� �پ��� Ư��(Ư��)�� �����ϴ� ���
// => 1990��� ���� ó�� ���ߵǾ���,
// => C++11 ǥ�ؿ� �߰��� ���

template<typename T>
void printv(const T& value)
{
	if ( T �� ������ Ÿ���̶�� )
		std::cout << value << " : " << *value << std::endl;	
	else
		std::cout << value << std::endl;
}

int main()
{
	int n = 10;
	printv(&n); 
	printv(n);	
}