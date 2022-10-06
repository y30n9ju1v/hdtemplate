// if constexpr1.cpp 복사 해서 주석 지워 보세요
#include <iostream>
#include <type_traits>

// 아래 "pointer template" 은
// 1. 템플릿 자체는 에러가 없다.
// 2. T=int 일때 인스턴스화가 되면 에러 이다.(T=int* 일때는 에러아님)
// 3. T=int 일때 인스턴스화가 되지 않으면 에러 아니다.

template<typename T> void pointer(const T& value)
{
	std::cout << value << " : " << *value << std::endl;
}
template<typename T> void not_pointer(const T& value)
{
	std::cout << value << std::endl;
}

template<typename T>
void printv(const T& value)
{
	// 의도 : T = int 라면 if ( false ) 이고,  pointer(v) 를 사용되지 않는다.
	//      따라서, 인스턴스화 되지 않을것이다 !!
	if (std::is_pointer_v<T>)
		pointer(v);
	else
		not_pointer(v);

	// 실패!!
	// if 는 실행시간 조건문이므로 조건식의 결과에 상관없이
	// pointer(v), not_pointer(v) 모두 인스턴스화가 된다.!!!
	// T=int 일때 pointer(v)가 인스턴스화 되므로 에러!!

	// 의도대로 하려면 "if" 대신 "if constexpr(C++17)" 필요
}



int main()
{
	int n = 10;
	printv(n);	// error.
}