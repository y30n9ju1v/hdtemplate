#include <iostream>
#include <type_traits>

// ��� 3. 2���� ���ø� ����
// ��ȯ Ÿ�� ǥ�� 1. ����ڰ� �����Ѵ�.
// => �Ʒ� ó�� �����, "T1, T2" �� �Լ� ���ڷ� �߷� ������
// => R�� �����Ϸ��� �߷� �Ҽ� �����ϴ�. �ݵ�� �����ؾ� �մϴ�.
template<typename R, typename T1, typename T2>
R add(const T1 & a, const T2 & b)
{
	return a + b;
}

int main()
{
	std::cout << add<int>(3, 4) << std::endl;   // int, int
	std::cout << add<double>(3, 4.3) << std::endl; // int, double
}



