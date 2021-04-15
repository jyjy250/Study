#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<cmath>
#include<time.h>
#include<vector>

using namespace std;

int ccount = 0; // 연산 횟수를 저장할 전역변수 ccount

int Double(int changeto);
int Addone(int changeto);
bool isAddedOne(int changeto);
void run(int num, int changeto, int maxcount);
int getMaxCount(int num, int changeto);

int main()
{
	int num, changeto; // 정수 A를 입력받을 변수 num, B를 입력받을 변수 changeto
	int maxcount; // 무한 루프를 방지하기 위해서 최대연산횟수를 저장할 변수 maxcount
	scanf("%d %d", &num, &changeto); // 정수 A와 B 입력
	clock_t start = clock();
	maxcount = getMaxCount(num, changeto); // getMaxCount 함수를 통해 maxcount 값을 저장
	run(num, changeto, maxcount); // 핵심 함수
	clock_t end = clock();
	printf("실행시간: %lf초\n", (double)(end - start) / CLOCKS_PER_SEC);
}

int Double(int changeto) // 연산횟수를 저장하고있는 전역변수 ccount값을 증가시키고 매개변수를 2로 나눈값을 반환 하는 함수
{
	ccount++;
	return changeto / 2;
}

int Addone(int changeto) // 연산횟수를 저장하고있는 전역변수 ccount값을 증가시키고 매개변수에서 1을 뺀다음 10으로 나눈 값을 반환 하는 함수
{
	ccount++;
	return ((changeto - 1) / 10);
}

void run(int num, int changeto, int maxcount) // changeto 변수를 num 변수로 만드는 과정
{
	while (1) // 연산횟수가 maxcount에 도달하기전까지 무한반복
	{
		if (ccount == maxcount) // 연산 횟수가 max count에 도달 했는데도 (changeto == num) 조건문에 걸리지 않은 경우 , 무한 루프이고 바꿀수 없는 경우 이므로 -1출력후 반복문 탈출
		{
			printf("-1\n"); 
			break;
		}
		if (isAddedOne(changeto)) // 매개 변수 끝자리가 1로 끝난다면 무조건 전 연산이 1을 숫자 가장 오른쪽에 추가하는 연산이다
		{
			changeto = Addone(changeto);
		}
		else // 매개변수 끝자리가 1로 끝나지 않은 경우에는 전연산이 2를 곱하는 것이였다고 간주한다
		{
			changeto = Double(changeto);
		}
		if (changeto == num) // changeto 변수가 num과 같다면 반복문 탈출
			break;
	}
	if (ccount != maxcount) // 출력
		printf("%d\n", ccount + 1);
}

bool isAddedOne(int changeto) // 매개변수 끝자리가 1로 끝나는지 확인 하는 함수
{
	if (changeto % 10 == 1) // 10으로 나누었는데 나머지가 1이라면 끝자리가 1이다
		return true;
	else
		return false;
}

int getMaxCount(int num, int changeto) 
{
	int count=0;
	while (1) // A와 B가 양수이므로 값을 가장 작게 증가시키는 연산은 두배하는 연산이다. 그러므로 2배하는 연산만 진행 했을때에 MaxCount를 구할수있다.
	{
		if (num < changeto)
		{
			num *= 2;
			count++;
		}
		else
			break;
	}
	return count;
}











