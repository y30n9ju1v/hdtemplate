#include <iostream>
#include <type_traits>

// C++20 �������� "auto" �� �Լ� ���ڷ� ����Ҽ� �����ϴ�.
// C++20 ���ʹ�   "auto" �� �Լ� ���ڷ� ����Ҽ� �ֽ��ϴ�.

// �Ʒ� �ڵ�� "template_return_type6.cpp" �� add �� �Ϻ��� �����մϴ�.
// ��, C++20 ���� ����
// �Ʒ� �ڵ忡�� a, b �� ���� �ٸ� ���ø� �Դϴ�.
auto add(const auto& a, const auto & b)
{
	return a + b;
}

int main()
{
	std::cout << add(3, 4) << std::endl;
	std::cout << add(3, 4.3) << std::endl;


}



