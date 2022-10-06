#include <iostream>

template<typename T> struct remove_pointer
{
	using type = T; 
};
template<typename T> struct remove_pointer<T*>
{
	using type = T;
};
// remove_pointer 같은 것을 "제대로 설계(C++표준처럼)" 하려면
// const, volatile을 모두 고려해야 합니다.
// 어제 만든 is_pointer 도 동일합니다.
template<typename T> struct remove_pointer<T* const>
{
	using type = T;
};
template<typename T> struct remove_pointer<T* volatile>
{
	using type = T;
};
template<typename T> struct remove_pointer<T* const volatile >
{
	using type = T;
};
// 참고 :  const T* => 포인터는 const 아님. 대상체가 const 
//        T* const => 포인터가 const.     대상체는 const 아님

// const T* 는 포인터 자체가 const 인것은 아니므로, 위처럼 따로 만들필요없습니다

template<typename T>
void fn(T& p)
{
	// remove_pointer 사용할때, dependent name 이라면 
	// "typename" 표기해야 합니다.
	remove_pointer<T>::type n1; // error

	typename remove_pointer<T>::type n2; // ok
}


int main()
{
	std::cout << typeid(remove_pointer<int*>::type).name() 				  << std::endl;
	std::cout << typeid(remove_pointer<int* const>::type).name() 		  << std::endl;
	std::cout << typeid(remove_pointer<int* volatile>::type).name() 	  << std::endl;
	std::cout << typeid(remove_pointer<int* const volatile>::type).name() << std::endl;
}