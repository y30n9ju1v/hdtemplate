#include <iostream>


template<typename T>
class Point
{
	T x, y;
public:
	Point(const T& a, const T& b) : x(a), y(b) {}

	// 결론 : 클래스 템플릿의 friend 함수를 만들때는
	//       템플릿 선언 안쪽에 직접 구현까지 하는것이 최선의 코드 입니다.
	friend std::ostream& operator<<(std::ostream& os, const Point<T>& pt)
	{
		std::cout << pt.x << ", " << pt.y << std::endl;
		return os;
	}
};
int main()
{
	Point<int> p(1, 2);

	std::cout << p; // 이 코드는
//	operator<<(cout, p); // 이 코드와 같습니다.
						// 이렇게 사용되려면 멤버 함수가 아닌 일반 함수 어야야 합니다.

	// operator<< 가 멤버라면
//	p.operator<<(cout, p); // 이렇게 사용해야 합니다.
}