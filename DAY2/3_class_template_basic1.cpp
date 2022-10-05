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

	// 다음중 맞는 것은 ?
	void swap(Vector&    v) {}	// 1. 이렇게 해도 2번과 동일
//	void swap(Vector<T>& v) {}  // 2. 정확한 표기법

	// 핵심 3. 멤버 함수 안에서는 "Vector" 만 표기해도
	//        "Vector<T>" 와 동일 합니다.


	// 그래서, 복사 생성자모양은 아래 2개 코드가 동일합니다.
	Vector(const Vector& v) {}		// 이렇게 해도 되고
//	Vector(const Vector<T>& v) {}	// 이렇게 해도 됩니다.
};


// 핵심 1. Vector vs Vector<T>
// Vector    : 템플릿, 타입은 아님
// Vector<T> : 타입,   템플릿 아님

// 핵심 2. 함수의 인자는 "템플릿" 이 아닌 "타입" 이어야 합니다.

//void fn(Vector v) {}    // error.
void fn(Vector<int> v) {} // ok.




int main()
{
//	Vector v(10);	// error. Vector 는 타입이 아닌 템플릿 입니다.
					// 단, C++17 부터는, 
					// 1. 생성자를 통한 추론, 
					// 2. type deduction guide 제공시 추론 가능

	Vector<int> v(10); // ok. Vector<T> 는 템플릿이 아닌 "타입"

	fn(v);
}