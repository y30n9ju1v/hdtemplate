#include <vector>

template<typename T>
T square(T a)
{
	return a * a;
}

template<typename T>
class List
{
public:
	List(int sz, const T& value) {}
};

int main()
{
	// 함수 템플릿은 "타입 인자"를 생략 할수 있습니다. - C++98 부터.
	square<int>(3);	// ok
	square(3);		// ok 

	// 클래스 템플릿은 "C++17" 부터 타입 인자 생략가능합니다.
	List<int> s1(10, 3);
	List      s2(10, 3);// error. until C++14
						// ok     since c++17

	std::vector<int> v1 = { 1,2,3 };
	std::vector      v2 = { 1,2,3 };  // C++17 부터는 타입 인자 생략해도		
										// 됩니다.
}

