#include <iostream>
#include <tuple>

template<typename ... Types> void foo(Types ... args)
{
	// args �� �ִ� ��� ��Ҹ� ������ �ʹٸ�
	// 
	// args �ȿ� �ִ� 2��° ���� ��� �ʹ�.
	// => �ѹ��� �Ҽ� �ִ� ����� �����ϴ�.

	// �Ʒ� 3�� ��� �߿� �Ѱ��� ����ؾ� �մϴ�.
	// 1. pack expansion		- C++11
	// 2. recursive �� ������ ��� - C++11
	// 3. fold expression - C++17

	// ��� 1. pack expansion

	// 1. ��� ��Ұ� ���� Ÿ���̸� �迭 �Ǵ� std::initializer_list �� ��Ƽ� ����ϼ���

	//	int x[] = { args... };	// int x[] = {1,2,3}
								// args �� ��� �ִ� ��� error

	std::initializer_list<int> x = { args... }; // ok
									// args �� ��� �־ �˴ϴ�.
	// x �� ��� ������ �ݺ��ڷ� �ϸ� �˴ϴ�.
	auto p1 = x.begin();


	// 2. ����� Ÿ���� �ٸ� ���� tuple �� ������ �ֽ��ϴ�.
	std::tuple<Types...> tp(args...);

	std::cout << std::get<0>(tp) << std::endl; // 1��° ��� ����

}

int main()
{
	foo(1, 2, 3);
}

