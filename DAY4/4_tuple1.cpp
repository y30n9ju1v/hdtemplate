#include <iostream>

// Step 1. ���� ���� ���ø� ���
template<typename ... Types>
struct tuple
{
	static constexpr std::size_t N = 0; // �����ϴ� ����� ����
};

int main()
{
	tuple<> t0;

	tuple<char> t1;
	
	tuple<double, char> t2;
	
	tuple<int, double, char> t3;
}
