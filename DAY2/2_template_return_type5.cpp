#include <iostream>
#include <type_traits>

// 방법 3. 2개의 템플릿 인자

// 반환 타입 표기 2. decltype 키워드 사용

// decltype(표현식) : 컴파일러에게 표현식의 타입을 구해 달라는 의미.
// => 이경우, C++11 에서 새로 나온 "후위 반환 타입" 표기법을 사용해야 합니다.
// => 리턴 타입을 () 뒤쪽에 표기하는 표기법
template<typename T1, typename T2>
//decltype(a+b) add(const T1& a, const T2& b)	// error.

auto add(const T1& a, const T2& b) -> decltype(a + b) 
{
	return a + b;
}

int main()
{
	std::cout << add(3, 4) << std::endl;  
	std::cout << add(3, 4.3) << std::endl;


//	a = 10; // error. 변수를 선언전에 사용
//	int a = 0;
//	a = 20; // ok.. 변수를 선언후에 사용.
}



