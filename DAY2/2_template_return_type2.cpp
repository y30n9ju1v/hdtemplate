#include <iostream>
#include <type_traits>

// 방법 2. 한개의 템플릿 인자, std::type_identity 사용
// => 1, 2 번째 인자가 같은 타입의 함수 생성
// => 단, 타입 추론은 1번째 인자로만 하겠다는 의도

template<typename T>
T add(const T& a, const typename std::type_identity<T>::type & b)
{
	return a + b;
}

int main()
{
	std::cout << add(3, 4) << std::endl; // ok
	std::cout << add(3.1, 4.3) << std::endl; // ok

	std::cout << add(4.3, 3) << std::endl; // ok. double
	std::cout << add(3, 4.3) << std::endl; // ok. int

	std::cout << add<double>(3, 4.3) << std::endl; // ok
}



