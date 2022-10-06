#include <iostream>
#include <string>

class Animal {};
class Dog : public Animal {};

template<typename T> class smart_ptr
{
	T* obj = nullptr;
public:
	explicit smart_ptr(T* p) : obj(p) {}

	/*
	template<typename U,
		typename A = std::enable_if_t<
						std::is_convertible_v<U*, T*> >>
		smart_ptr(const smart_ptr<U>& sp) : obj(sp.obj) {}
	*/

	// ���ø� ���ڿ� enable_if �Ҷ��� �Ʒ� ó�� �ϱ⵵ �մϴ�.
	// �Ʒ� �ڵ�� �ᱹ ������ ���̸� 
	// template<typename T, void* = nullptr> �Դϴ�.
	template<typename U,
		std::enable_if_t<std::is_convertible_v<U*, T*>> * = nullptr>

		smart_ptr(const smart_ptr<U>& sp) : obj(sp.obj) {}


	template<typename> friend class smart_ptr;
};
int main()
{
	smart_ptr<Dog>    p1(new Dog);
	smart_ptr<Animal> p2 = p1;

	smart_ptr<int> p3 = p1;
}


