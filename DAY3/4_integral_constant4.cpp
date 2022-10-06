#include <iostream>
#include <type_traits>

template<typename T> 
void fn(const T& arg)
{
	// T 가 포인터 인지에 따라 다른 알고리즘을 사용하고 싶다면
	// 방법 1. if 문으로 조사
	if ( std::is_pointer_v<T> ) // std::is_pointer<T>::value
	{
		// if ( false), 즉, 포인터가 아니라도 이 부분은 인스턴스화에 포함됨.
		// *arg = 10; // 그래서, 이런 코드는 작성할수 없습니다.
		// 그래서, 이방법은 권장 하지 않음.
	}
	else
	{
	}
	// 방법 2. if constexpr
	// => 위 코드에서 "if" 대신 "if constexpr" 사용
	// => 좋은 코드, 단, C++17 부터 가능

	// 방법 3. true_type, false_type 으로 오버로딩
	fn_imp(arg, std::is_pointer<T>());
}
template<typename T> void fn_imp(const T& arg, std::true_type) {} 
														// *arg = 10; 사용가능
template<typename T> void fn_imp(const T& arg, std::false_type) {}


// 방법 4. enable_if -> 오후
// 방법 5. concept   -> C++20, 오후. 
int main()
{

}