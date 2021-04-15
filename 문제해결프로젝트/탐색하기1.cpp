#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>

void findIndex(int data[], int n, int m);


int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	int* data = new int[n];
	data = new int[n]; //n길이만큼의 배열을 생성
	for (int i = 0; i < n; i++) // 배열을 채워넣음
		scanf("%d", &data[i]);
	findIndex(data, n, m);
	delete[] data;
	return 0;
}

void findIndex(int data[], int n ,int m)
{
	for (int i = 0; i < n; i++)
	{
		if (data[i] == m)// 찾는 데이터를 발견하면 인덱스값 출력
		{
			printf("%d", i);
			break;
		}
		if (i == n - 1) // 배열끝까지 찾아보았지만 없다면 -1 출력
			printf("-1");
	}
}
