#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>

void solve(int data[], int n, int p, int q);


int main()
{
	int n, p, q;
	int* data;
	scanf("%d %d %d", &n, &p, &q); // n, p, q값 입력
	data = new int[n]; // 멤버들의 수에 맞춰 그 길이만큼의 int형 배열을 생성
	for (int i = 0; i < n; i++)
		scanf("%d", &data[i]); // 생성한 배열에 멤버들의 몸무게 입력
	solve(data, n, p, q);
	delete[] data;
	return 0;
}

void solve(int data[], int n, int p, int q)
{
	int count = 0; //탑승가능한 멤버들의 수 카운트
	int totalweight = 0; // 탑승가능한 멤버들의 몸무게합을 저장할 변수
	for (int i = 0; i < n; i++)
	{
		if (data[i] <= p)  //i번째 멤버의 몸무게가 p kg 이하라면 탑승가능멤버수 카운트한뒤 몸무게합변수를 몸무게만큼 늘림
		{
			count++;
			totalweight += data[i];
		}
	}
	printf("%d %d\n", count, totalweight);
	if (totalweight <= q)// q kg 이하라면 YES 아니면 NO
		printf("YES");
	else
		printf("NO");
}
