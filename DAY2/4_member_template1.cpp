
// 53page
template<typename T>
class Object
{
public:
	void mf1(int n) {}	// 함수 템플릿 아닙니다.
						// 인자는 "int" 입니다.
	
	void mf2(T   n) {}	// 함수 템플릿 아닙니다.
						// 클래스 템플릿의  "일반 멤버 함수" 입니다.
						// "Object<double> obj" 로 객체 생성시
						// "mf2(double)" 로 함수는 결정 됩니다.

	// 아래 코드가 "함수 템플릿" 입니다.
	// "클래스 템플릿"의 "멤버 함수 템플릿"
	template<typename U>
	void mf3(U n) {}
};

int main()
{
	Object<int>    obj1;

	obj1.mf1(3);	// mf1은 인자는 항상 "int"
	obj1.mf2(3);	// mf2의 인자는 객체를 만들때 전달한 타입 "int"
	obj1.mf2(3.4);	// 에러는 아니지만 인자가 int 인 함수에 
					// double 전달데이타 손실 발생

	obj1.mf3(3);	// mf3(int) 함수 생성
	obj1.mf3(3.4);	// mf3(double) 함수 생성

	// 결국 "mf2" 은 템플릿 이 아니므로 "멤버 함수가 한개" 인데..
	// "mf3" 은 함수 템플릿 이므로 "여러개의 mf3" 가 생성될수 있습니다.
}