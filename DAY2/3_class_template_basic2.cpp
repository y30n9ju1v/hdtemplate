#include <iostream>


template<typename T>
class Vector
{
	T* ptr;
	std::size_t  size;
public:
	Vector(std::size_t sz);
	~Vector();
	T& operator[](std::size_t idx);
};

// Ŭ���� ���ø��� ��� �Լ��� Ŭ���� �ܺο� ����.
// �ٽ� 1. Ŭ���� �̸��� "Vector" ��  �ƴ� "Vector<T>" �Դϴ�.
//     2. "T" �� ���ø� ���� ���� �˸��� ���� ��� ��� �Լ� �տ�
//       "template<typename T>" �� �־�� �մϴ�.

//     3. ��� �Լ��� Ŭ���� ���ø� �ܺο� ������� ������
//        ������ �ҽ� ���Ϸ� �и����� ������
//		  �ݵ��, ��� �ȿ� "��� ��� �Լ� ������" �� �־�� �մϴ�.


template<typename T> 
Vector<T>::Vector(std::size_t sz) : size(sz)
{
	ptr = new T[sz];
}

template<typename T>
Vector<T>::~Vector() { delete[] ptr; }

template<typename T>
T& Vector<T>::operator[](std::size_t idx) { return ptr[idx]; }







int main()
{

}