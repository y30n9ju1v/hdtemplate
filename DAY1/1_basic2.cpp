// 7 page : typename, class, auto

// Ÿ�� paramter �� ǥ���ϴ� ���
// 
// 1. class - C++ ��� ó���� ����ϴ� ���
template<class T> 
T square1(T a)
{
	return a * a;
}

// 2. typename 
template<typename T>
T square2(T a)
{
	return a * a;
}

// 3. C++20 "auto" ��밡��
//    => �Ʒ� �ڵ尡 ���ø� �Դϴ�.
//    => �� square1, square2 �� �Ϻ��� ������ �ڵ��Դϴ�.
auto square3(auto a)  
{
	return a * a;
}

int main()
{
	// �ٽ� 2. ��� ����
	// int : template argument(parameter) - ������ �ð��� ����
	// 3   : function argument(parameter) - ����   �ð��� ����
	square3<int>(3);
}