#include <iostream>

template<std::size_t N> struct Factorial
{
	enum { value = N * Factorial<N-1>::value };
};

// ��͸� �����ϱ� ���� N=1 �� ����� Ư��ȭ
template<> struct Factorial<1>
{
	enum { value = 1 };
};

int main()
{
	// �Ʒ� ������ ��� ������ ������.
	// => 5! �� "������ �ð�"�� �����Ѱ��Դϴ�.
	int ret = Factorial<5>::value;
				// 5 * F<4>::value
				//     4 * F<3>::value
				//		   3 * F<2>::value
				//		       2 * F<1>::value
				//                 1
	
	std::cout << ret << std::endl;

	// template meta programming
	// => ���ø� ����� ����ؼ� "������ ������ ������ �ð�"�� �����ϴ� ��

	// ��, ���ø� ���ڴ� ������ ����Ҽ� �����ϴ�.
	int n = 5;
//	int ret2 = Factorial<n>::value; // error
	int ret3 = Factorial<5>::value; // ok


	int n1 = 0b1010; // C++11 ���ʹ� ������ �����մϴ�.
					 // C++11 �������� ������ �ȵ˴ϴ�.
	int n2 = binary<1010>::value; // C++11 ������ �� ���ø� ����
									// ����ϰ� �߽��ϴ�.

	std::cout << n2 << std::endl; // 9..  binary  ������ ������
									// ���۰˻��ϸ� ���ɴϴ�.
									
}