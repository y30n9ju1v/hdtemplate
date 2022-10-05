#include <iostream>
#include <type_traits>

// is_pointer 2�� ������ ������. is_array ����� ������.

template<typename T> 
void fn(T& arg)
{
	std::cout << is_array<T>::value << std::endl;
}
int main()
{
	int n = 0;
	int x[3] = {1,2,3};

	fn(n);	// 0(false)
	fn(x);	// 1(true) ���;� �մϴ�.
	
}