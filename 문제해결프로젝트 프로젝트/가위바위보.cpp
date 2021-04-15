#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<time.h>

using namespace std;
void run(int r, int n, char* rsp, char** frsp);

int main()
{
	int r,n; // 라운드 수를 입력받을 변수 r, 친구의 수를 입력받을 변수 n
	char* rsp; // 전남이가 낸 모양을 저장하는 배열
	char** frsp; // 전남이의 친구가 낸 모양을 저장하는 배열
	scanf("%d", &r); // 라운드 수 입력
	rsp = new char[r+1]; // 전남이가 낸 모양을 저장하는 배열 생성
	scanf("%s", rsp); // 전남이가 낸 모양 입력
	scanf("%d", &n); // 친구의 숫 입력
	frsp = new char* [n];
	for (int i = 0; i < n; i++) // n X r+1 크기의 2차원 배열로 전남이의 친구가 낸모양을 저장하는 배열을 생성
		frsp[i] = new char[r + 1];
	for (int i = 0; i < n; i++) // 친구들이 낸 모양들을 입력
		scanf("%s", frsp[i]);
	clock_t start = clock();
	run(r, n, rsp, frsp); // 가위바위보 실행
	clock_t end = clock();
	printf("실행시간: %lf초\n", (double)(end - start) / CLOCKS_PER_SEC);
	return 0;
}

void run(int r, int n, char* rsp, char** frsp)
{
	int point = 0; //전남이의 점수를 저장할 변수 선언
	int maxPoint = 0; // 전남이가 친구들이 무엇을 낼지 미리 알고있다고 가정할때 얻을 수 있는 점수를 저장할 변수 선언
	char* predict = new char[r + 1]; // 전남이가 친구들이 무엇을 낼지 미리 알고있다고 가정할때 내야할 모양을 가진 배열
	int countr = 0; // 위 predict 배열을 만들기 위해 선언한 변수
	int counts = 0; // 위 predict 배열을 만들기 위해 선언한 변수
	int countp = 0; // 위 predict 배열을 만들기 위해 선언한 변수
	int countmax= 0; // 위 predict 배열을 만들기 위해 선언한 변수
	for (int i = 0; i < r; i++)
	{
		countr = 0; // predict 배열을 정확히 만들기 위하여 초기화
		counts = 0; // predict 배열을 정확히 만들기 위하여 초기화
 		countp = 0; // predict 배열을 정확히 만들기 위하여 초기화
		for (int j = 0; j < n; j++) // point 변수를 결정하는 알고리즘
		{
			if (rsp[i] == 'R') // 전남이가 바위일경우
			{
				if (frsp[j][i] == 'R') // 비긴경우
					point += 1;
				if (frsp[j][i] == 'S') // 이긴경우
					point += 2;
			}
			if (rsp[i] == 'S') // 전남이가 가위일경우
			{
				if (frsp[j][i] == 'S') // 비긴경우
					point += 1;
				if (frsp[j][i] == 'P') // 이긴경우
					point += 2;
			}
			if (rsp[i] == 'P') // 전남이가 보일경우
			{
				if (frsp[j][i] == 'P') // 비긴경우
					point += 1;
				if (frsp[j][i] == 'R') // 이긴경우
					point += 2;
			}
		}
		for (int j = 0; j < n; j++) // i+1 라운드에 친구들이 낸 가위,바위,보 숫자를 체크한다
		{
			if (frsp[j][i] == 'R')
				countr++;
			if (frsp[j][i] == 'S')
				counts++;
			if (frsp[j][i] == 'P')
				countp++;
		}
		countmax = (((countr > counts) ? countr : counts) > countp) ? ((countr > counts) ? countr : counts) : countp; // 가위,바위,보 중 가장많이나온 모양의 숫자를 countmax에 대입한다
		if (countmax == countr) // 바위가 가장 많다면 보를 내는게 현명하다
			predict[i] = 'P';
		if (countmax == counts) // 가위가 가장 많다면 바위를 내는게 현명하다
			predict[i] = 'R';
		if (countmax == countp) // 보가 가장 많다면 가위를 내는게 현명하다
			predict[i] = 'S';
	}
	for (int i = 0; i < r; i++) // 완성된 predict 배열로 가위바위보를 진행한다
	{
		for (int j = 0; j < n; j++)
		{
			if (predict[i] == 'R')
			{
				if (frsp[j][i] == 'R')
					maxPoint += 1;
				if (frsp[j][i] == 'S')
					maxPoint += 2;
			}
			if (predict[i] == 'S')
			{
				if (frsp[j][i] == 'S')
					maxPoint += 1;
				if (frsp[j][i] == 'P')
					maxPoint += 2;
			}
			if (predict[i] == 'P')
			{
				if (frsp[j][i] == 'P')
					maxPoint += 1;
				if (frsp[j][i] == 'R')
					maxPoint += 2;
			}
		}
	}
	printf("%d\n", point);
	printf("%d\n", maxPoint);
}
