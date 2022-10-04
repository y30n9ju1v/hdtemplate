// 3_dependent_name3
#include <iostream>

template<typename T>
struct Object
{
	template<typename U>
	static void mf()
	{
		std::cout << "template mf" << std::endl;
	}
};

// template specialization ����
template<>
struct Object<int>
{
	static void mf()
	{
		std::cout << "mf" << std::endl;
	}
};
template<>
struct Object<double>
{
	static constexpr int mf = 0;
};
int main()
{
	// Object<T>���� � T�� �͵� object template�� 
	// ���� mf��  template�̶�°� �� �� ���� �ʳ���?
	// => template specialization ���� �� �ֱ� ������
	// => ���ø� ���ڿ� ���� "mf" �� �ǹ̰� �޶����� �ֽ��ϴ�.   
	Object<int>::mf();
	Object<double>::mf;
	Object<char>::mf<int>();
}