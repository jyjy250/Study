#include<stdio.h>
#include<iostream>

using namespace std;

class SudokuBoard // 스도쿠 보드의 행,열,그룹을 정하기 위한 클래스 스도쿠 보드
{
public:
	int getRowByIndex(int idx) // 인덱스를 매개변수로 행을 반환
	{
		return ((idx - 1) / 9) + 1; // 인덱스 에서 1을 빼준뒤 9로 나눈몫이 n이라면 n+1 행이다
	}
	int getColumnByIndex(int idx) // 인덱스를 매개변수로 열을 반환
	{
		return ((idx - 1) % 9) + 1; // 인덱스 에서 1을 빼준뒤 9로 나눈나머지가 n이라면 n+1 열이다
	}
	int getGroupNumByIndex(int idx) // 인덱스를 매개변수로 그룹 번호를 반환
	{
		int row = getRowByIndex(idx); // 그룹 번호를 알아내기위해 행위치를 저장
		int column = getColumnByIndex(idx); // 그룸 번호을 알아내기위해 열위치를 저장
		return (((row - 1) / 3) * 3) + (((column - 1) / 3) + 1); // 행으로 1~3 ,4~6 , 7~9 까지의 범위를 정한다음에 열로 그범위중 하나를 고른다.
	}
};



int main()
{
	int caseSize; // 테스트케이스의 수를 저장하기위한 변수 caseSize
	cin >> caseSize; //테스트케이스수 입력
	int* idxes = new int[caseSize]; // 테스트케이스 수만큼의 길이를 가진 idxes 배열 생성
	for (int i = 0; i < caseSize; i++) // idxes 배열에 인덱스들을 저장
		cin >> idxes[i]; 
	SudokuBoard board = SudokuBoard(); // 스도쿠 보드 생성
	for (int i = 0; i < caseSize; i++) // 테스트 케이스만큼 반복
	{
		cout << "Case #" << i + 1 << ":" << endl;
		cout << board.getRowByIndex(idxes[i]) << " " << board.getColumnByIndex(idxes[i]) << " " << board.getGroupNumByIndex(idxes[i]) << endl; // 인덱스를 인자로 행,열,그룹번호 출력
	}
	return 0;
}