#include <iostream>
#include "tuple.h"

int main()
{
//	tuple<			   char>				 // 2��° ���, 'A'����
//	tuple<     double, char>				 // 1��° ���, 3.4����
	tuple<int, double, char> t(1, 3.4, 'A'); // 1����

	std::cout << t.value << std::endl; // 1

	std::cout << static_cast<tuple<double, char>&>(t).value << std::endl; // 3.4 ������ �غ�����
	
	std::cout << static_cast<tuple<char>&>(t).value << std::endl; // 'A' ������ �غ�����.

	// �ٽ� 1. t �� N ��° ��Ҹ� ���ٷ���
	//        t �� "N ��° ��� Ŭ���� Ÿ��&" �� ĳ�����ؼ� value �� �����ϸ� �˴ϴ�.

	get<1>(t) = 9.9;
}
// get �� ���
template<int N, typename TP>
?
get(TP& tp)
{
	return static_cast<?>(tp).value;
}
