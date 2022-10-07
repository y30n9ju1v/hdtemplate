#include <tuple>
#include <vector>
#include <iostream>

int main()
{
	// vector : "������ Ÿ��" �� ������ ����
	std::vector<int> v{1,2,3};

	
	// pair : "���� �ٸ� Ÿ��" �� "2��" ����
	std::pair<int, double> p1(1, 3.4);

	// pair �� 2�� �̻� ������ �����մϴ�.
	// => ������ ������ ���Դϴ�.
	std::pair<int, std::pair<double, char>> p2(1, { 3.4, 'A' } );


	// C++11 �� tuple : "���� �ٸ� Ÿ��"�� "N��" ����

	std::tuple<int, double, char> t(3, 3.4, 'A');

	// tuple �� ��� ���� : std::get ���
	std::get<1>(t) = 9.9;

	std::cout << std::get<0>(t) << std::endl; // 3
	std::cout << std::get<1>(t) << std::endl; // 9.9
}
