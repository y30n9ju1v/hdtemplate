#include <iostream>
#include <algorithm>
#include <concepts>
#include <vector>

// std::find 는 모든 인자가 템플릿 입니다.
// 반복자 : 복사본이 생성되어도 오버헤드 거의 없습니다. "값으로 받는것이 원칙"
template<typename Iter, typename T>
Iter find(Iter first, Iter last, const T& value)
{
	std::cout << "값 검색 버전" << std::endl;

	return first;
}
// 같은 이름 find 를 다시 함수 버전으로 만드는 방법이 C++98 에는 없었습니다.
// C++11 enable_if 로 어느정도 가능하지만 완벽하지 않습니다.
template<typename Iter, typename T>
Iter find(Iter first, Iter last, T func)
{
	std::cout << "함수 버전" << std::endl;

	return first;
}

int main()
{
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };
	
	// find    : 주어진 구간에서 값 검색
	// find_if : 주어진 구간에서 조건 검색(마지막 인자로 호출가능한 객체(callable object) 전달)
	auto p1 = std::find(   std::begin(v), std::end(v), 3);
//	auto p2 = std::find_if(std::begin(v), std::end(v), [](int a) { return a % 3 == 0; } );

	// find_if 말고, 그냥 find() 로 만들면 더 편하지 않았을까?
	auto p2 = std::find(std::begin(v), std::end(v), [](int a) { return a % 3 == 0; });


}