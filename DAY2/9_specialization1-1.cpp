#include <iostream>


// "primary template" 이라고 합니다.
template<typename T> class Vector
{
	T* ptr;
	std::size_t size;
public:
	Vector(std::size_t sz) : size(sz)
	{
		ptr = new T[sz];

		std::cout << "primary template 버전 사용" << std::endl;
	}
	~Vector() { delete[] ptr; }
};
// specialization (특수화, 전문화) 라고 합니다.
// => 타입이 완전히 확정된 경우
template<> class Vector<bool>
{
	int* ptr;
	std::size_t size;
public:
	Vector(std::size_t sz) : size(sz)
	{
		ptr = new int[(sz / 32) + 1]; // 0~31 : int 1개로 관리
									  // 32~63 : int 2개로 관리

		std::cout << "vector<bool> 특수화 버전 사용" << std::endl;
	}
	~Vector() { delete[] ptr; }
};
// partial specialization(부분 특수화, 부분 전문화)
template<typename T> class Vector<T*>
{
	// 포인터에 최적화 되도록 구현
public:
	Vector(std::size_t sz) : size(sz)
	{
		std::cout << "T* 버전 사용" << std::endl;
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

// 참고. 실제 std::vector 는
// primary template 과
// vector<bool> 특수화 버전으로만 되어 있습니다.

// 위 코드 처럼 포인터에 대한 부분 특수화가 되어 있지는 않습니다.