#include <iostream>
#include <string>
#include <string_view>	// C++17 에서 추가됨

int main()
{
	std::string s1 = "to be or not to be";

	// 아래 2줄을 차이를 꼭 알아 두세요.
	std::string      s2 = s1;
	std::string_view sv = s1;

}

