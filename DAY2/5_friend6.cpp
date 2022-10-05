// 5_friend6.cpp

// "1개" 클래스가 "1개" 함수와 friend 관계

struct Object1
{
	friend void f1();
};
void f1() {}

//=================================================
// "N개" 클래스가 "1개" 함수와 friend 관계
template<typename T>
struct Object2
{
	friend void f2();
};
void f2() {}

//===========================================
// "1개" 클래스가 "N개" 함수(f3(int), f3(double) 등) 와 friend 관계 
struct Object3
{
	template<typename T> friend void f3(T arg);
};
template<typename T> void f3(T arg) {}

//======================================
// 핵심!!
// "N개" 클래스가 "M개" 함수와 friend 관계 
template<typename U> struct Object4
{
	template<typename T> friend void f4(T arg);
};
template<typename T> void f4(T arg) {}

//=====================================
// 핵심 : Object5<int>    <=> f5(int)
//       Object5<double> <=> f5(double) 
// 
// 위처럼 한개 타입이 한개 함수와 friend 되게 할수 없을까 ?

template<typename U> struct Object5
{
	// 아래 처럼 friend 함수의 구현 자체를 class 안에 만들면 됩니다.
	friend void f5(T arg)
	{
	}
};

// 위 5개  경우가 모두 이해 되신분은
// friend7번 만드세요.  5번 복사한후, 주석 지우고 코드 생각해 보세요..
// 