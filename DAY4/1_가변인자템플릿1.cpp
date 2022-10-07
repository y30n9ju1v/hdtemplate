// 175 page

// 아래 처럼 만들면.. 이 템플릿(틀) 사용시 
// => 타입 인자를 반드시 한개만 전달해야 합니다.
//template<typename T> class tuple  {};

// 가변인자 템플릿, C++11
// => 타입 인자를 임의 갯수를 받을수 있다.
// => 관례적으로 "T" 보다는 "Types", "Ts" 등, 복수형태로 표기 합니다.
//    "타입들" 이라는 의미
template<typename ... Types> class tuple 
{
};

// 인자가 "한개인 함수들을 생성"할수 있는 템플릿
// => "fn(3)" 처럼 반드시 인자를 한개만 보내야 합니다.
//template<typename T> void fn(T arg) {}


// 가변인자 함수 템플릿
// => 임의 갯수의 인자를 가지는 함수를 생성할수 있습니다.
template<typename ... Types> 
void fn(Types ... args) 
{
}

int main()
{
	tuple<> t0;
	tuple<int> t1;
	tuple<int, double> t2;
	tuple<int, double, char> t3; // Types : int, double, char


	fn(1, 3.4);
	fn(1, 3.4, 'A'); // Types : int, double, char
					 // args   : 1,   3.4,    'A'
}

