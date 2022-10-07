#include <iostream>

// 방법 2. recursive 유사 코드
// 
// => 모두 가변인자로 하지 말고, 1번째 인자는 독립된 변수로 받습니다.
// => 아래 코드는 재귀 호출은 아닙니다.
//    "foo(3개인자)" => "foo(2개인자)" => "foo(1개인자)" => "foo()"

// 재귀의 종료
// C++17 이전에는 아래 함수 제공
void foo() {} // 아래 코드의 재귀를 종료하기 위해

template<typename T, typename ... Types>
void foo(T value, Types ... args)
{
	std::cout << value << std::endl;	// 1번째 인자는 이름이 있으므로
										// 접근 가능

//	foo(args...);	// foo(3.4, 'A')
					// foo('A')
					// foo()

	// C++17 이후라면.. 아래 처럼 만드세요
	// => "if constexpr" 를 사용하려면 C++17 필요
	if constexpr (sizeof...(args) > 0)
		foo(args...);
}

// 나중에 이 코드를 "godbolt.org" 에 넣어서 생성된 코드 꼭 확인해 보세요.
// => 위 foo 함수 구현이 간단하면 inline 치환하면
//    모든 함수가 치환 되므로, 실제 생성된 함수는 없습니다!!!!
// => godbolt 에서 보려면 최적화 옵션(-O2) 필요 합니다.


int main()
{
	foo(1, 3.4, 'A'); 
}





