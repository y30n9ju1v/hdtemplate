// 3_int2type0.cpp

template<typename T>
void printv(const T& value)
{
	if (std::is_pointer_v<T>)
		std::cout << value << " : " << *value << std::endl;
	else
		std::cout << value << std::endl;
}
// 위 코드는 에러 입니다.
// 위 코드의 문제를 해결하는 해결책은 4가지가 있습니다. => 모두 중요!!!
// 
// 1. int2type, integral_constant - C++11 기술
// 
// 2. enable_if - C++11 기술
// 
// 3. if constexpr - C++17 기술
// 
// 4. concept - C++20 기술
 