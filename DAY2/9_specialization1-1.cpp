#include <iostream>


// "primary template" �̶�� �մϴ�.
template<typename T> class Vector
{
	T* ptr;
	std::size_t size;
public:
	Vector(std::size_t sz) : size(sz)
	{
		ptr = new T[sz];

		std::cout << "primary template ���� ���" << std::endl;
	}
	~Vector() { delete[] ptr; }
};
// specialization (Ư��ȭ, ����ȭ) ��� �մϴ�.
// => Ÿ���� ������ Ȯ���� ���
template<> class Vector<bool>
{
	int* ptr;
	std::size_t size;
public:
	Vector(std::size_t sz) : size(sz)
	{
		ptr = new int[(sz / 32) + 1]; // 0~31 : int 1���� ����
									  // 32~63 : int 2���� ����

		std::cout << "vector<bool> Ư��ȭ ���� ���" << std::endl;
	}
	~Vector() { delete[] ptr; }
};
// partial specialization(�κ� Ư��ȭ, �κ� ����ȭ)
template<typename T> class Vector<T*>
{
	// �����Ϳ� ����ȭ �ǵ��� ����
public:
	Vector(std::size_t sz) : size(sz)
	{
		std::cout << "T* ���� ���" << std::endl;
	}
	~Vector() { }
};

int main()
{
	Vector<int>    v1(5);	
	Vector<double> v2(5);   
	Vector<bool>   v3(100); 

	Vector<int*>   v4(5);
	Vector<double*>v5(100);
}

// ����. ���� std::vector ��
// primary template ��
// vector<bool> Ư��ȭ �������θ� �Ǿ� �ֽ��ϴ�.

// �� �ڵ� ó�� �����Ϳ� ���� �κ� Ư��ȭ�� �Ǿ� ������ �ʽ��ϴ�.