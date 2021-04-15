#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>

using namespace std;
void isOrdered(int n, int data[]);

int main()
{
	int n; // 학생수를 나타내는 변수 n
	int* data; // 학생들의 키를 나타내고 학생수만큼의 길이를 가진 배열 data
	scanf("%d", &n); // 학생수를 입력받음
	data = new int[n]; // 학생수만큼의 길이를 가진 배열 생성
	for (int i = 0; i < n; i++) // 배열에 키를 입력받음
		scanf("%d", &data[i]);
	isOrdered(n, data); // 오름차순인지 아닌지 판단하는 함수 출력
	delete[] data; // data 배열 메모리에서 삭제
	return 0;
}

void isOrdered(int n, int data[])
{
	bool check = true; // 오름차순인지를 판별하기 위한 변수
	for (int i = 0; i < n - 1; i++)
	{
		if (data[i] > data[i + 1])
		{
			printf("NO"); // 오름차순이 아니라면 NO를 출력
			check = false; // 오름차순이 아니므로 check에 false값을 대입
		}
	}
	if (check)
		printf("YES"); // 오름차순인 경우에는 YES 를 출력
}
