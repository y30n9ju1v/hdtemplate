#include <iostream>

// fold expression ( C++17 )
// => parameter pack 안에 모든 요소에 대해서 이항 연산을 수행하는 표현식

template<typename ... Types>
auto sum(Types... args)
{
	// args 안의 모든 요소에 대해 합을 구하고 싶다.	
	// args    : 1 , 2 , 3 , 4 , 5 , 2.4 , 4.3
	// 원하는것 : 1 + 2 + 3 + 4 + 5 + 2.4 + 4.3

//	return (args + ...); // pack 의 모든 요소에 대해 +를 적용해 달라.
						 // args 가 비어 있으면 에러

	return (args + ... + 0); // 모든요소에 덧셈후 "+ 0" 추가
							// args 가 비어도 가능. 
}


int main()
{
//	auto ret = sum(1, 2, 3, 4, 5, 2.4, 4.3);
	auto ret = sum();

	std::cout << ret << std::endl;
}
