

// 1. Point 를 템플릿으로 하면 사용자에게 보다 많은 "유연성"을 제공할수 있습니다.

template<typename T>
class Point
{
	T x, y;
public:
	Point(const T& a, const T& b) : x(a), y(b) {}

	// 핵심 : 클래스 템플릿의 멤버 함수 템플릿은 
	// 주로, "generic 복사 생성자", "generic 대입연산자" 등을 만들때 
	// 널리 사용됩니다.
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