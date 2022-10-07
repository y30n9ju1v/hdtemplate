#include <iostream>

// Step 2. ��� �Ѱ� �����ϱ� 

template<typename ... Types>
struct tuple
{
	static constexpr std::size_t N = 0; 
};

// tuple �� Ÿ�� ���ڰ� �ּ� �Ѱ� �̻� �ִ� ����� �κ� Ư��ȭ
template<typename T, typename ... Types>
struct tuple<T, Types...>
{
	T value;

	tuple() = default;
	tuple(const T& v) : value(v) {}

	static constexpr std::size_t N = 1;
};

int main()
{
	tuple<> t0;
	tuple<char> t1;					// char   �� �Ѱ� ����
	tuple<double, char> t2;			// double �� �Ѱ� ����

	tuple<int, double, char> t3(5); // int �� �Ѱ� ����
}
