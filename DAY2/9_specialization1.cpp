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
	// 핵심 1. vector 같은 container는 다양한 타입을 보관할수 있어야 하므로
	//        "template" 으로 만들어야 합니다.
	Vector<int>    v1(5);	// int    5개 보관하기 위해 "new int[5]" 할당
	Vector<double> v2(5);   // double 5개 보관하기 위해 "new double[5]" 할당

	// 핵심 2. vector 생성자를 보고 아래 코드를 생각해 보세요.. ??
	Vector<bool>   v3(100); // bool 100개 보관하기 위해 "100 byte 사용??"
							// => 100 byte 가 아니라 100 bit 면 됩니다.
}

