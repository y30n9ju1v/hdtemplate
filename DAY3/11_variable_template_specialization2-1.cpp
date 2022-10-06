#include <iostream>
#include <string>
#include <string_view>	// C++17 에서 추가됨

// call by value : 아주 나쁜 코드
void f1(std::string s) {}      

// const reference : 나쁘지 않지만... 최선은 아님..
void f2(const std::string& s) {} 

// string_view : good.... 단. 읽기만 가능합니다.
void f3(std::string_view sv) {}

int main()
{
	std::string s1 = "to be or not to be";

	f1(s1);
	f2(s1);
	f3(s1);
}

