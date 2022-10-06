#include <iostream>
#include <type_traits>


// enable_if< ����, T >::type 
// ������ ���̸�   : ���� ����� "T"
// ������ �����̸� : ::type �� ����!

// �Ʒ� �ڵ��� �ǹ�
// T�� Ÿ���� ���� �迭�̸� ��ȯ Ÿ���� "T"
// T�� Ÿ���� ���� �迭�̾ƴϸ� "gcd ���ø�" ������(SFINAE ��Ģ)
// => �ٸ� ����(gcd(double)) ��밡��. 

// "T�� �����϶��� ����ϰڴ�" �� ��
template<typename T> 
//typename std::enable_if< std::is_integral_v<T>, T>::type 

std::enable_if_t< std::is_integral_v<T>, T>

gcd(T a, T b)
{
	return 0;
}

double gcd(double a, double b)
{
	std::cout << "double version" << std::endl;
	return 0;
}
int main()
{
	gcd(6, 9);
	gcd(3.1, 5.4);		
	gcd(3.1f, 5.4f);	

}