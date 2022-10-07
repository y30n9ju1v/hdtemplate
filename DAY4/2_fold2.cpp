#include <iostream>

// fold expression
// => () �� �ݵ�� �־�� �մϴ�.
// => 4�� ������ �ֽ��ϴ�.
// => '+' ��ġ�� ��� ���� �����ڵ� �ü� �ֽ��ϴ�.
// => '0' ��ġ�� ��� ��(����)�� �ü� �ֽ��ϴ�(init value ��� �մϴ�.)

// (args + ...)	 // E1+(E2+(E3+(E4+E5)))		 unary  right fold
// (args + ... + 0) // E1+(E2+(E3+(E4+(E5+0))))  binary right fold

// (... + args)	 // (((E1+E2)+E3)+E4)+E5		 unary  left fold
// (0 + ... + args) // ((((0+E1)+E2)+E3)+E4)+E5  binary left fold


template<typename ... Types>
auto sum(Types... args)
{
	return (args + ... + 0); 
}

int main()
{
	auto ret = sum(1, 2, 3, 4, 5);

	std::cout << ret << std::endl;
}
