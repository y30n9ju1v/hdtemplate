

// 1. Point �� ���ø����� �ϸ� ����ڿ��� ���� ���� "������"�� �����Ҽ� �ֽ��ϴ�.

template<typename T>
class Point
{
	T x, y;
public:
	Point(const T& a, const T& b) : x(a), y(b) {}

	// 1. ���� �����ڸ� ������ ���ô�.
	// => "Point<double> p3 = p1" ������ T=double�� �����Ǿ����Ƿ�
	// => p1 �� "Point<double>" �� ��츸 ������ �ƴմϴ�.
	// 
//	Point(const Point& pt) {}	// �� �ڵ�� 
//	Point(const Point<T>& pt) {}// �� �ڵ�� �����մϴ�.


	// 2. �Ʒ� �Լ��� ������ ���ô�
	// => ���ڷ� "Point<int>" Ÿ�Ը� �ްڴٴ� �ǹ�.
//	Point(const Point<int>& pt) {} 

	// 3. Point<int> �Ӿƴ϶� Point<float> � �Ǿ�� �մϴ�.

	// => T(int) �� U(double) �� ���� �ɼ� �ִٸ�
	// => Point<T> �� Point<U> �� ���� �ɼ� �־�� �Ѵ�.
	
	// Generic (copy) constructor ��� ����
	template<typename U>
	Point(const Point<U>& pt) {}
};

int main()
{
	Point<int> p1(1, 2);  
	Point<int> p2 = p1;   

	Point<double> p3 = p1;

	Point<float> p4(1, 2);
	Point<double> p5 = p4;
}