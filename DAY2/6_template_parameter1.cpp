// 92 page

// ���ø� �Ķ���ʹ� 3���� ������ �ֽ��ϴ�.
// 1. type
// 2. non-type
// 3. template

template<typename T> class list 
{
};
	
template<typename T,					// template "type parameter"
	     int N,							// template "non-type parameter"
	     template<typename> class C>	// template "template parameter"
class Object
{
};

int main()
{
//	Object<int, 5, list<int> > obj; // error. list<int> �� ���ø��� �ƴ� Ÿ��
	Object<int, 5, list      > obj; // ok.    list �� ���ø�
}