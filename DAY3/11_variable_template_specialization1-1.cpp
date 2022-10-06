#include <iostream>

template<typename T>
constexpr int made_year = -1;

// ���̺귯���� �پ��� Ŭ������ �ִµ�, ���� ����� ������ ���������� �ϰ� �ʹ�.
// => �� Ŭ���� �����ڰ� "made_year" variable template �� Ư��ȭ �ϱ�� ���
class AAA {};
template<> constexpr int made_year<AAA> = 2002;


class BBB {};
template<> constexpr int made_year<BBB> = 2020;

int main()
{
	std::cout << made_year<AAA> << std::endl;
	std::cout << made_year<BBB> << std::endl;
	std::cout << made_year<int> << std::endl;

}



