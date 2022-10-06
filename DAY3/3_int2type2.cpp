// if constexpr1.cpp 복사 해서 주석 지워 보세요
#include <iostream>
#include <type_traits>

// 함수 오버로딩에서 "어떤 함수를 선택할지는 컴파일 시간에 결정"
// => 사용되지 않은 함수가 템플릿 이라면 인스턴스화 안됨.

template<typename T> void printv_imp(const T& value, YES)
{
	std::cout << value << " : " << *value << std::endl;
}

template<typename T> void printv_imp(const T& value, NO)
{
	std::cout << value << std::endl;
}

template<typename T>
void printv(const T& value)
{
	// 조건(T가 포인터 인가) 에 따라 함수 오버로딩
	printv_imp(value, std::is_pointer_v<T>  );
						// T가 포인터 이면 : true(1)
						// T가 포인터아니면 : false(0)
						// => 함수 오버로딩은 "인자의 갯수나 타입이 달라야 한다"
						// => 그런데, 0, 1 은 같은 타입이다.

}



int main()
{
	int n = 10;
	printv(n);	// error.
}