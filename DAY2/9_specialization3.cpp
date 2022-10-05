// Object사용법 : Object<타입, 정수>

// 핵심 : primary 버전은 선언만 제공 ( {} 가 없다는 의미)
// => 부분 특수화 버전만 사용하겠다는것.
// => 단, 선언은 있어야 합니다. 선언도 없으면 부분 특수화 안됩니다.
template<typename T, int N>
struct Object;

// N==1 일때를 위한 부분 특수화 
// => 1로 확정 되었으므로 , int N 은 표기 하지 않습니다.
template<typename T>
struct Object<T, 1>
{	
};
// N == 2
template<typename T>
struct Object<T, 2>
{	
};

int main()
{
	Object<int, 1> obj1;
	Object<int, 2> obj2;
	Object<int, 3> obj3; // error
}