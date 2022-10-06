
// 아래 코드가 "modern c++ design(2002)" 책의 저자가 2002년경에 만든 코드입니다.

template<int N> 
struct int2type
{
	enum { value = N };
};

int main()
{
	fn(0);
	fn(1); // 0, 1 은 모두 같은 타입(int) 입니다. 
			// 따라서, fn(0), fn(1) 은 같은 함수를 호출합니다.

	int2type<0> t0;
	int2type<1> t1;

	fn(t0);
	fn(t1); // t0, t1은 다른 타입입니다.
			// fn(t0), fn(t1)은 다른 함수를 호출합니다.
			// 77, 78 은 같은 타입입니다.
			// int2type<77>, int2type<78> 은 다른 타입입니다.
}