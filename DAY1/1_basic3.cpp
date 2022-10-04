#include <iostream>

// template instantiation(���ø� �ν��Ͻ�ȭ)
// => ���ø�(Ʋ) �� ���� ���� "�Լ�/Ŭ����"�� ����� ����

// template instantitaion ��� Ȯ�� �ϴ� ��� - 12 page
// 1. godbolt.org		=> ���� �����ϴ� ���.. !
// 2. cppinsights.io

// 3. ���� �����Ϸ��� ����ؼ� ����� �ڵ带 ���� Ȯ�� - 12page ����
//    => g++ �ҽ��̸�.cpp -S  �ϸ� "�ҽ��̸�.s" ���� �����˴ϴ�.
//    => cl  �ҽ��̸�.cpp /FAs    "�ҽ��̸�.asm" 

// 4. �Լ� �̸��� ����� ���� ���

// 5. C++20 �� std::source_location Ŭ���� ���
//  => basic4.cpp ����..

#include "fname.h"  // _FNAME_ �� �� ����� �ֽ��ϴ�.
template<typename T> 
T square(T a)
{
	// __func__ : ���� �Լ��� �̸��� ���� C++ ǥ�� ��ũ��
	//			  ��, ������ ����� ��µ��� �ʽ��ϴ�.
	//std::cout << __func__ << std::endl;

	// __FUNCSIG__         : �Լ� �̸� (signature ����). C++ ǥ�� �ƴ�. VC����
	// __PRETTY_FUNCTION__ : �Լ� �̸� (signature ����). C++ ǥ�� �ƴ�. g++����
	//std::cout << __FUNCSIG__ << std::endl;


	std::cout << _FNAME_ << std::endl;

	return a * a;
}

int main()
{
	square<int>(3);			// int square(int) �Լ� ����
	square<double>(3.3);
	square(3);
}

