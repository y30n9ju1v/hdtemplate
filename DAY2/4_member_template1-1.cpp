
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

// mf1, mf2, mf3 �ܺ� ���� �� ������.

template<typename T>
void Object<T>::mf1(int n) 
{
}
template<typename T>
void Object<T>::mf2(T n)
{
}

//template<typename T, typename U>			// 1 => �� ǥ��� Ŭ���� ���ø��� ���ڰ� 2����� �ǹ�
template<typename T> template<typename U>	// 2 => ��. "Ŭ������ ���ø� �ε�, ����Լ��� ���ø� �̶�� �ǹ�"
void Object<T>::mf3(U n)
{
}



int main()
{

}