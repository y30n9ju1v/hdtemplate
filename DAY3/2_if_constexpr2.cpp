#include <iostream>
#include <type_traits>

template<typename T>
void printv(const T& value)
{
	// C++17. if constexpr
	// 조건식이 false 라면 해당 문장은 "템플릿 인스턴스화"에 포함안됨
	if constexpr (std::is_pointer_v<T>) 

		std::cout << value << " : " << *value << std::endl;
	else
		std::cout << value << std::endl;
}

int main()
{
	int n = 10;
	printv(&n); // ok
	printv(n);	// ok
}
/*
// T=int 일때 아래 처럼 생성됩니다.
void printv(const int& value)
{
	std::cout << value << std::endl;
}
// T=int* 일때 아래 처럼 생성됩니다.
void printv(const int*& value)
{
	std::cout << value << " : " << *value << std::endl;
}
*/
/*
// 참고 : is_pointer<T>::value 는 반드시 컴파일 시간에 값을 알수 있어야 합니다.
template<typename T> struct is_pointer
{
	// constexpr : 컴파일 시간에 사용하기 위해 필요!
	static constexpr  bool value = false;
};
// static 이 없으면 아래 처럼 객체를 생성후에 value 접근해야 합니다.
// 그런데, is_pointer 의 의도는 value 만 조사하면 되므로 객체 생성할 필요는
// 없습니다.
// is_pointer<T> ip;
// ip.value;
*/