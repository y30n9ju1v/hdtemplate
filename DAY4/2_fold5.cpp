#include <iostream>
#include <vector>

std::vector<int> v;

template<typename ... Types>
void fn(Types ... args)
{
	// pack 안의 모든 요소를 v 에 넣고 싶다.
	(v.push_back(args) , ...);
	// pack            op  ...   입니다.
	// v.push_back(1), (v.push_back(2), ( v.push_back(3)     
}
int main()
{
	fn(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);

	for (auto e : v)
		std::cout << e << ", ";
}
// 이 외에도 구글에서 "C++ fold expression example"  검색하면
// 재미있는 기법 많이 있습니다.


