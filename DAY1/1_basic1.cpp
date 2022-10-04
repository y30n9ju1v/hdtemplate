// 5 page
// 함수 오버로딩 : 인자의 갯수나 타입이 다르면 동일이름의 함수를
//				 여러개 만들수 있다.
/*
int square(int a)
{
	return a * a;
}

double square(double a)
{
	return a * a;
}
*/
// 함수의 구현이 동일(유사) 하다면 함수를 만들지 말고
// 함수를 만드는 "틀(템플릿)을 제공"하자.
template<typename T>
T square(T a)
{
	return a * a;
}
int main()
{
	// 함수 템플릿(틀) 을 사용하는 정확한 표기법
//	square<int>(3);	// 1. 컴파일 시간에 "int square(int)"함수 생성
					// 2. 이 위치에 "call square<int>(3)" 기계어생성
//	square<double>(3.3);// 1. 컴파일 시간에 "double square(double)"함수 생성
						// 2. 이 위치에 "call square<double>(3.3)" 기계어생성
	
	// 함수 템플릿 사용시 타입을 생략하면 
	// 함수 인자를 보고 타입을 결정합니다.
	square(3);	// 3은 int 이므로 T=int 로 결정해서 함수 생성
	square(3.3);
}
// godbolt.org


// 코드 폭발(Code Bloat)
// => 템플릿 사용시 컴파일러가 너무 많은 "함수/클래스" 를 생성해서
//    코드 크기가 커지는 현상
// => 임베디드 같은 환경에서는 주의 해야 합니다.
//    (다양한 방법으로 어느정도 해결가능 합니다.)









//DAY1.zip 압축 풀고, Visual studio 에서 열어 보세요..

//1. 버전 설정 변경해야 합니다(프로젝트 메뉴, "DAY1 속성" 메뉴 선택)
// => 플랫폼 도구집합
// => 윈도우 SDK 버전 최신버전으로 설정
// => Ctrl + F5 로 빌드해서 에러 없는지 확인해 보세요

// 2. 빌드 환경 : "Debug", "x64" 환경

// 3. 소스 파일을 빌드에서 "제외/포함" 하는 방법.

// "cpp2" : C++언어의 핵심 문법만 남겨 놓고
//          필요 없는 부분을 제거해서 "simple" 하게. 
//          복잡도를 줄이자.!