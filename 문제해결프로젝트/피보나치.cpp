#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<time.h>
#include<vector>

using namespace std;

int fibonacciSequence(int n);

int main()
{
	int t; // 테스트 케이스의 수를 입력받을 변수 t
	scanf("%d", &t); // 테스트 케이스수 입력
	int* n = new int[t]; // 테스트 케이스 수만큼의 길이를 가진 배열 n 생성
	for( int i=0; i<t; i++) // 자연수 n의 입력
		scanf("%d", &n[i]);
	for (int i = 0; i < t; i++)
		fibonacciSequence(n[i]); 
}

int fibonacciSequence(int n)
{
	int front = 0; // 앞의 두원소중 앞의 인덱스를 가리키는 변수 front
	int back = 1; // 앞의 두원소중 뒤의 인덱스를 가리키는 변수 back
	vector<unsigned long long> fibonacci; // fibonacci 수열을 저장할 벡터
	fibonacci.push_back(0); // 첫번쨰 항은 0
	fibonacci.push_back(1); // 두번째 항은 1
	if (n == 1) // n이 1일땐 0을 출력
	{
		printf("0\n");
		return 0;
	}
	if (n == 2) // n이 2일땐 1을 출력
	{
		printf("1\n");
		return 0;
	}
	while (fibonacci.size() != n) // n이 3이상일땐 n번째 항을 아래과정을 통해 구한다.
	{
		fibonacci.push_back(fibonacci[front] + fibonacci[back]); // 앞의 두원소의 합을 벡터에 추가
		front++; // 인덱스값 증가
		back++; // 인덱스값 증가
		fibonacci.back() %= 100000000; 
	}

	printf("%d\n", fibonacci.back());
	return 0;
}





