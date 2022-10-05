#include <iostream>

// 77 page
class Point
{
	int x, y;
public:
	Point(int a, int b) : x(a), y(b) {}

	friend std::ostream& operator<<(std::ostream& os, const Point& pt);
};

std::ostream& operator<<(std::ostream& os, const Point& pt)
{
	std::cout << pt.x << ", " << pt.y << std::endl;
	return os;
}

int main()
{
	Point p(1,2);

	std::cout << p; // ok. operator<<(cout, p) 호출!!

	// 핵심 : operator<< 를 만들면, 사용자 정의 타입을 cout으로 출력 가능.
}