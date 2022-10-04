#include <iostream>
#include <list>
#include <queue>
#include <vector>
#include <funtional>

// template 의 종류 - 8 page
// => 4가지가 있습니다.

// 1. 함수 템플릿 => 함수를 만드는 틀
template<typename T> T square(T a)
{
	return a * a;
}

// 2. 클래스 템플릿 => 클래스를 만드는 틀(내일 자세히 배우게 됩니다.)
template<typename T> class Vector
{
	T* buff;
};

// 3. 변수(variable) 템플릿 => 내일 부터 많이 사용
// => C++11 에서 소개된 문법
// => 요즘에 아주 널리 사용됩니다.(내일부터 배우게 됩니다.)
template<typename T>
constexpr T pi = static_cast<T>(3.141692);

double d = pi<double>; // static_cast<double>(3.141592)
float f  = pi<float>;  // static_cast<float>(3.141592) 


// 4. using template 
// => C++11 부터 추가
// => 기존 템플릿의 별명 만들기.
// => 기존 템플릿이 복잡할때 사용
template<typename T>
using MyList = std::list<T>;

MyList<int> s; // std::list<int>

template<typename T>
using pqueue = std::priority_queue<T, std::vector<T>, std::greater<T>>;
