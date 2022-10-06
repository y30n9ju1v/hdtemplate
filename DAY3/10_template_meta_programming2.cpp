#include <iostream>

// C++11 constexpr  �Լ�
// => ���� ���� ������ �ð��� �˼� �ְ�, �Լ� ȣ���ϴ� ����
// => ������ �ð��� ����� �˾ƾ� �ϴ� ���̶��
// => ������ �ð��� �����ش޶�.

constexpr std::size_t factorial(std::size_t n)
{
	return n == 1 ? 1 : n * factorial(n-1);
}

int main()
{
	int x[ factorial(5) ]; // �迭�� ũ��� ������ �ð��� �˾ƾ� �մϴ�.

	int n = 5;
	int x1[factorial(n)];	// error. n�� ���� �̹Ƿ� 
							// ������ �ð� ���� �ȵ�

	int ret = factorial(n); // ȣ���ϴ� ���� ������ �ð��� �䱸���� �ʴ´�.
							// ����ð� ȣ��
}