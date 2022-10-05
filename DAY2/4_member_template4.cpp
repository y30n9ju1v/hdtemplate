#include <memory>

class Animal { int age; };

class Dog : public Animal {};

int main()
{
	// Animal* Ÿ���� ������ "Dog�� �ּ�"�� ������ �ֽ��ϴ�. - upcasting
	Animal* p = new Dog;

	// C++ �� raw pointer ��� "����Ʈ ������"�� ���� ����մϴ�.

	std::shared_ptr<Dog>	p1(new Dog);
	std::shared_ptr<Animal> p2 = p1; // �Ǿ� �մϴ�.!! �˴ϴ�.!!
					// �׷���, p1 �� p2�� �ٸ� Ÿ�� �Դϴ�.
					// shared_ptr �ȿ��� "generic copy constructor"�� 
					// �ֽ��ϴ�.!!
}
