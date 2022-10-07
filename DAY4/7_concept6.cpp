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

	// C++20 부터는 위 처럼 이름을 같게 할수도 있지만..
	// 과거와의 호환성을 위해서.. find_if 는 계속 find_if 입니다.
}

// 복습하시다가 질문 생기시면 

// smkang @ codenuri.co.kr   로 메일 주세요


// 복습할때 "godbolt.org" 많이 활용하세요..

// C++ Template Complete GUIDE <===  최고의 서적(C++ 표준위원장 저)
//		2/e   => C++20 없음.. 