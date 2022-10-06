#include <iostream>
#include <type_traits>

// ���� ���ø� ���� : ��� Ÿ�Կ� �����ϴ� �Լ�
//                 (��� Ÿ�Կ� ���� �Լ� ����)
// 
// enable_if ���� : ������ �����ϴ� Ÿ�Կ� ���� �����ϴ� �Լ�
//					(������ �����ϴ� Ÿ�Կ� ���ؼ��� �Լ��� ����)
//					������ �������� ������ ������ �ƴ϶�, ������!

template<typename T>
std::enable_if_t< std::is_pointer_v<T> >
printv(const T& value)
{
	std::cout << value << " : " << *value << std::endl;
}

template<typename T>
std::enable_if_t< !std::is_pointer_v<T> >
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