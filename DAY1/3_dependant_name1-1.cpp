// 이소스 복사해서 3_dependant_name1-1도 만들어 두세요.
// 77 page
struct Object
{
	using type = int;

	static constexpr int value = 10;

	template<typename T> struct rebind
	{
	};
};

template<typename T>
void foo(T obj)
{
	// ::value 는 값 입니다. typename 필요 없습니다.
	Object::value * 10;
	T::value * 10;			// <= value 는 타입이 아니므로
							//    typename 없어야합니다.

	Object::type* p1;	 // "dependant name" 아닙니다. typename필요없음
	typename T::type* p2;// "dependant name" 입니다. typename 필요
	//==========================================================
	// rebind 는 Object 안에 내포된 구조체 입니다.
	Object::rebind<int> r1; // ok. dependant name 아님.

//	T::rebind<int> r2;	// error
						// rebind 는 dependant name 이므로
						// typename 필요

//	typename T::rebind<int> r2;	// error
								// rebind 의 선언을 조사할수 없으므로
								// "rebind<" 표기에서 "<" 의 의미를
								// 알수 없기 때문에

	typename T::template rebind<int> r2; // ok.. rebind가 
								// 템플릿 임을 알려주어야 합니다.

	// 결론 : 위 코드에서 "typename", "template" 이 필요한 이유 알아두세요
}




int main()
{
	Object obj;
	foo(obj);
}