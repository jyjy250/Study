#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<time.h>
#include<cmath>

using namespace std;

void bubbleSort(int data[], int n);
void isConsecutive(int data[], int n);

int main()
{
	int n; // 데이터 수를 입력받을 변수 n
	int* data; // 데이터를 입력받을 배열 data
	scanf("%d", &n); // 데이터 수를 입력
	data = new int[n]; // 데이터 수 만큼의 길이를 가진 배열 생성
	for (int i = 0; i < n; i++) // 데이터 입력
		scanf("%d", &data[i]);
	bubbleSort(data, n); // 입력 받은 데이터를 버블정렬한다
	isConsecutive(data, n);
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
}

void isConsecutive(int data[], int n)
{
	int count=0; // 연속적인 수열인지 판별하기위한 count 변수
	for (int i = 0; i < n - 1; i++)
	{
		if (data[i] + 1 != data[i + 1])
			printf("NO"); // 연속적인 수열이 아니라면 NO 출력
		else if(data[i] + 1 == data[i + 1])
			count++; // 연속적인 수열 이라면 count 값 증가
	}
	if (count == n - 1) // n-1번 반복해서 한번도 if문의 조건에 걸리지 않았다면 연속적인 수열이다
		printf("YES");
}