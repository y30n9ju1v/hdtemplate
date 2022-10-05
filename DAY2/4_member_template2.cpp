

// 1. Point �� ���ø����� �ϸ� ����ڿ��� ���� ���� "������"�� �����Ҽ� �ֽ��ϴ�.

template<typename T>
class Point
{
	T x, y;
public:
	Point(const T& a, const T& b) : x(a), y(b) {}
};

int main()
{
	Point<int> p1(1, 2);  // ok. ���ڰ� 2���� ������ ���
	Point<int> p2 = p1;   // ok. �����Ϸ��� �����ϴ� "���� ������" ���

	Point<double> p3 = p1;// error.
						  // p1 �� p3�� �ٸ� Ÿ�� �Դϴ�.
						  // "���� �����ڴ� ���� Ÿ��" �� �����Ҷ� ���

	// "int" �� "double" �� �����ɼ� �ֽ��ϴ�.
	// "Point<int>" �� "Point<double>" �� �����ɼ� �ֽ��ϴ�.
	// => generic ������(���������) ��� ������ �ʿ� �մϴ�.

}