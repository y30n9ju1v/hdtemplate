#include <iostream>
#include <string>

class Animal {};
class Dog : public Animal {};

template<typename T> class smart_ptr
{
	T* obj = nullptr;
public:
	explicit smart_ptr(T* p) : obj(p) {}


	// smart_ptr<Animal> = smart_ptr<Dog> �� �Ǿ�� �մϴ�.
	// smart_ptr<int>    = smart_ptr<Dog> �� �ȵǾ� �մϴ�.

	// �����ڴ� ���� Ÿ���� ������ �����ϴ�.
	// �̰�� ��κ�, ���ø� ���ڿ� enable_if ����� ����մϴ�.
	// �Ʒ� �ڵ��� "A" ���ڴ� ���� ����Ϸ��� �Ѱ��� �ƴϰ�
	// enable_if ����� ���ؼ� ����� �Դϴ�.
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


