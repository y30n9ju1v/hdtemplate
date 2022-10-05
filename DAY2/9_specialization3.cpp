// Object���� : Object<Ÿ��, ����>

// �ٽ� : primary ������ ���� ���� ( {} �� ���ٴ� �ǹ�)
// => �κ� Ư��ȭ ������ ����ϰڴٴ°�.
// => ��, ������ �־�� �մϴ�. ���� ������ �κ� Ư��ȭ �ȵ˴ϴ�.
template<typename T, int N>
struct Object;

// N==1 �϶��� ���� �κ� Ư��ȭ 
// => 1�� Ȯ�� �Ǿ����Ƿ� , int N �� ǥ�� ���� �ʽ��ϴ�.
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