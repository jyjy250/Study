#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<time.h>
#include<cmath>

using namespace std;

bool isInside(int x, int y, int R);
void CirclePixelCount(int R);

int main()
{
	int caseSize; // 테스트 케이스의 수를 입력받을 변수 caseSize
	int* R; // 반지름을 입력받을 배열 R
	scanf("%d", &caseSize); // 테스트 케이스 수 입력 
	R = new int[caseSize]; // 테스트 케이스 수만큼의 길이를 가진 배열 생성
	for (int i = 0; i < caseSize; i++) // 반지름을 입력
		scanf("%d", &R[i]);
	for (int i = 0; i < caseSize; i++) // 테스트 케이스 수만큼 반복실행
	{
		printf("#%d\n", i + 1);
		CirclePixelCount(R[i]);
	}
	delete[] R;
	return 0;
}

bool isInside(int x, int y, int R)
{
	if (pow(x, 2) + pow(y, 2) < pow(R, 2)) // x^2+y^2 < R^2 일경우 픽셀은 원안에 있다고 판단
		return true;
	else // 그외의 경우는 바깥에 있다고 판단
		return false;
}
void CirclePixelCount(int R)
{
	long long pixel=0;
	int height;
	for (int i = 0; i < R; i++)
	{
		height = R; // 
		for (int j = 0; j < R; j++)
		{
			if (isInside(i, height, R)) // 원안에 있다면 반복문을 나가서 pixel에 height값을 더해줌
				break;
			else
				height--; // 원밖에 있다면 height값을 1 줄인뒤 다시 시도
		}
		pixel += height+1; // 구한 높이+1 만큼의 픽셀이 있음
	}
	printf("%lld\n", 4*pixel); // 하나의 사분면의 개수를 구해서 4를 곱해준뒤 출력
}
