#include <iostream>
#include <string>
#include <string_view>
#include <ranges>

int main()
{
	std::string s1 = "to be or not to be";

	// 아래 2줄에 대해서 생각해 보세요
	// => 임시객체의 반복자 얻기..

	auto p1 = std::begin(std::string(s1));

	auto p2 = std::begin(std::string_view(s1));

	// 자원을 소유하는 클래스의 임시객체는 "반복자"를 꺼내면 위험합니다.
	// 자원을 소유하지 않은 클래스의 임시객체는 "반복자"를 꺼내도 됩니다.

	// 결론 : 어떤 타입이 자원을 소유 하는가?
	//       소유하지 않은 가?  가 중요합니다.

	// 소유 하지 않은 것을 "borrowed range" 라고 부릅니다 - C++20

	// std::ranges::enable_borrowed_range : variable template 입니다.

	std::cout << std::ranges::enable_borrowed_range<std::string> << std::endl; // 0
	std::cout << std::ranges::enable_borrowed_range<std::string_view> << std::endl; // 1
}

// C++20의 enable_rorrowed_rangle, <ranges> 헤더
template <typename>
inline constexpr bool enable_borrowed_range = false;

template <typename T, typename Traits>
inline constexpr bool enable_borrowed_range<std::basic_string_view<T, Traits>> = true;
