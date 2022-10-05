template<typename T> 
void fn(T arg) 
{
}

int main()
{
	// auto 의 타입 추론 방법은 
	// template 과 동일 합니다

	const int c = 10;
	fn(c);  // "T    arg = c" 이므로 c를 보고 T 의 타입을 추론
			// "auto arg = c" 와 동일합니다. c를 보고 auto 추론


	auto   a1 = c;	// "T a1 = c" 와 같으므로 , 규칙 1 적용
					// "c 가 가진 const, volatile, reference" 제거후 결정
					// auto = int,  a1 = int

	auto&  a2 = c;	// "T& a2 = c" 이므로, 규칙 2.
					// "c 가 가진 reference 만 제거하고 타입 결정"
					// auto = const int,  a2 = const int&

	int n = 10;
	// auto&& 는 T&& 와 같은 규칙
	auto&& a3 = 3;	// 3은 rvalue
					// auto = int,  a3 = int&&
				   
	auto&& a4 = n;	// n은 lvalue
					// auto = int&	a4 = int& && => int&

	// 배열과 auto
	const int v[3] = { 1,2,3 };

	auto a5 = v;	// "T a5 = v", 배열을 값 타입으로 받는 경우
					// "const int* a5 = v"
					// auto : const int*    a5 : const int*

	auto& a6 = v;  // "T& a6 = v"
				   // T(auto) : const int[3], a6 : const int (&a6)[3]

	int x[3];
	int(&r)[3] = x;  // 배열을 가리키는 참조 라는 문법입니다.
	int(*p)[3] = &x; // 배열을 가리키는 포인터(C언어) 입니다.
}

// template 타입 추론 규칙과 auto 는 완벽히 동일합니다.
// => 그런데, auto 를 가지고 학습을 하면, 확인할 방법이 없습니다.
//    "auto 가 어떤 타입이 되었는지???"
// => template 은 확인 가능합니다.

const int c = 1;
auto a = c;  // a의 타입을 조사하려면

template<typename T> void fn(T a) {}  // 이렇게 만들고 여기서 함수 이름출력
fn(c); 