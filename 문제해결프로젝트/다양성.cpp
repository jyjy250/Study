#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;
void getElementTypeCount(int n, int data[]);

int main()
{
	int n; // 화보의 수를 나타내는 변수 n
	int* data; // 화보의 수를 나타내고 화보의 수만큼의 길이를 가진 배열 data
	scanf("%d", &n); // 화보의 수를 입력받음
	data = new int[n]; // 화보의 수만큼의 길이를 가진 배열 생성
	for (int i = 0; i < n; i++) // 배열에 고유번호를 입력받음
		scanf("%d", &data[i]);
	getElementTypeCount(n, data); // 화보의 종류를 세는 함수 호출
	delete[] data; // data 배열 메모리에서 삭제
	return 0;
}

void getElementTypeCount(int n, int data[])
{
	int count = 0; // 겹치는게 있는지 없는지 확인하기 위한 count 변수
	vector<int> serialNum; // 화보의 고유번호를 겹치지 않게 저장하기위한 vector 
	serialNum.push_back(data[0]); // 이후 알고리즘을 위해 고유번호 하나를 삽입
	for (int i = 1; i < n; i++)
	{	
		for (int j = 0; j < serialNum.size(); j++) // main함수에서 입력받은 고유번호가 vector에 등록되어있는지 확인
		{
			if (data[i] != serialNum[j]) // 고유번호와 vector의 원소들을 비교했을때 겹치지 않으면 count 변수 증가
				count++;
			if (count == serialNum.size()) // 고유번호가 모든 vector의 원소들과 겹치지 않으면 등록되지 않은 고유번호 이므로 vector에 삽입
				serialNum.push_back(data[i]);
		}
		count = 0; // 고유번호 비교를 위해 다시 count 변수 0으로 초기화 
	}
	printf("%d", serialNum.size()); // 겹치지 않게 고유번호의 종류를 vector에 등록했으므로 vector의 크기가 곧 종류의 갯수
}
