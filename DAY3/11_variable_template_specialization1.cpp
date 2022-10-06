#include <iostream>


// �Ϲ� ���� ����(���)
constexpr int made_year1 = -1;


// C++17, variable template
template<typename T>
constexpr int made_year2 = -1;

int main()
{
	std::cout << made_year1 << std::endl;  // -1

	std::cout << made_year2 << std::endl;	// error. Ÿ�����ڰ� ����.

	std::cout << made_year2<int>    << std::endl;	// ok. -1
	std::cout << made_year2<double> << std::endl;	// ok. -1
	
}



