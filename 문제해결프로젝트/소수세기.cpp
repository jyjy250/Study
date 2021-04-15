#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int primeCount(int start, int end);

int main()
{
	int caseSize; // 테스트 케이스의 수를 저장하기 위한 변수 caseSize;
	cin >> caseSize; //테스트 케이스수 입력
	int* start = new int[caseSize]; // 테스트케이스수만큼의 길이를 가진범위의 시작을 저장할 start 배열 
	int* end = new int[caseSize]; // 테스트케이스수만큼의 길이를 가진범위의 끝을 저장할 end 배열 생성 
	for (int i = 0; i < caseSize; i++) // 범위를 입력
		cin >> start[i] >> end[i];
	for (int i = 0; i < caseSize; i++) // 케이스의 수만큼 함수를 반복실행
	{
		cout << "Case #" << i + 1 << ":" << endl;
		cout << primeCount(start[i], end[i]) << endl;
	}
}

int primeCount(int start, int end) // 범위를 주면 그사이의 소수의 갯수를 반환하는 함수
{
	int count = 0; // 소수의 개수를 저장할 변수 count
	for (int i = start; i <= end; i++)
	{
		int factor = 0; // 약수의 개수를 저장할 변수 factor
		for (int j = 2; j <= i; j++) // j를 증가시키며 i가 j로 나누어떨어지는지 확인
		{
			if (i % j == 0) // 나누어 떨어지면 factor값 증가
				factor++;
		}
		if (factor == 1) // j값이 2부터 시작이고 i값까지 증가하기 때문에 factor 값이 1이라면 소수이다
			count++; //소수의 개수 증가
	}
	return count; // 소수의 개수 반환
}
