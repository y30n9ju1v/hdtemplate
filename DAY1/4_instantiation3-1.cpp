#include <vector>

template<typename T>
class List
{
public:
	List(int sz, const T& value) {}
	List() {}

	// STL 컨테이너를 인자로 가지는 생성자
	template<typename C>
	List(const C& c) {}  

	template<typename IT>
	List(IT first, IT last) {} // 반복자는 "call by value"로 받아도 됩니다.

};
// C++17 "class template type deduction guide" 문법
// 생성자모양 -> List<타입>
List()->List<int>;

template<typename C>
List(const C& c)->List<typename C::value_type>;   // 현재 C는 vector<int>

template<typename IT>
List(IT first, IT last)->List< typename IT::value_type >;

int main()
{
	List<int> s1(10, 3);
	List      s2(10, 3);
	List      s3; // "deduction guide" 가 있으므로 List<int> 입니다.
				  // 그런데, 이 경우는 "에러"나게 하는게 좋습니다.

	std::vector v = { 1,2,3 };
	List s4(v); // ?

	List s5(v.begin(), v.end()); // 에러나지 않게 
						// 생성자와 "deduction guide" 제공해 보세요
}

