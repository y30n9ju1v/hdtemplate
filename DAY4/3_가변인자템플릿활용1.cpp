#include <iostream>

// �ٽ� 1. ���𹮿��� �̸��� �����ϸ� "Ÿ��" �� �˴ϴ�.

// "int f(int a, double b)" => int(int, double)

int f(int a, double b) { return 0; }

// �Լ��� ��ȯ Ÿ�� ���ϱ�

// 1. result ���ø��� ����� "using type = T" �� �ֽ��ϴ�
template<typename T> struct result
{
	using type = T;
};

// 2. ���ϴ� Ÿ���� ������ �ֵ��� �κ� Ư��ȭ �մϴ�.
// "int(int, double)" => int �� ������Ÿ�Ե� �� �и� �ؾ� �մϴ�.
template<typename R, typename A1, typename A2>
struct result<R(A1, A2)>
{
	using type = ? ;
};


template<typename T> void foo(T& a) 
{
	// T : int(int, double) �Դϴ�.
	typename result<T>::type n;  // int 

	std::cout << typeid(n).name() << std::endl;  
}


int main()
{
	foo(f);
}