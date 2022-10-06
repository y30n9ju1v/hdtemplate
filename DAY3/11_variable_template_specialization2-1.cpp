#include <iostream>
#include <string>
#include <string_view>	// C++17 ���� �߰���

// call by value : ���� ���� �ڵ�
void f1(std::string s) {}      

// const reference : ������ ������... �ּ��� �ƴ�..
void f2(const std::string& s) {} 

// string_view : good.... ��. �б⸸ �����մϴ�.
void f3(std::string_view sv) {}

int main()
{
	std::string s1 = "to be or not to be";

	f1(s1);
	f2(s1);
	f3(s1);
}

