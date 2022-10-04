#include <iostream>
#include <source_location>

// C 언어 : __FILE__, __LINE__ 등의 매크로 사용
// C++20 : std::source_location

template<typename T> 
T square(T a)
{
	std::source_location s = std::source_location::current();

	std::cout << s.function_name() << std::endl;
				// => VC  : 현재 함수 이름만 출력
				// => g++ : signature를 포함한 함수 이름 출력
				// C++ 표준 문서 : "구현에 따라 출력 결과는 다를수 있다"
				//				라고 되어 있습니다.

	std::cout << s.file_name() << std::endl;

	return a * a;
}

int main()
{
	square<int>(3);	
	square<double>(3.3);
	square(3);
}

