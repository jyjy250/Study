#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

vector<int> cases; // 카드를 뽑아서 만들 수 있는 모든 경우의 수를 저장할 벡터 cases;
vector<int> possible; // 만들 수 있는 당첨 번호를 저장할 벡터 possible

void CaseCalculator(int cards[], int cardNum);
void bubbleSort(vector<int> data);

int main()
{
	int cardNum, lottoNum; // 사용할 카드의 숫자를 입력받을 변수 cardNum, 당첨번호의 숫자를 입력받을 변수 lottoNum;
	cin >> cardNum >> lottoNum; // 카드의 숫자와 당첨번호의 숫자의 입력
	int* cards = new int[cardNum]; // 카드 숫자만큼의 길이를 가진 배열 cards 생성
	int* lotto = new int[lottoNum]; // 당첨번호의 숫자만큼의 길이를 가진 배열 lotto 생성
	bool posi; // possible 벡터를 채울때에 조건을 설정하기 위한 bool 변수 posi
	for (int i = 0; i < cardNum; i++) // 카드에 적힌 숫자들을 입력
		cin >> cards[i];
	for (int i = 0; i < lottoNum; i++)// 당첨번호들을 입력
		cin >> lotto[i];
	cases.push_back(cards[0] + cards[0] + cards[0]); // 가능한 경우의 수를 뒤의 알고리즘을 위해 한가지 추가해준다
	CaseCalculator(cards, cardNum); // 가능한 모든 경우의수를 계산해서 채우는 함수
	for (int i = 0; i < lottoNum; i++) // 경우의 수중에서 이번주 당첨번호와 겹친다면 possible 벡터에 추가
	{
		posi = false;
		for (int j = 0; j < cases.size(); j++)
			if (lotto[i] == cases[j])
				posi = true;
		if (posi)
			possible.push_back(lotto[i]);
	}
	bubbleSort(possible); // possible 벡터를 오름차순으로 정렬
}
void CaseCalculator(int cards[], int cardNum)
{
	bool already; // 이미 있는 숫자인경우를 판별하기 위한 변수 already
	for (int i = 0; i < cardNum; i++)
		for (int j = 0; j < cardNum; j++)
			for (int k = 0; k < cardNum; k++)
			{ 
				already = false; 
				for (int l = 0; l < cases.size(); l++)
					if (cards[i] + cards[j] + cards[k] == cases[l]) // 이미 있는 경우의 수인경우를 걸러낸다
						already = true;
				if (!already) //already 함수가 false 라면 이미 있는 경우의 수가 아니므로 경우의 수를 벡터에 추가
					cases.push_back(cards[i] + cards[j] + cards[k]);
			}
}

void bubbleSort(vector<int> data)
{
	for (int i = 0; i < data.size(); i++) // 아래 과정을 벡터의 길이만큼 반복
	{
		for (int j = 0; j < data.size() - 1; j++) // data[0]~data[n-2] 번칸의 숫자가 data[1]~ data[n-1] 칸의 숫자 보다 크면 두값의 위치를 교환한다
		{
			if (data[j] > data[j + 1])
			{
				int temp = data[j]; // 값을 교환하기위해 잠깐 변수값을 저장할 변수 temp
				data.erase(data.begin() + j);
				data.insert(data.begin()+(j + 1), temp);
			}
		}
	}
	if (possible.size())
		for (int i = 0; i < data.size(); i++)
			cout << data[i] << " ";
	else
		cout << "NO";
}
