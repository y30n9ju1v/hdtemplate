#include <iostream>

void fn(...) 
{ 
	std::cout << "..." << std::endl; 
}

// 아래 코드는 SFINAE 가 적용될까요 ? 에러일까요 ?
// => error
// => SFINAE 는 함수 signature(리턴 타입과 인자, 템플릿 인자) 에만 적용됩니다.
template<typename T> 
void fn(T a) 
{ 
	typename T::type n;  // int::type n;
}

int main()
{
	fn(3); // T=int
}
