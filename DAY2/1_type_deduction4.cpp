#include <iostream>
#include "fname.h"

// ��Ģ 3. ������ Ÿ���� "forwarding reference(T&&)" �� ���
// => C++11 ���� ���� "�Ϻ��� ����"�� ���� ���
// => ���ڰ� lvalue �̸� "T �� reference type"
//    ���ڰ� rvaleu �̸� "T �� value type"
// => "modern C++ ���� ����"

template<typename T> void f3(T&& arg)
{
	std::cout << _FNAME_ << std::endl;
}

int main()
{
	int  n = 10;
	int& r = n;
	const int  c = 10;
	const int& cr = c;

	f3(3);	// 3 �� rvalue, T = int,    arg = int&& (rvalue reference )
	f3(n);	// n �� lvalue, T = int&    arg = int& && => int& 
	
	f3(c);	// c �� const lvalue, T= const int&,  arg =const int& &&
			//											const int&

	f3(r);	// r �� lvalue, T=int&   arg = int& && => int&
	
	f3(cr); // cr �� const lvalue
			// T = const int&		arg = const int& && => const int&

}