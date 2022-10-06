#include <iostream>
#include <type_traits>

// �׷���.. �Ʒ� �ڵ�� ��.. �����ϱ�� ?
template<typename T> 
void printv(const T& value)
{
	// if �� ����ð� ��� �Դϴ�.
	// ���ǽ��� ������ �ð��� "false" �� �����Ǿ

	// ������� �ʰ� �Ǵ� ���嵵 "�ν��Ͻ�ȭ���� ����" �˴ϴ�.

	if ( std::is_pointer_v<T> )  // �Ǵ� std::is_pointer<T>::value

		std::cout << value << " : " << *value << std::endl;
	else
		std::cout << value << std::endl;
}

// T=int �϶� �Ʒ� ó�� �����˴ϴ�.
void printv(const int& value)
{
	if (false) 
		std::cout << value << " : " << *value << std::endl;
									// => *value ���� ����!
	else
		std::cout << value << std::endl;
}
// T=int* �϶� �Ʒ� ó�� �����˴ϴ�.
void printv(const int*& value)
{
	if (true)
		std::cout << value << " : " << *value << std::endl;
										// => *value �� ���� �ƴ�
	else
		std::cout << value << std::endl;
}


int main()
{
	int n = 10;
	printv(&n); // ok
	printv(n);	// error
}