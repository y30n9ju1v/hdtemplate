// 템플릿은 틀 입니다.
// 사용한 경우만 인스턴스화 됩니다.
template<typename T> void fn(T value, int)
{
	*value = 10;
}

template<typename T> void fn(T value, double)
{
}

int main()
{
//	fn(1, 3);	// fn(T, int) 버전 사용. 인스턴스화 되면 에러.

	fn(1, 3.3); // fn(T, double) 사용.
				// fn(T, int) 버전은 인스턴스화 안되므로 에러 아님.
}