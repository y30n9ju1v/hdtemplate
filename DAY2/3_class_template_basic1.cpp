#include <iostream>

// Vector vs Vector<T>

template<typename T>
class Vector
{
	T* ptr;
	std::size_t  size;
public:
	Vector(std::size_t sz) : size(sz)
	{
		ptr = new T[sz];
	}
	~Vector() { delete[] ptr; }

	T& operator[](std::size_t idx) { return ptr[idx];}

	// ������ �´� ���� ?
	void swap(Vector&    v) {}	// 1. �̷��� �ص� 2���� ����
//	void swap(Vector<T>& v) {}  // 2. ��Ȯ�� ǥ���

	// �ٽ� 3. ��� �Լ� �ȿ����� "Vector" �� ǥ���ص�
	//        "Vector<T>" �� ���� �մϴ�.


	// �׷���, ���� �����ڸ���� �Ʒ� 2�� �ڵ尡 �����մϴ�.
	Vector(const Vector& v) {}		// �̷��� �ص� �ǰ�
//	Vector(const Vector<T>& v) {}	// �̷��� �ص� �˴ϴ�.
};


// �ٽ� 1. Vector vs Vector<T>
// Vector    : ���ø�, Ÿ���� �ƴ�
// Vector<T> : Ÿ��,   ���ø� �ƴ�

// �ٽ� 2. �Լ��� ���ڴ� "���ø�" �� �ƴ� "Ÿ��" �̾�� �մϴ�.

//void fn(Vector v) {}    // error.
void fn(Vector<int> v) {} // ok.




int main()
{
//	Vector v(10);	// error. Vector �� Ÿ���� �ƴ� ���ø� �Դϴ�.
					// ��, C++17 ���ʹ�, 
					// 1. �����ڸ� ���� �߷�, 
					// 2. type deduction guide ������ �߷� ����

	Vector<int> v(10); // ok. Vector<T> �� ���ø��� �ƴ� "Ÿ��"

	fn(v);
}