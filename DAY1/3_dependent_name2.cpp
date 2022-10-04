template<typename T> 
struct Object
{
	using type = int;

	template<typename U> 
	static void mf() {	}
};
template<typename T>
void foo()
{
	Object<int>::type t1;	// T에 의존하지 않음. typename 필요 없음
							// ok.
							// 
	// T::type t2;			// 이 표기도 dependant name
	//Object<T>::type t2;	// 이 표기도 dependant name
							// typename 있어야 합니다.
	typename Object<T>::type t2; // ok
	//==============================================

	Object<int>::mf<double>();	// ok
								// "mf" 는 dependant name 아닙니다.

//	Object<T>::mf<double>();	// error
	
	// 위 코드 에러나지 않게 해보세요.
	Object<T>::template mf<double>();
				// => mf 는 타입의 이름은 아닙니다. typename 필요없음
				// => 하지만 "템플릿" 이었음을 알려주어야 합니다.
	//=================================
	Object<int> o1;	// 이렇게 하면 컴파일러는 o1 객체의 타입을 
					// 명확히 알게 됩니다.
					// 따라서, 모든 멤버에 대해 정확히 알고 있습니다.
					// "mf"가 템플릿 임을 알고 있습니다.

	Object<T>   o2;	// T 에 따라서, "mf"의 정체는 달라질수 있습니다.

	o1.mf<int>();	// ok. 컴파일러는 이순간, "mf" 가 템플릿 이라는 것을 
					// 알고 있습니다.
//	o2.mf<int>();	// error. 에러나지 않게 해보세요.

	o2.template mf<int>(); // ".template" 이라는 표기법
							// "->template" 표기법도 있습니다.
							// 
	// 핵심 1. dependant name 이라는 용어 알아 두세요
	//		=> T에 의존해서 꺼내는 이름
	// 
	// 2. dependant name 사용시 
	//    "typename", "template"을 적절하게 표기해야 합니다.

	// C++20, C++23 부터는 "컴파일 방식이 많이 개선됩니다"
	// "typename", "template"을 표기하지 않아도 되는 경우가 있습니다.
	// 하지만, C++17  까지는 꼭 표기해 주세요..
}




int main()
{
	foo<int>();
}