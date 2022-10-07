#include <iostream>
#include <algorithm>
#include <concepts>
#include <vector>

template<typename Iter, typename T>
	requires (!std::predicate<T, std::iter_value_t<Iter>>)
Iter find(Iter first, Iter last, const T& value)
{
	std::cout << "값 검색 버전" << std::endl;
	return first;
}

// std::predicate<T, 타입> : T가  "타입객체" 를 1번째 인자로 해서 호출가능한가?
//							결과(반환타입)이 bool 로 변환될수 있는가 ?
template<typename Iter, typename T> 
			requires std::predicate<T, std::iter_value_t<Iter>>
Iter find(Iter first, Iter last, T func)
{
	std::cout << "함수 버전" << std::endl;
	return first;
}

int main()
{
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };

	auto p1 = find(std::begin(v), std::end(v), 3);
	auto p2 = find(std::begin(v), std::end(v), [](int a) { return a % 3 == 0; });


}