#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>

using namespace std;
void getMaximumHeight(int height[], int month[], int n, int m);

int main()
{
	int n, m; //도토리의 수를 나타내는 변수 n, 현재 달을 입력받는 변수 m
	int* height; // i번째 도토리의 키를 나타내기 위한 배열 height
	int* month; // i번째 도토리의 생일을 나타내기 위한 배열 month
	scanf("%d", &n); //도토리의 수를 입력받음
	height = new int[n]; //도토리의 수만큼의 길이를 가지는 배열을 생성
	month = new int[n]; //도토리의 수만큼의 길이를 가지는 배열을 생성
	for (int i = 0; i < n; i++)//i번쨰 도토리의 키를 입력받음
		scanf("%d", &height[i]);
	for (int i = 0; i < n; i++)//i번쨰 도토리의 생일을 입력받음
		scanf("%d", &month[i]);
	scanf("%d", &m);// 현재달을 입력받음
	getMaximumHeight(height, month, n, m); // 생일이있는 도도리들중 가장 키가 큰 도토리의 키를 출력하는 함수
	delete[] height; // 메모리 공간에서 height 배열삭제
	delete[] month; // 메모리 공간에서 month 배열 삭제
	return 0;
}

void getMaximumHeight(int height[], int month[], int n, int m)
{
	int maxheight = -1; // 밑의 조건문에서 생일이 해당 달에 속한 도토리가 없다면 -1을 출력할수있게 -1로 초기화
	for (int i = 0; i < n; i++) 
	{
		if (month[i] == m)
			if (maxheight < height[i]) // 이중 조건문 생일이 해당달에 있고 지금까지 저장해온 maxheight보다 키가 크다면 maxheight을 업데이트함
				maxheight = height[i];

	}
	printf("%d", maxheight); // 출력
}