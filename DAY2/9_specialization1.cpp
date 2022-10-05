#include <iostream>


template<typename T> class Vector
{
	T*  ptr;
	std::size_t size;
public:
	Vector(std::size_t sz) : size(sz)
	{
		 ptr = new T[sz];
	}
	~Vector() { delete[] ptr;}
};


int main()
{
	// �ٽ� 1. vector ���� container�� �پ��� Ÿ���� �����Ҽ� �־�� �ϹǷ�
	//        "template" ���� ������ �մϴ�.
	Vector<int>    v1(5);	// int    5�� �����ϱ� ���� "new int[5]" �Ҵ�
	Vector<double> v2(5);   // double 5�� �����ϱ� ���� "new double[5]" �Ҵ�

	// �ٽ� 2. vector �����ڸ� ���� �Ʒ� �ڵ带 ������ ������.. ??
	Vector<bool>   v3(100); // bool 100�� �����ϱ� ���� "100 byte ���??"
							// => 100 byte �� �ƴ϶� 100 bit �� �˴ϴ�.
}

