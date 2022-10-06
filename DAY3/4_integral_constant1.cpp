#include <iostream>

template<int N> struct int2type
{
	enum { value = N };
};

// C++11 ���鶧 "int2type" �� ���� ���� ���Ѽ� C++11 ǥ�ؿ� �߰��߽��ϴ�.
// int �� �ƴ϶� ��� ������ Ÿ���� ��� ���� Ÿ��ȭ �Ҽ� �ֵ��� �Ʒ�ó�� ����
// => ��, �Ǽ��� C++20 ���� �����ǹǷ� C++11 ���鶧�� ������� ����

template<typename T, T N> struct integral_constant
{
	static constexpr T value = N;
};

int main()
{
	// �Ʒ� �ڵ�� 0, 1�� �ٸ� Ÿ������ �����
	int2type<0> t1;
	int2type<1> t2; 

	// �Ʒ� �ڵ�� c1, c2, c3 �� ��� �ٸ� Ÿ��
	integral_constant<int, 0> c1;
	integral_constant<int, 1> c2;
	integral_constant<short, 1> c3;

	// true/false �� ��/������ ��Ÿ���� �� �Դϴ�. ���� Ÿ�� �Դϴ�.
	// b1, b2�� �ٸ� Ÿ�� �Դϴ�.
	integral_constant<bool, true>  b1;
	integral_constant<bool, false> b2;

	// true_type/false_type �� ��/������ ��Ÿ���� Ÿ�� �Դϴ�.
	// ���� �ٸ� Ÿ��
	using true_type  = integral_constant<bool, true>;
	using false_type = integral_constant<bool, false>;
}