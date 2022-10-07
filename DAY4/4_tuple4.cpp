#include <iostream>

// �ϼ��� �ڵ� ����

template<typename ... Types>
struct tuple
{
	static constexpr std::size_t N = 0;
};

template<typename T, typename ... Types>
struct tuple<T, Types...> : public tuple<Types...>
{
	using base = tuple<Types...>;
	T value;
	tuple() = default;
	tuple(const T& v, const Types& ... args)
		: value(v), base(args...) {}
	static constexpr std::size_t N = base::N + 1;
};
int main()
{
	tuple<> t0;									// 3��° ���
	tuple<             char> t1;				// 2��° ���, char   �� �Ѱ� ����
	tuple<     double, char> t2;				// 1��° ���, double �� �Ѱ� ����
	tuple<int, double, char> t3(5, 3.4, 'A');	// int �� �Ѱ� ����
}

// tuple.h ���弼��.. �� tuple 2�� ���� �� ��������