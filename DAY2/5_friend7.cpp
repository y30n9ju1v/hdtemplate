#include <iostream>

// �Ʒ� �ڵ�� "N��" Ŭ������ "M��" �Լ��� friend

// Point<int>  <=> operator<<(Point<int>)
//             <=> operator<<(Point<double>) ��� ��� friend

// Point<double>	<=> operator<<(Point<int>)
//					<=> operator<<(Point<double>) ��� ��� friend

template<typename T>
class Point
{
	T x, y;
public:
	Point(const T& a, const T& b) : x(a), y(b) {}

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