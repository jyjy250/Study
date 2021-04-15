#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>

using namespace std;

void findIndex(int data[], int n);


int main()
{
	int n;
	int* data;
	scanf("%d", &n);
	data = new int[n]; // 데이터 수만큼의 길이를 가진 int형 배열 선언
	for (int i = 0; i < n; i++)
		scanf("%d", &data[i]);
	findIndex(data, n);
	delete[] data;
	return 0;
}

void findIndex(int data[], int n)
{
	double average = 0;
	double* absol = new double[n]; // 절댓값을 저장하기위한 배열
	int minIdx = 0;
	for (int i = 0; i < n; i++) // 평균을 구하기위해 data를 전부 average에 더해줌
		average += data[i];
	average = average / n; // 평균을 구해줌
	for (int i = 0; i < n;i++)
		absol[i] = abs(average - data[i]); // abs 함수를 사용해서 절댓값을 저장해줌
	double minAbsol = absol[0]; // 절댓값 비교를 위해 minAbsol 변수를 초기화
	for (int i = 0; i < n; i++) // 비교를통해 구하고자 하는것을 구함
	{
		if (minAbsol > absol[i])
		{
			minAbsol = absol[i];
			minIdx = i + 1;
		}
	}
	printf("%d %d", minIdx, data[minIdx-1]);
}
