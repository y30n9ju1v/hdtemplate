#include <iostream>

// fold expression ( C++17 )
// => parameter pack �ȿ� ��� ��ҿ� ���ؼ� ���� ������ �����ϴ� ǥ����

template<typename ... Types>
auto sum(Types... args)
{
	// args ���� ��� ��ҿ� ���� ���� ���ϰ� �ʹ�.	
	// args    : 1 , 2 , 3 , 4 , 5 , 2.4 , 4.3
	// ���ϴ°� : 1 + 2 + 3 + 4 + 5 + 2.4 + 4.3

//	return (args + ...); // pack �� ��� ��ҿ� ���� +�� ������ �޶�.
						 // args �� ��� ������ ����

	return (args + ... + 0); // ����ҿ� ������ "+ 0" �߰�
							// args �� �� ����. 
}


int main()
{
//	auto ret = sum(1, 2, 3, 4, 5, 2.4, 4.3);
	auto ret = sum();

	std::cout << ret << std::endl;
}
