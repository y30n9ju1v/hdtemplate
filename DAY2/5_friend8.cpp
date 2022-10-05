#include <iostream>


template<typename T>
class Point
{
	T x, y;
public:
	Point(const T& a, const T& b) : x(a), y(b) {}

	// ��� : Ŭ���� ���ø��� friend �Լ��� ���鶧��
	//       ���ø� ���� ���ʿ� ���� �������� �ϴ°��� �ּ��� �ڵ� �Դϴ�.
	friend std::ostream& operator<<(std::ostream& os, const Point<T>& pt)
	{
		std::cout << pt.x << ", " << pt.y << std::endl;
		return os;
	}
};
int main()
{
	Point<int> p(1, 2);

	std::cout << p; // �� �ڵ��
//	operator<<(cout, p); // �� �ڵ�� �����ϴ�.
						// �̷��� ���Ƿ��� ��� �Լ��� �ƴ� �Ϲ� �Լ� ��߾� �մϴ�.

	// operator<< �� ������
//	p.operator<<(cout, p); // �̷��� ����ؾ� �մϴ�.
}