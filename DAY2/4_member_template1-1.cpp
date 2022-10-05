
// 53page
template<typename T>
class Object
{
public:
	void mf1(int n);
	void mf2(T   n);
	template<typename U>
	void mf3(U n);
};

// mf1, mf2, mf3 외부 구현 해 보세요.

template<typename T>
void Object<T>::mf1(int n) 
{
}
template<typename T>
void Object<T>::mf2(T n)
{
}

//template<typename T, typename U>			// 1 => 이 표기는 클래스 템플릿의 인자가 2개라는 의미
template<typename T> template<typename U>	// 2 => 답. "클래스도 템플릿 인데, 멤버함수도 템플릿 이라는 의미"
void Object<T>::mf3(U n)
{
}



int main()
{

}