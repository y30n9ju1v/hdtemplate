

// 1. Point 를 템플릿으로 하면 사용자에게 보다 많은 "유연성"을 제공할수 있습니다.

template<typename T>
class Point
{
	T x, y;
public:
	Point(const T& a, const T& b) : x(a), y(b) {}
};

int main()
{
	Point<int> p1(1, 2);  // ok. 인자가 2개인 생성자 사용
	Point<int> p2 = p1;   // ok. 컴파일러가 제공하는 "복사 생성자" 사용

	Point<double> p3 = p1;// error.
						  // p1 과 p3는 다른 타입 입니다.
						  // "복사 생성자는 같은 타입" 을 복사할때 사용

	// "int" 는 "double" 에 보관될수 있습니다.
	// "Point<int>" 도 "Point<double>" 에 보관될수 있습니다.
	// => generic 생성자(복사생성자) 라는 개념이 필요 합니다.

}