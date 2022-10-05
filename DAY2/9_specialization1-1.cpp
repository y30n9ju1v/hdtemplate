#include <iostream>


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

int main()
{
	Vector<int>    v1(5);	
	Vector<double> v2(5);   
	Vector<bool>   v3(100); 
}

