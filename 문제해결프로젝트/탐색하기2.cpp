#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string>
#include<iostream>

using namespace std;

void printIndexes(string school[], int n);


int main()
{
	int n;
	char buff[11];
	scanf("%d", &n);
	string* school = new string[n]; // 데이터 수만큼 길이를 가진 string배열을 선언
	for (int i = 0; i < n; i++) // string 배열에 값을 입력받음
	{
		scanf("%s", buff);
		school[i] = buff;
	}
	printIndexes(school, n);
	delete[] school;
	return 0;
}

void printIndexes(string school[], int n)
{
	int first = -1;
	int last = -1;
	string str = "AJOU";
	for (int i = 0; i < n; i++)
	{
		if (school[i].compare(str) == 0)// first 값을 구하면 반복문을 끝냄
		{
			first = i + 1;
			break;
		}
	}
	for (int i = first; i < n; i++)// last값을 구하기위해 한번더 반복문을 실행함
	{
		if (school[i].compare(str) == 0)
			last = i + 1;
	}
	printf("%d %d", first, last);
}
