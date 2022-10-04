#include <iostream>
#include <source_location>

// C ��� : __FILE__, __LINE__ ���� ��ũ�� ���
// C++20 : std::source_location

template<typename T> 
T square(T a)
{
	std::source_location s = std::source_location::current();

	std::cout << s.function_name() << std::endl;
				// => VC  : ���� �Լ� �̸��� ���
				// => g++ : signature�� ������ �Լ� �̸� ���
				// C++ ǥ�� ���� : "������ ���� ��� ����� �ٸ��� �ִ�"
				//				��� �Ǿ� �ֽ��ϴ�.

	std::cout << s.file_name() << std::endl;

	return a * a;
}

int main()
{
	square<int>(3);	
	square<double>(3.3);
	square(3);
}

