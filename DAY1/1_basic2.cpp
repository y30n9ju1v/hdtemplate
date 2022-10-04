// 7 page : typename, class, auto

// 타입 paramter 를 표기하는 방법
// 
// 1. class - C++ 언어 처음에 사용하던 방식
template<class T> 
T square1(T a)
{
	return a * a;
}

// 2. typename 
template<typename T>
T square2(T a)
{
	return a * a;
}

// 3. C++20 "auto" 사용가능
//    => 아래 코드가 템플릿 입니다.
//    => 위 square1, square2 와 완벽히 동일한 코드입니다.
auto square3(auto a)  
{
	return a * a;
}

int main()
{
	// 핵심 2. 용어 정리
	// int : template argument(parameter) - 컴파일 시간에 전달
	// 3   : function argument(parameter) - 실행   시간에 전달
	square3<int>(3);
}