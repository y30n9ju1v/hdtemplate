

// 1. Point 를 템플릿으로 하면 사용자에게 보다 많은 "유연성"을 제공할수 있습니다.

template<typename T>
class Point
{
	T x, y;
public:
	Point(const T& a, const T& b) : x(a), y(b) {}

	// 1. 복사 생성자를 생각해 봅시다.
	// => "Point<double> p3 = p1" 했을때 T=double로 결정되었으므로
	// => p1 은 "Point<double>" 인 경우만 에러가 아닙니다.
	// 
//	Point(const Point& pt) {}	// 이 코드는 
//	Point(const Point<T>& pt) {}// 이 코드와 동일합니다.


	// 2. 아래 함수를 생각해 봅시다
	// => 인자로 "Point<int>" 타입만 받겠다는 의미.
//	Point(const Point<int>& pt) {} 

	// 3. Point<int> 뿐아니라 Point<float> 등도 되어야 합니다.

	// => T(int) 가 U(double) 에 복사 될수 있다면
	// => Point<T> 는 Point<U> 에 복사 될수 있어야 한다.
	
	// Generic (copy) constructor 라는 개념
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