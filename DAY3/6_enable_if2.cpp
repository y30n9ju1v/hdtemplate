#include <iostream>
#include <type_traits>

// �ִ� ������� ���ϴ� �Լ��� ������ ���ô�.
template<typename T> T gcd(T a, T b)
{
	// ���� ���ø��� �����϶��� ����ϰ� �غ��ô�.
	static_assert( std::is_integral_v<T>, "error, T is not integer");

	return 0;// ������ ����.. 
}
double gcd(double a, double b)
{
	std::cout << "double version" << std::endl;
	return 0;
}
int main()
{
	gcd(6, 9);
	gcd(3.1,  5.4);		// double ���� ���.
	gcd(3.1f, 5.4f);	// T ���� ���
						// �׷���, ���� Ÿ���� �ƴϹǷ� ������ ����

	// �ٽ�
	// static_assert : ������ �������� ������ error!!
	// 
	// => ������ �������� ������, �������� ����, �ĺ������� �����Ҽ� ������ ?
	// => ������ �ƴѰ��, double �� ����Ҽ� �ֵ���
}