#include <iostream>

template<typename T>
class Point
{
	T x, y;
public:
	Point(const T& a, const T& b) : x(a), y(b) {}

	// �ذ�å
	// => "operator<<" �� �Լ� ���ø� �Դϴ�. friend ����Ҷ�

	// 1. �Ʒ� ó�� ���ø� �� �ƴ� "friend �Ϲ� �Լ�" �� ������� ������
//	friend std::ostream& operator<<(std::ostream& os, const Point& pt);

	// 2. �Ʒ� ó�� "friend �Լ� ���ø�" ���� �ϼ���
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