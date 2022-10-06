#include <iostream>

template<typename T> struct remove_all_pointer
{
	using type = T;
};

template<typename T> struct remove_all_pointer<T*>
{
	// 재귀를 사용해서 포인터를 한개씩 제거
	// => 재귀의 종료는 "마지막 단계에서 T=int" 이므로 포인터가 아니다.
	//    primary template 사용

	using type = typename remove_all_pointer<T>::type;

	// 참고 : C++표준에는 "remove_all_pointer" 는 없습니다.
};


int main()
{
//	std::remove_pointer<int***>::type n; // int**

	remove_all_pointer<int***>::type n; // int

	std::cout << typeid(n).name() << std::endl;
}