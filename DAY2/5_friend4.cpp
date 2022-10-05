#include <iostream>

template<typename T>
class Point
{
	T x, y;
public:
	Point(const T& a, const T& b) : x(a), y(b) {}
	

	friend std::ostream& operator<<(std::ostream& os, const Point& pt);
														 // Point<T>& 

	// 1. Ŭ���� �ܺο� �ִ� operator<< �� "�Լ� ���ø�" �Դϴ�.

	// 2. �� friend �Լ� ������ ���ø� �ƴմϴ�.
	//    main ���� "Point<int> p" �� �ϸ� �� friend �� �ᱹ �Ʒ� �ڵ��Դϴ�.
//	friend std::ostream& operator<<(std::ostream& os, const Point<int>& pt);
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

	std::cout << p;	// �̼��� "template" �� ������� �ʰ�
					// 2��° ���ڰ� "Point<int>"�� Ư��ȭ ������ ã������ �մϴ�.
					// ������ ���� ������ ��ũ����

					// friend ���� ������ "Point<int>" �� ã���� �մϴ�.
}