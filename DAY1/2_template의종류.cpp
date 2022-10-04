#include <iostream>
#include <list>
#include <queue>
#include <vector>
#include <funtional>

// template �� ���� - 8 page
// => 4������ �ֽ��ϴ�.

// 1. �Լ� ���ø� => �Լ��� ����� Ʋ
template<typename T> T square(T a)
{
	return a * a;
}

// 2. Ŭ���� ���ø� => Ŭ������ ����� Ʋ(���� �ڼ��� ���� �˴ϴ�.)
template<typename T> class Vector
{
	T* buff;
};

// 3. ����(variable) ���ø� => ���� ���� ���� ���
// => C++11 ���� �Ұ��� ����
// => ���� ���� �θ� ���˴ϴ�.(���Ϻ��� ���� �˴ϴ�.)
template<typename T>
constexpr T pi = static_cast<T>(3.141692);

double d = pi<double>; // static_cast<double>(3.141592)
float f  = pi<float>;  // static_cast<float>(3.141592) 


// 4. using template 
// => C++11 ���� �߰�
// => ���� ���ø��� ���� �����.
// => ���� ���ø��� �����Ҷ� ���
template<typename T>
using MyList = std::list<T>;

MyList<int> s; // std::list<int>

template<typename T>
using pqueue = std::priority_queue<T, std::vector<T>, std::greater<T>>;
