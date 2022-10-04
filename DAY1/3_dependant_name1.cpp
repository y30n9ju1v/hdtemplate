// 이소스 복사해서 3_dependant_name1-1도 만들어 두세요.
// 77 page
struct Object
{
	using type = int;
	static constexpr int value = 10;
};

template<typename T> 
void foo(T obj)
{
	// 아래 2줄에서 "*"의 의미를 생각해 보세요.
	// "클래스이름::이름" 으로 표기할때 "이름" 의 의미는
	// 1. 값   : static 멤버데이타, enum 상수등
	// 2. 타입 : typedef, using 같은 것.

	Object::value * 10;    // 곱하기의 의미
	Object::type  * p1;	   // p1 이라는 포인터 변수의 선언

	// 핵심 1. dependant name
	//      => 템플릿 인자 T에 의존해서 꺼내는 이름
	//      => 컴파일러는 무조건 이름의 의미를 "값"으로 해석합니다.

	T::value * 10;    
//	T::type  * p2;	// type 을 값으로 해석하므로 * 를 곱하기로 해석
					// "p2"라는 변수가 없다고 에러.. 

	typename T::type* p2; // ::type 을 "값"이 아닌 "타입" 이름으로 
						  // 해석해 달라.
}





int main()
{
	Object obj;
	foo(obj);
}