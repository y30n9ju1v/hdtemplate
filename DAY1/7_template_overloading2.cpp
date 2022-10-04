#include <iostream>
#include <concepts>

// overloading1 ���� 
// => "int Ÿ��" �� "int�� �ƴ�Ÿ��" �� �ٸ��� ó���ϴ� �ڵ��Դϴ�.


// "�����迭" �� "�Ǽ��迭"�� �ٸ��� ó���ϰ� �ʹٸ�.. 
// => ������ �䱸 ���� �Դϴ�.
// => C++20 ���� : enable_if, true_type/false_type, if constexpr���ذ�
// => C++20 : concept ���� �ذ�
// ��� ���� ���� ���� ���

// �Ʒ� �ڵ�� "C++20" �Դϴ�. 
template<typename T> requires std::integral<T>
T square(T a)
{
	std::cout << "integral" << std::endl;
	return a * a;
}

template<typename T> requires (!std::integral<T>)
T square(T a)
{
	std::cout << "not integral" << std::endl;
	return a * a;
}

int main()
{
	square(3);  
	square(3.4);
	square(3.4f); // float �� �Ǽ� �迭�̹Ƿ� �Ʒ� ���� ���
	
}