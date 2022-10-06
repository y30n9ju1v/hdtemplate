#include <iostream>
#include <type_traits>

// 그런데.. 아래 코드는 왜.. 에러일까요 ?
template<typename T> 
void printv(const T& value)
{
	if ( std::is_pointer_v<T> )  // 또는 std::is_pointer<T>::value

		std::cout << value << " : " << *value << std::endl;
	else
		std::cout << value << std::endl;
}


int main()
{
	int n = 10;
	printv(&n); // ok
	printv(n);	// error
}