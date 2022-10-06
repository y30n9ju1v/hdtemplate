#include <iostream>
#include <type_traits>

template<int N>
struct int2type
{
	enum { value = N };
};

template<typename T> void printv_imp(const T& value, int2type<1> )
{
	std::cout << value << " : " << *value << std::endl;
}

template<typename T> void printv_imp(const T& value, int2type<0>  )
{
	std::cout << value << std::endl;
}

template<typename T>
void printv(const T& value)
{
	printv_imp(value, int2type< std::is_pointer_v<T> >() );

					// 0,  1 �� ���� Ÿ��������
					// int2type<0>, int2type<1> �� �ٸ� Ÿ��
					// 
					// "int2type<0>" �� Ÿ�� �Դϴ�.
					// "int2type<0>()" �� �ӽð�ü ���� �Դϴ�.
}		



int main()
{
	int n = 10;
	printv(n);	// error.
}