#include <iostream>

template<typename T> void printv(const T& a)
{
	std::cout << a << std::endl;
}

template<typename ... Types> void foo(Types ... args)
{
	// args : 1, 2, 3

//	printv(args...);	// printv(1, 2, 3) �� �ǹ�.
						// printv() �� ���ڰ� �Ѱ� �̹Ƿ� error

//	printv(args)...;	// printv(1), printv(2), printv(3) �� �ǵ�.
						// ������. error

	// �ٽ� 1. pack expansion �� �Ҽ� �ִ� ��ġ�� ������ �ֽ��ϴ�.
	// 1. �Լ� ȣ���� ()  : goo(args...)
	// 2. {} �ʱ�ȭ ����  : int x[] = {args...};
	// 3. ���ø� ���� <>  : tuple<Types...>  
	// 
//	args...;				// error
//	int x[] = { args... };	// ok.

	// args �� ��� ������ printv �� ������ ����
	// C++11 ��â�⿡ ����ߴ� ���

	int dummy[] = { 0, (printv(args), 0)... };
			   // { (printv(1), 0), (printv(2), 0), (printv(3), 0) };
}

int main()
{
	foo(1, 2, 3);
	foo();
}

