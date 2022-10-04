template<typename T>
class Object
{
	T value;
public:
	void mf()
	{
		*value = 10; 
	}
};

int main()
{
	// 지연된 인스 턴스화(lazy instantiation)
	// => 클래스 템플릿의 멤버 함수중에서 사용된 것만 인스턴스화가 됩니다.
	// => 사용되지 않은 멤버 함수는 인스턴스화가 되지 않습니다.

	Object<int> obj; // 이순간, 멤버 데이타 "value" 가 스택에 놓이게 됩니다.
					// 따라서, 객체를 생성하면 "멤버 데이타"는 사용하게 되는것 입니다.

	obj.mf();	// 멤버 함수는 호출하는 코드가 있어야 "사용하는 것" 이 됩니다.
}
