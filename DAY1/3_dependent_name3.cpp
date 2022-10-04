// 3_dependent_name3
#include <iostream>

template<typename T>
struct Object
{
	template<typename U>
	static void mf()
	{
		std::cout << "template mf" << std::endl;
	}
};

// template specialization 문법
template<>
struct Object<int>
{
	static void mf()
	{
		std::cout << "mf" << std::endl;
	}
};
template<>
struct Object<double>
{
	static constexpr int mf = 0;
};
int main()
{
	// Object<T>에서 어떤 T가 와도 object template을 
	// 보면 mf가  template이라는걸 알 수 있지 않나요?
	// => template specialization 문법 이 있기 때문에
	// => 템플릿 인자에 따라서 "mf" 의 의미가 달라질수 있습니다.   
	Object<int>::mf();
	Object<double>::mf;
	Object<char>::mf<int>();
}