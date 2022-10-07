#include <iostream>
#include <type_traits>
#include <vector>
#include <iterator>
#include <concepts>


// �ٽ� 1. concept ����� ��� �˾� �μ���.
template<typename T>
concept container = requires(T & c)
{
	std::begin(c);
	std::end(c);
};

// �ٽ� 2. template require clauses
// => ������ �����Ҷ��� template �� ����ϰڴ�.
// => ������ ������ �ð��� �����Ǵ� "bool��" �̸� ��͵� ����
// => ��κ� concept �� type traits ���

// # ������ ���� concept ���
template<typename T> requires container<T> 
void fn(T& c) 
{
	std::cout << "container" << std::endl;
}

// # C++ 20 ǥ�ؿ� �̹� ������� ���� concept �� �ֽ��ϴ�.(100����)
template<typename T> requires std::input_iterator<T>
void fn(T& c)
{
	std::cout << "iterator" << std::endl;
}

// # C++11 type_traits �� ��밡��
template<typename T> requires std::is_integral_v<T>
void fn(T& c)
{
	std::cout << "integer" << std::endl;
}

int main()
{
	int n = 10;
	std::vector<int> v = { 1,2,3 };
	
	auto p = v.begin();

	fn(v); // container
	fn(p); // iterator
	fn(n); // integer
}