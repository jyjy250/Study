#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<time.h>
#include<vector>

using namespace std;

#define MAX 100001 // 시리얼 번호가 1이상 10만 이하 이므로 개수를 세기 위해 100001으로 MAX를 정의한다

void bubbleSort(vector<int> data);

int main()
{
	int n; // 시리얼 번호의 수를 입력받을 변수 n
	scanf("%d", &n); // 시리얼 번호 수 입력
	int data[MAX] = {0, }; // 인덱스 0~10000 까지의 원소를 0으로 초기화 한다
	int serialnum;
	for (int i = 0; i < n; i++) // 시리얼 번호를 입력받고 입력받은 시리얼 번호의 갯수를 카운트한다
	{
		scanf("%d", &serialnum);
		data[serialnum]++;
	}
	vector<int> serial; // 한번만 응모한 시리얼 번호를 저장하기 위한 벡터 생성
	for (int i = 0; i < MAX; i++)
	{
		if (data[i] == 1) // 딱 한번만 응모한 시리얼 번호를 벡터에 저장한다
			serial.push_back(i);
	}
	bubbleSort(serial); // 저장된 시리얼 넘버를 버블정렬로 오름차순으로 정령해서 출력한다
}




void bubbleSort(vector<int> data)
{
	for (int i = 0; i < data.size(); i++) // 아래 과정을 n번 반복
	{
		for (int j = 0; j < data.size() - 1; j++) // data[0]~data[n-2] 번칸의 숫자가 data[1]~ data[n-1] 칸의 숫자 보다 크면 두값의 위치를 교환한다
		{
			if (data[j] > data[j + 1])
			{
				int temp = data[j]; // 값을 교환하기위해 잠깐 변수값을 저장할 변수 temp
				data[j] = data[j + 1];
				data[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < data.size(); i++) // 버블정렬한 배열 출력
		printf("%d ", data[i]);
}
