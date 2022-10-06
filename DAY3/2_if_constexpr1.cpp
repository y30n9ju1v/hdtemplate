#include <iostream>
#include <type_traits>

// 그런데.. 아래 코드는 왜.. 에러일까요 ?
template<typename T> 
void printv(const T& value)
{
	// if 는 실행시간 제어문 입니다.
	// 조건식이 컴파일 시간에 "false" 로 결정되어서

	// 실행되지 않게 되는 문장도 "인스턴스화에는 포함" 됩니다.

	if ( std::is_pointer_v<T> )  // 또는 std::is_pointer<T>::value

		std::cout << value << " : " << *value << std::endl;
	else
		std::cout << value << std::endl;
}

// T=int 일때 아래 처럼 생성됩니다.
void printv(const int& value)
{
	if (false) 
		std::cout << value << " : " << *value << std::endl;
									// => *value 에서 에러!
	else
		std::cout << value << std::endl;
}
// T=int* 일때 아래 처럼 생성됩니다.
void printv(const int*& value)
{
	if (true)
		std::cout << value << " : " << *value << std::endl;
										// => *value 는 에러 아님
	else
		std::cout << value << std::endl;
}


int main()
{
	int n = 10;
	printv(&n); // ok
	printv(n);	// error
}