#include <iostream>
#include <type_traits>

// 방법 3. 2개의 템플릿 인자

// 반환 타입 표기 3. auto 만 표기
// => "return 표현식" 에서 "표현식"을 보고 타입을 결정해 달라는 의미
// => "return" 문장이 여러개 있다면 추론할수 없다.
//    이때는 -> decltype() 으로 반환 타입을 표기하면 된다.
template<typename T1, typename T2>
auto add(const T1& a, const T2& b)
{
	return a + b;

	//아래 처럼 return 문장이 여러개 라면 "auto" 로 추론할수 없습니다.
//	if (a == 3) return a;
//	return b;
}

int main()
{
	std::cout << add(3, 4) << std::endl;
	std::cout << add(3, 4.3) << std::endl;


}



