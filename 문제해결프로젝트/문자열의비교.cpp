#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<string.h>

using namespace std;
void stringCompare(char str1[], char str2[]);

int main()
{
	char str1[100001]; //최대 10만 길이까지 저장할수있는 첫번째 문자배열 생성
	char str2[100001]; //최대 10만 길이까지 저장할수있는 두번째 문자배열 생성
	scanf("%s", str1); // 첫번째 문자열 입력
	scanf("%s", str2); // 두번째 문자열 입력
	stringCompare(str1, str2); // 사전순으로 비교하는 함수 호출
	return 0;
}

void stringCompare(char str1[], char str2[])
{
	int length; // 문자비교 횟수를 정하기 위해 int형 변수를 선언
	bool equals = true; // 문자열이 같은지를 결정하기 위해 bool 형 변수 선언
	if (strlen(str1) > strlen(str2)) // 두문자열중 더 긴 문자의열의 길이를 반복횟수로 선택
		length = strlen(str1);
	else
		length = strlen(str2);
	for (int i = 0; i < length; i++)
	{
		if (str1[i] < str2[i]) // 문자값의 아스키값이 더크다면 사전순으로 더뒤에있기 때문에 이경우 -1을 출력
		{
			printf("-1");
			equals = false; // 같지않으므로 equals 변수에 false를 대입
			break; //반복문 종료
		}
		if (str1[i] > str2[i]) // 문자값의 아스키값이 더크다면 사전순으로 더뒤에있기 때문에 이경우 1을 출력
		{
			printf("1");
			equals = false; // 같지않으므로 equals 변수에 false를 대입
			break; //반복문 종료
		}
	}
	if(equals) // 모든 문자가 아스키값이 같으므로 0 출력
		printf("0");
}
