#include <iostream>
#include <string>

class Animal {};
class Dog : public Animal {};

template<typename T> class smart_ptr
{
	T* obj = nullptr;
public:
	explicit smart_ptr(T* p) : obj(p) {}


	// Generic copy constructor
	template<typename U>
	smart_ptr(const smart_ptr<U>& sp) : obj(sp.obj) {}

	// smart_ptr<int> p3 = p1; 인 경우 p1 이 smart_ptr<Dog> 이므로
	// 위 템플릿을 사용해서 아래 코드 생성
	
	smart_ptr(const smart_ptr<Dog>& sp) 
		: obj(sp.obj)  //<== 여기서 에러. "obj = int*, sp.obj = Dog*" 이므로
	{}


	template<typename> friend class smart_ptr;
};
int main()
{
	smart_ptr<Dog>    p1(new Dog);
	smart_ptr<Animal> p2 = p1;	// Animal* p2 = &Dog 개념이므로 되야합니다.
								// p1 : smart_pointer<Dog>
								// p2 : smart_pointer<Animal>
								// => 어제 배운 Generic 복사 생성자필요

	smart_ptr<int> p3 = p1; // int* p3 = &Dog 이므로. error 나와야 합니다.
							// 현재 error 나옵니다.
							// 그런데. 에러 메세지 확인해 보세요
						   
}


