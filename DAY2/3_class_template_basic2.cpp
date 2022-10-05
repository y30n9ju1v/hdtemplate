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

// 클래스 템플릿의 멤버 함수를 클래스 외부에 구현.
// 핵심 1. 클래스 이름은 "Vector" 가  아닌 "Vector<T>" 입니다.
//     2. "T" 가 템플릿 인자 임을 알리기 위해 모든 멤버 함수 앞에
//       "template<typename T>" 가 있어야 합니다.

//     3. 멤버 함수는 클래스 템플릿 외부에 만들수는 있지만
//        별도의 소스 파일로 분리하지 마세요
//		  반드시, 헤더 안에 "모든 멤버 함수 구현부" 가 있어야 합니다.


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