#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<time.h>

using namespace std;

bool isPrime(int testCase);

int main()
{
	int caseSize; // 테스트케이스의 갯수를 입력받을 변수 caseSize
	int* testCase; // 테스트케이스의 숫자를 입력받을 배열 testCase
	scanf("%d", &caseSize); // 테스트 케이스의 갯수를 입력
	testCase = new int[caseSize]; // 테스트 케이스의 갯수만큼의 길이를 가진 배열 생성
	for (int i = 0; i < caseSize; i++) // 배열에 테스트 케이스별로 숫자를 입력
		scanf("%d", &testCase[i]); 
	for (int i = 0; i < caseSize; i++) // 테스트 케이스 별로 소수인지 아닌지 판단후 알맞게 출력
	{
		printf("Case #%d\n", i + 1);
		if (isPrime(testCase[i])) // 소수인경우
			printf("YES\n");
		else // 소수가 아닌경우
			printf("NO\n");
	}
	delete[] testCase;
	return 0;
}

bool isPrime(int testCase) // 테스트 케이스의 숫자를 입력받아 소수인지 아닌지 bool값을 return해주는 함수
{
	int count = 0; // 테스트 케이스의 숫자가 얼마나 나눠지는지 저장할 변수
	for (int divison=2; divison <= testCase; divison++) // testCase를 2부터 시작해서 1씩 증가시키면서 계속 나눈다
		if (testCase % divison == 0) // 나누어 떨어진다면 count 변수를 1증가시킨다
			count++;
	if (count > 1) // 1보다 큰경우 즉 나누어 떨어지는 경우가 자기자신 말고 한번이라도 더 있다면 소수가 아니다
		return false;
	else // count 변수가 1인경우에는 소수이다
		return true;
}
