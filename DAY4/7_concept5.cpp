#include <iostream>
#include <algorithm>
#include <concepts>
#include <vector>

// std::find �� ��� ���ڰ� ���ø� �Դϴ�.
// �ݺ��� : ���纻�� �����Ǿ ������� ���� �����ϴ�. "������ �޴°��� ��Ģ"
template<typename Iter, typename T>
Iter find(Iter first, Iter last, const T& value)
{
	std::cout << "�� �˻� ����" << std::endl;

	return first;
}
// ���� �̸� find �� �ٽ� �Լ� �������� ����� ����� C++98 ���� �������ϴ�.
// C++11 enable_if �� ������� ���������� �Ϻ����� �ʽ��ϴ�.
template<typename Iter, typename T>
Iter find(Iter first, Iter last, T func)
{
	std::cout << "�Լ� ����" << std::endl;

	return first;
}

int main()
{
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };
	
	// find    : �־��� �������� �� �˻�
	// find_if : �־��� �������� ���� �˻�(������ ���ڷ� ȣ�Ⱑ���� ��ü(callable object) ����)
	auto p1 = std::find(   std::begin(v), std::end(v), 3);
//	auto p2 = std::find_if(std::begin(v), std::end(v), [](int a) { return a % 3 == 0; } );

	// find_if ����, �׳� find() �� ����� �� ������ �ʾ�����?
	auto p2 = std::find(std::begin(v), std::end(v), [](int a) { return a % 3 == 0; });


}