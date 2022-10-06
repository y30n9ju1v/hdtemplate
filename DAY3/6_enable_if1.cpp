// 6_enable_if1.cpp

// 아래 enable_if 는 "C++11 표준" 에 이미 있는 코드 입니다.

template<bool, typename T = void > struct enable_if
{
//	typedef  T type; // C++11 이전 스타일
	using type = T;  // C++11 이후 스타일
};

template<typename T> struct enable_if<false, T> 
{
	// 핵심 : 이 버전에는 "type" 이 없다는 점. 
};
// enable_if 사용법 : enable_if<bool상수, 타입>

int main()
{
	// 아래 코드에서 각 변수의 타입은 ?
	enable_if<true, int>::type  n1; // int n1
	enable_if<true>::type       n2; // void n2 인데. 
									// void 변수는 만들수 없기 때문에 error
	enable_if<false, int>::type n3; // error
									// "::type" 이 없다.

	// 아래 정리 외우세요
//	enable_if<true, 타입>::type => "타입" 입니다.
//	enable_if<true>::type      => "void" 입니다.
//	enable_if<false, 타입>::type  => error. "::type" 없습니다.
}