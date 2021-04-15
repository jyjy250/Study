#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

class Square // 사각형에대한 정보를 저장하기 위한 클래스 Square
{
public:
	int leftloc; // 왼쪽모소리의 x좌표를 저장할 변수 leftloc
	int rightloc; // 오른쪽모소리의 x좌표를 저장할 변수 right loc
	int toploc; // 위쪽 모소리의 y좌표를 저장할 변수 toploc
	int bottomloc; // 아래쪽 모소리의 y좌표를 저장할 변수 bottomoc
	Square(int ax, int ay, int bx, int by) 
	{
		leftloc = min(ax, bx);
		rightloc = max(ax, bx);
		toploc = max(ay, by);
		bottomloc = min(ay, by);
	}
};

void getArea(Square a, Square b);

int main()
{
	int t; // 테스트 케이스의 수를 저장할 변수 t
	cin >> t; // 테스트 케이스의 수 입력
	int ax, ay, bx, by, px, py, qx, qy; // a,b는 첫번째 사각형을 이루는 서로 대각선으로 마주보는 두점의 좌표 p와 q는 두번째 직사각형을 이루는 서로 대각선으로 마주보는 두점의 좌표
	for (int i = 0; i < t; i++)
	{
		cin >> ax >> ay >> bx >> by >> px >> py >> qx >> qy; // 좌표입력
		Square a(ax, ay, bx, by); // 입력받은 좌표로 사각형 생성
		Square b(px, py, qx, qy); // 입력받은 좌표로 사각형 생성
		getArea(a, b); // 겹치는 부분의 넓이를 계산
	}
}

void getArea(Square a, Square b)
{
	int leftloc = max(a.leftloc, b.leftloc); // 겹치는 부분이 그려낸 사각형의 왼쪽 모소리의 x좌표를 저장할 변수 leftloc
	int rightloc = min(a.rightloc, b.rightloc); // 겹치는 부분이 그려낸 사각형의 오른쪽 모소리의 x좌표를 저장할 변수 rightloc
	int toploc = min(a.toploc, b.toploc); // 겹치는 부분이 그려낸 사각형의 위쪽 모소리의 y좌표를 저장할 변수 toploc
	int bottomloc = max(a.bottomloc, b.bottomloc); // 겹치는 부분이 그려낸 사각형의 아래쪽 모소리의 y좌표를 저장할 변수 bottomloc
	cout << (rightloc - leftloc) * (toploc - bottomloc) << endl;
}