#include <iostream>
#include <string>

class Animal {};
class Dog : public Animal {};

template<typename T> class smart_ptr
{
	T* obj = nullptr;
public:
	explicit smart_ptr(T* p) : obj(p) {}


	// smart_ptr<Animal> = smart_ptr<Dog> 는 되어야 합니다.
	// smart_ptr<int>    = smart_ptr<Dog> 는 안되야 합니다.

	// 생성자는 리턴 타입을 가질수 없습니다.
	// 이경우 대부분, 템플릿 인자에 enable_if 기술을 사용합니다.
	// 아래 코드의 "A" 인자는 실제 사용하려고 한것은 아니고
	// enable_if 기술을 위해서 만든것 입니다.
	template<typename U,
			 typename A = std::enable_if_t< 
								std::is_convertible_v<U*, T*> >>	
	smart_ptr(const smart_ptr<U>& sp) : obj(sp.obj) {}

	template<typename> friend class smart_ptr;
};
int main()
{
	smart_ptr<Dog>    p1(new Dog);
	smart_ptr<Animal> p2 = p1;	

	smart_ptr<int> p3 = p1; 
}


