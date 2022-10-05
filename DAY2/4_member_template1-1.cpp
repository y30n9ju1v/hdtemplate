
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
void Object::mf1(int n) 
{
}
void Object::mf2(T n)
{
}
void Object::mf3(U n)
{
}



int main()
{

}