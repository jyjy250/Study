#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<time.h>
#include<cmath>

using namespace std;

void bubbleSort(int data[], int n);

int main()
{
	int n; // 데이터 수를 입력받을 변수 n
	int* data; // 데이터를 입력받을 배열 data
	scanf("%d", &n); // 데이터 수를 입력
	data = new int[n]; // 데이터 수 만큼의 길이를 가진 배열 생성
	for (int i = 0; i < n; i++) // 데이터 입력
		scanf("%d", &data[i]); 
	bubbleSort(data, n);
	delete[] data;
	return 0;
}

void bubbleSort(int data[], int n)
{
	for (int i = 0; i < n; i++) // 아래 과정을 n번 반복
	{
		for (int j = 0; j < n - 1; j++) // data[0]~data[n-2] 번칸의 숫자가 data[1]~ data[n-1] 칸의 숫자 보다 크면 두값의 위치를 교환한다
		{
			if (data[j] > data[j + 1])
			{
				int temp = data[j]; // 값을 교환하기위해 잠깐 변수값을 저장할 변수 temp
				data[j] = data[j + 1];
				data[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < n; i++) // 버블정렬한 배열 출력
		printf("%d ", data[i]);
}