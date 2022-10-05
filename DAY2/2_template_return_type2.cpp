#include <iostream>
#include <type_traits>

// ��� 2. �Ѱ��� ���ø� ����, std::type_identity ���
// => 1, 2 ��° ���ڰ� ���� Ÿ���� �Լ� ����
// => ��, Ÿ�� �߷��� 1��° ���ڷθ� �ϰڴٴ� �ǵ�

template<typename T>
T add(const T& a, const typename std::type_identity<T>::type & b)
{
	return a + b;
}

int main()
{
	std::cout << add(3, 4) << std::endl; // ok
	std::cout << add(3.1, 4.3) << std::endl; // ok

	std::cout << add(4.3, 3) << std::endl; // ok. double
	std::cout << add(3, 4.3) << std::endl; // ok. int

	std::cout << add<double>(3, 4.3) << std::endl; // ok
}



