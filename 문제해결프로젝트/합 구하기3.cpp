#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>

using namespace std;

void getAnswer(int n);


int main()
{
	int n;
	scanf("%d", &n);
	getAnswer(n);
	return 0;
}

void getAnswer(int n)
{
	long long answer = 0;
	int count = 1;
	for (int i = 1; i <= n; i++) //answer에 다시 1부터 더해지게  count 값을 1로 초기화
	{
		count = 1;
		for (int j = 1; j <= i; j++) // 1이상 i 이하 자연수의 합을 count값을 1씩 늘려가며 answer에 더함
		{
			answer += count;
			count++;
		}
	}
	printf("%ld", answer);
}
