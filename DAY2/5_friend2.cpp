#include <iostream>

template<typename T>
class Point
{
	T x, y;
public:
	Point(const T& a, const T& b) : x(a), y(b) {}

	friend std::ostream& operator<<(std::ostream& os, const Point& pt);
};

/*
// 아래 처럼 하면 cout 으로 "Point<int>" 만 출력가능하게 됩니다.
std::ostream& operator<<(std::ostream& os, const Point<int>& pt)
{
	std::cout << pt.x << ", " << pt.y << std::endl;
	return os;
}
*/
// 아래 처럼 하면 cout 으로 Point<int>, Point<double> 등 모두 출력가능합니다.
// 그런데.. 왜??? 에러가 날까요 ? 에러의 이유를 생각해 보세요.
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