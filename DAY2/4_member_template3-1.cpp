

// 1. Point �� ���ø����� �ϸ� ����ڿ��� ���� ���� "������"�� �����Ҽ� �ֽ��ϴ�.

template<typename T>
class Point
{
	T x, y;
public:
	Point(const T& a, const T& b) : x(a), y(b) {}

	// �ٽ� : Ŭ���� ���ø��� ��� �Լ� ���ø��� 
	// �ַ�, "generic ���� ������", "generic ���Կ�����" ���� ���鶧 
	// �θ� ���˴ϴ�.
	template<typename U>
	Point(const Point<U>& pt) : x(pt.x), y(pt.y) {}

	template<typename> friend class Point;
};

int main()
{
	Point<int>   p1(1, 2);
	Point<int>   p2 = p1;
	Point<float> p3(1, 2);

	Point<double> p4 = p1;
	Point<double> p5 = p3;
}