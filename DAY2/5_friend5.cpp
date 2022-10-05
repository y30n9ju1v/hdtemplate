#include <iostream>

template<typename T>
class Point
{
	T x, y;
public:
	Point(const T& a, const T& b) : x(a), y(b) {}

	// 해결책
	// => "operator<<" 는 함수 템플릿 입니다. friend 등록할때

	// 1. 아래 처럼 템플릿 이 아닌 "friend 일반 함수" 로 등록하지 마세요
//	friend std::ostream& operator<<(std::ostream& os, const Point& pt);

	// 2. 아래 처럼 "friend 함수 템플릿" 으로 하세요
	template<typename U>
	friend std::ostream& operator<<(std::ostream& os, const Point<U>& pt);
};

template<typename T>
std::ostream& operator<<(std::ostream& os, const Point<T>& pt)
{
	std::cout << pt.x << ", " << pt.y << std::endl;
	return os;
}

int main()
{
	Point<int> p(1, 2);

	std::cout << p;	
}