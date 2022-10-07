#include <iostream>

int f(int a, double b) { return 0; }

template<typename T> struct result
{
	using type = T;
};

// 1�������� "���ڰ� 2���� �Լ�" �� ��밡���մϴ�
// ��� �Լ��� ��ȯ Ÿ���� ���Ҽ� �ְ� ������ ���ô�.

template<typename R, typename ... Types>
struct result<R(Types... )>
{
	using type = R;
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