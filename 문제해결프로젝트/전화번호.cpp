#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<time.h>

using namespace std;


int main()
{
	int n; // 전화번호의 수를저장할 변수 n
	scanf("%d", &n); // 전화번호의 수 입력
	int* data = new int[n]; // 전화번호의 수만큼의 길이를 가진 배열 생성
	int cnt [10000] = { 0, }; // 0~9999 까지의 숫자의 갯수를 저장할 배열 생성, 0으로 초기화
	for (int i = 0; i < n; i++) // 전화번호 수만큼 반복해서 전화번호를 입력받는다
	{
		scanf("%d", &data[i]);
		cnt[data[i]] += 1; // cnt[전화번호] +=1 이므로 갯수가 카운팅된다
	}
	int idx = 0; // 가장많은 전화번호를 저장할 변수 idx
	for (int i = 0; i < 10000; i++) // 가장많은 전화번호를  변수 idx에 저장한다
	{
		if (cnt[i] > idx)
			idx = i;
	}
	printf("%04d ", idx); // 전화번호 0001은 cnt[1]의 갯수를 올리기때문에 %04d 형식으로 출력해준다
}