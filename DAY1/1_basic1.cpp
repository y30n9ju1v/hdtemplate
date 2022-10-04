// 5 page
int square(int a)
{
	return a * a;
}

double square(double a)
{
	return a * a;
}

int main()
{
	square(3);	
	square(3.3);
}



//DAY1.zip 압축 풀고, Visual studio 에서 열어 보세요..

//1. 버전 설정 변경해야 합니다(프로젝트 메뉴, "DAY1 속성" 메뉴 선택)
// => 플랫폼 도구집합
// => 윈도우 SDK 버전 최신버전으로 설정
// => Ctrl + F5 로 빌드해서 에러 없는지 확인해 보세요

// 2. 빌드 환경 : "Debug", "x64" 환경

// 3. 소스 파일을 빌드에서 "제외/포함" 하는 방법.