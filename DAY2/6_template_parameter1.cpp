// 92 page

// 템플릿 파라미터는 3가지 종류가 있습니다.
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
//	Object<int, 5, list<int> > obj; // error. list<int> 는 템플릿이 아닌 타입
	Object<int, 5, list      > obj; // ok.    list 는 템플릿
}