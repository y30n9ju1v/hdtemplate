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

	// smart_ptr<int> p3 = p1; �� ��� p1 �� smart_ptr<Dog> �̹Ƿ�
	// �� ���ø��� ����ؼ� �Ʒ� �ڵ� ����
	
	smart_ptr(const smart_ptr<Dog>& sp) 
		: obj(sp.obj)  //<== ���⼭ ����. "obj = int*, sp.obj = Dog*" �̹Ƿ�
	{}


	template<typename> friend class smart_ptr;
};
int main()
{
	smart_ptr<Dog>    p1(new Dog);
	smart_ptr<Animal> p2 = p1;	// Animal* p2 = &Dog �����̹Ƿ� �Ǿ��մϴ�.
								// p1 : smart_pointer<Dog>
								// p2 : smart_pointer<Animal>
								// => ���� ��� Generic ���� �������ʿ�

	smart_ptr<int> p3 = p1; // int* p3 = &Dog �̹Ƿ�. error ���;� �մϴ�.
							// ���� error ���ɴϴ�.
							// �׷���. ���� �޼��� Ȯ���� ������
						   
}


