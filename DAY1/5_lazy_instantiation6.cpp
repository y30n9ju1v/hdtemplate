// 아래 코드는 에러가 있을까요 ?
template<typename T> 
void fn(T value)
{
	// if : 실행시간 조건문
	//      컴파일 할때 조건이 "false"로 결정되어도
	//      "*value = 10" 은 인스턴스화에 포함됩니다.
//	if ( false )
//		*value = 10;

	// if constexpr : 컴파일 시간 조건문 ( C++17 부터 지원)
	//				  조건이 false 로 결정되면
	//				  해당 문장은 "인스턴스화에 포함 안됨"
	if constexpr (false)
		*value = 10;
}

int main()
{
	int n = 10;
	fn(n);
}
