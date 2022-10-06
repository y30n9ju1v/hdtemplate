// printv4 
#include <iostream>
#include <type_traits>

// ��� 4. requires clauses ��� - C++20 
template<typename T> requires std::is_pointer_v<T>
void printv(const T& value)
{
	std::cout << value << " : " << *value << std::endl;
}

template<typename T> requires (!std::is_pointer_v<T>)
void printv(const T& value)
{
	std::cout << value << std::endl;
}

int main()
{
	int n = 10;
	printv(&n);
	printv(n);
}