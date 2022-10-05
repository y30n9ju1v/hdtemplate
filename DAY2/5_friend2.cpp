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
// �Ʒ� ó�� �ϸ� cout ���� "Point<int>" �� ��°����ϰ� �˴ϴ�.
std::ostream& operator<<(std::ostream& os, const Point<int>& pt)
{
	std::cout << pt.x << ", " << pt.y << std::endl;
	return os;
}
*/
// �Ʒ� ó�� �ϸ� cout ���� Point<int>, Point<double> �� ��� ��°����մϴ�.
// �׷���.. ��??? ������ ����� ? ������ ������ ������ ������.
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