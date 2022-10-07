#include <iostream>
#include <vector>
#include <type_traits>

// Container 라는 개념(Concept)을 설계해 봅시다.
template<typename T>
concept container = requires(T c)
{
	c.begin();
	c.end();
};

template<typename T> void check(T& c)
{
	std::cout << container<T> << std::endl;
}



int main()
{
	int n = 0;
	std::vector<int> v = { 1,2,3 };
	int x[3] = { 1,2,3 };

	check(n);
	check(v);
	check(x);
}