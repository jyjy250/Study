#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

class LottoTable // 행운권 번호를 생성하고 지급하기위한 클래스
{
public:
	vector<int> used; // 지급된 행운권 번호를 저장하기위한 벡터
	bool isUsed(int lotto) // 행운권 번호가 사용 되었는지 확인하는 메소드
	{
		for (int i = 0; i < used.size(); i++)
		{
			if (lotto == used[i]) // 사용되었다면 true 반환
				return true;
		}
		return false; // 사용되지 않았다면 false 반환
	}
	int makeLotto(int lottoAmount, int memberId) // 회원 번호로 행운권 번호를 생성하는 메소드
	{
		int lotto = memberId % lottoAmount; // 행운권 번호 생성
		while (1)
		{
			if (isUsed(lotto)) // 생성한 행운권 번호가 사용되었다면 값을 증가
				lotto++;
			else
				break; //사용되지않았다면 루프문 탈출
			if (lotto == lottoAmount) // 행운권번호 끝까지 간다면 0으로 돌아가서 반복
				lotto = 0;

		}
		used.push_back(lotto); // 사용되지않은 번호를 구했다면 used벡터에 추가
		return lotto; // 행운권 번호 리턴
	}

};

int main()
{
	int lottoAmount, enterMember; // 행운권의 수를 저장할 변수 lottoAmount, 입장회원의 수 enterMember
	cin >> lottoAmount >> enterMember; // 행운권의 수 입력, 입장회원의 수 입력
	int* memberId = new int[enterMember]; // 회원번호를 저장할 배열 memberId를 입장회원의 수만큼의 길이로 생성
	for (int i = 0; i < enterMember; i++) //회원번호 입력
		cin >> memberId[i];
	LottoTable luck = LottoTable(); 
	for (int i = 0; i < enterMember; i++) // 행운권 번호 생성후 출력
		cout << luck.makeLotto(lottoAmount, memberId[i]) << endl;
}
