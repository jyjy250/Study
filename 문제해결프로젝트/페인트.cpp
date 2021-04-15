#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<time.h>

using namespace std;

void paint(int seat[], int m);
void count(int seat[], int n);

int main()
{
	int n, m; // 좌석의 수, 색칠을 할 방법의수를 입력받을 변수 n,m
	scanf("%d %d", &n, &m); // 좌석의 수 , 색칙을 할 방법의수를 입력
	int* seat = new int[n + 1]; // 좌석의 색깔을 저장할 배열 seat, 0번좌석을 버리기위해 좌석의 수보다 1개더 길게 생성한다
	for (int i = 0; i < n + 1; i++)
		seat[i] = 0; // 일단 모두 0번 색깔로 칠한다
	paint(seat, m);
	count(seat, n);
	return 0;
}

void paint(int seat[], int m)
{
	int left; // 색칠할 가장 왼쪽 좌석의 번호를 저장할 변수 left
	int right; // 색칠할 가장 오른쪽 좌석의 번호를 저장할 변수 right
	int color; // 색깔의 번호를 입력받을 변수 color
	for (int i = 0; i < m; i++) // 색칠할 방법의 수만큼 반복해서 색칠
	{
		scanf("%d %d %d", &left, &right, &color);
		for (int j = left; j <= right; j++) // 좌석 한개씩 색칠
			seat[j] = color;

	}
}

void count(int seat[], int n)
{
	int cnt[100] = { 0, }; // 색깔이 총 0~99 까지 100개 이므로 길이100 짜리 배열 생성
	for (int i = 1; i < n + 1; i++) // cnt[색깔번호] +=1 이므로 cnt의 인덱스는 색깔의 번호를 뜻하고 요소는 색깔의 갯수를 의미하게된다.
		cnt[seat[i]] += 1;
	for (int i = 0; i < 100; i < i++)
	{
		if (cnt[i] == n) // 1가지 색깔로 칠할경우 밑의 알고리즘으로는 오류가 나기 때문에 예외로 여기서 처리한다
		{
			printf("%d\n", i);
			printf("%d\n", i);
			exit(0);
		}
	}
	int max = cnt[0]; // 가장 많은 색깔의 갯수를 저장할 변수 max
	int maxIdx = 0; // 가장 많은 색깔의 번호를 저장할 변수 maxIdx
	int min = cnt[0]; // 가장 적은 색깔의 갯수를 저장할 변수 min
	int minIdx = 0; // 가장 적은 색깔의 번호를 저장할 변수 minIdx
	for (int i = 0; i < 100; i++)
	{
		if (cnt[i] > max)
		{
			max = cnt[i];
			maxIdx = i;
		}
		if (cnt[i] != 0) // 색칠하지 않은 색깔은 제외 하기위한 조건문
			if (cnt[i] < min)
			{
				min = cnt[i];
				minIdx = i;
			}
	}
	printf("%d\n", maxIdx);
	printf("%d\n", minIdx);
}