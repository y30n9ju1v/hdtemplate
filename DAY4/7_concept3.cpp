#include <concepts>
#include <iostream>
#include <vector>


template<typename T>
concept container = requires(T & c)
{
	std::begin(c);
	std::end(c);
};

// requires clauses �� syntax sugar

// 1. �⺻ ���.
template<typename T> requires container<T>
void f1(T a) 
{
	std::cout << "f1" << std::endl;
}

// 2. require �� �Լ� () �ڿ� �־ �˴ϴ�.
template<typename T> 
void f2(T a) requires container<T>
{
	std::cout << "f2" << std::endl;
}

// 3. typename �ڸ��� concept �̸� �־ �˴ϴ�.
//    ��, type traits�� �ȵ˴ϴ�.
template< container T> 
void f3(T a)
{
	std::cout << "f3" << std::endl;
}

// 4. template ��� �˴ϴ�. 
void f4(container auto a)  // �ǹ� : container �� �����ϴ� ������ Ÿ��
{
	std::cout << "f4" << std::endl;
}

// 5. 
void f5(auto a)  // ���� ���� ��� Ÿ��!!  ��, �Ϲ� ���ø�
{
	std::cout << "f5" << std::endl;
}

int main()
{
	std::vector<int> v = { 1,2,3 };

	f1(v);
	f2(v);
	f3(v);
	f4(v);
	f5(v);
}