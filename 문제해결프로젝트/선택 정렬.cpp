#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>

using namespace std;

void selectionSort(int data[], int n);


int main()
{
	int n;
	int* data;
	scanf("%d", &n);
	data = new int[n]; // 데이터 수만큼의 길이를 가진 int형 배열 선언
	for (int i = 0; i < n; i++)
		scanf("%d", &data[i]);
	selectionSort(data, n);
	for (int i = 0; i < n; i++)
		printf("%d ", data[i]);
	delete[] data;
	return 0;
}

void selectionSort(int data[], int n)
{
	int keep=0;
	int min = 0;
	int idx = 0;
	for (int i = 0; i < n; i++)
	{
		min = data[i];
		for (int j = i; j < n; j++)
			if (min > data[j]) //최소값을 구해서 인덱스와 값을저장해놓음
			{
				min = data[j];
				idx = j;
			}
		if (data[i] != min) // 32번쨰 라인에서 min값을 초기화 해주었는데 이후에 과정에서 min값이 바뀌지 않는다면 꼬이기 때문에 if문을 사용
		{                   // 값의 교환
			keep = data[i];
			data[i] = min;
			data[idx] = keep;
		}
	}
}
