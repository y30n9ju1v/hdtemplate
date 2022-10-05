#include <iostream>

template<typename T>
class Point
{
	T x, y;
public:
	Point(const T& a, const T& b) : x(a), y(b) {}
	

	friend std::ostream& operator<<(std::ostream& os, const Point& pt);
														 // Point<T>& 

	// 1. 클래스 외부에 있는 operator<< 는 "함수 템플릿" 입니다.

	// 2. 위 friend 함수 선언은 템플릿 아닙니다.
	//    main 에서 "Point<int> p" 를 하면 위 friend 는 결국 아래 코드입니다.
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

	std::cout << p;	// 이순간 "template" 을 사용하지 않고
					// 2번째 인자가 "Point<int>"인 특수화 버전을 찾으려고 합니다.
					// 하지만 없기 때문에 링크에러

					// friend 선언 때문에 "Point<int>" 를 찾으려 합니다.
}