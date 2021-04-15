#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

void prime(int num);

int main()
{
	int caseSize; // 테스트 케이스의 수를 저장하기 위한 변수 caseSize;
	cin >> caseSize; //테스트 케이스수 입력
	int* num = new int[caseSize]; // 테스트케이스수만큼의 길이를 가진 num 배열 생성
	for (int i = 0; i < caseSize; i++) // 소인수 분해할 숫자들 입력
		cin >> num[i];
	for (int i = 0; i < caseSize; i++) // 테스트 케이스만큼 반복해서 소인수분해 함수 실행
	{
		cout << "#" << i + 1 << ":" << endl; 
		prime(num[i]);
		cout << endl;
	}
	return 0;
}

void prime(int num)
{
	vector<int> primes; // 소인수를 저장할 벡터 primes
	int m = 2; // 입력받은 숫자를 나눌수는 2로 초기화
	while (1) 
	{
		if (num % m == 0) // 나누어 떨어진다면 
		{
			primes.push_back(m); // m값을 소인수를 저장하는 벡터 primes에 추가
			num /= m; // num값에는 m값으로 나눈 몫을저장
			m = 2; // 다시 m을 2로 초기화
		}
		else // 나누어 떨어지지 않는다면
		{
			m++; // m값 증가 
		}
		if (sqrt(num) < m) // m값이 나누어지는 숫자의 제곱근보다 커진다면
		{
			primes.push_back(num); // 나누어지는 숫자를 벡터 primes에 추가
			break; // 반복문 탈출
		}
	}
	for (int i = 0; i < primes.size(); i++)
	{
		cout << primes[i] << " ";
	}
}
