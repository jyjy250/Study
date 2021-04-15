#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string>
#include<iostream>
#include<time.h>

using namespace std;

void clockRotate(string* wheel);
void counterClockRotate(string* wheel);
bool shouldRotateLeft(string rotatingWheel, string rotatedWheel);
bool shouldRotateRight(string rotatingWheel, string rotatedWheel);
void rotate(int rotwheel, int rotdirection, string wheel[]);

int didRotate[4] = { 0,0,0,0 }; // 톱니바퀴의 회전이력을 저장하기위한 배열 didRotate

int main()
{
	string wheel[4]; // 톱니 바퀴의 상태를 입력받기 위한 string 배열 wheel
	int score = 0; // 점수를 저장할 변수 score
	int rotatenum; // 회전 횟수를 저장할 변수 rotatenum
	int* rotwheel; // 회전시킨 톱니바퀴의 번호를 저장할 배열 rotwheel
	int* rotdirection; // 회전시킬 방향을 저장할 배열 rotdirection
	for (int i = 0; i < 4; i++) // wheel의 상태를 입력
		cin >> wheel[i];
	cin >> rotatenum; // 회전 횟수를 입력
	rotwheel = new int[rotatenum]; // rotatenum만큼의 길이를 가진 rotwheel 배열 생성
	rotdirection = new int[rotatenum]; // rtotatenum만큼의 길이를 가진 rotdirection 배열 생성
	for (int i = 0; i < rotatenum; i++)
		cin >> rotwheel[i] >> rotdirection[i]; // rotwheel과 rotdirection 입력
	clock_t start = clock();
	for (int i = 0; i < rotatenum; i++) // 회전 횟수만큼 rotate 함수 실행
	{
		rotate(rotwheel[i], rotdirection[i], wheel);
		for (int j = 0; j < 4; j++) // 한번의 회전이 끝난뒤 회전 이력 초기화
			didRotate[j] = 0;
	}

	if (wheel[0].at(0) == '1') // 회전시킨 톱니바퀴로 점수 집계
		score += 1;
	if (wheel[1].at(0) == '1')
		score += 2;
	if (wheel[2].at(0) == '1')
		score += 4;
	if (wheel[3].at(0) == '1')
		score += 8;
	cout << score << endl;
	clock_t end = clock();
	printf("실행시간: %lf초\n", (double)(end - start) / CLOCKS_PER_SEC);
}

void clockRotate(string* wheel) // 시계방향으로 회전시키는 함수
{
	string rotated = "00000000"; // 회전된 모습을 저장하기 위한 string 배열 rotated
	rotated.at(0) = wheel->at(7); // 문자열의 오른쪽 끝을 rotated배열의 첫번쨰에 대입한다
	for (int i = 1; i < 8; i++) // 시계방향으로 회전하는걸 배열입장에서 보면 오른쪽으로 미는것이다
		rotated.at(i) = wheel->at(i - 1);
	*wheel = rotated; // 회전된 모습을 wheel에 저장
}

void counterClockRotate(string* wheel) // 반시계방향으로 회전 시키는 함수
{
	string rotated = "00000000"; // 회전된 모습을 저장하기 위한 string 배열 rotated
	rotated.at(7) = wheel->at(0); // 문자열의 왼쪽 끝을 rotated배열의 오른쪽끝에 대입한다
	for (int i = 6; i > -1; i--) // 반시계방향으로 회전하는걸 배열입장에서 보면 왼쪽으로 미는것이다
		rotated.at(i) = wheel->at(i + 1);
	*wheel = rotated; // 회전된 모습을 wheel에 저장
}

bool shouldRotateRight(string rotatingWheel, string rotatedWheel) // 오른쪽에 있는 톱니바퀴가 왼쪽에있는 톱니바퀴의 회전때문에 회전해야하는지 판단
{
	if (rotatingWheel.at(2) != rotatedWheel.at(6)) // 문제의 설명대로 맞닿은 부분이 극이 다르다면 회전시켜야 하므로 true
		return true;
	else
		return false;
}

bool shouldRotateLeft(string rotatingWheel, string rotatedWheel) // 왼쪽에 있는 톱니바퀴가 오른쪽에있는 톱니바퀴의 회전때문에 회전해야하는지 판단
{
	if (rotatingWheel.at(6) != rotatedWheel.at(2)) // 문제의 설명대로 맞닿은 부분이 극이 다르다면 회전시켜야 하므로 true
		return true;
	else
		return false;
}

void rotate(int rotwheel, int rotdirection, string wheel[])
{
	didRotate[rotwheel - 1] = 1; // 회전 이력을 저장
	if (rotwheel == 1) // 회전시켜야 하는 톱니바퀴가 1번인 경우
	{
		if (rotdirection == 1) // 시계방향으로 회전 시키는 경우
		{
			if (shouldRotateRight(wheel[0], wheel[1]) && !didRotate[1]) // 2번 톱니바퀴의 회전여부 결정, 회전이력이 없고 맞닿은 극이 다를때 실행
				rotate(2, -1, wheel);
			clockRotate(&wheel[0]);
		}
		else // 반시계방향으로 회전 시키는 경우
		{
			if (shouldRotateRight(wheel[0], wheel[1]) && !didRotate[1]) // 2번 톱니바퀴의 회전여부 결정, 회전이력이 없고 맞닿은 극이 다를때 실행
				rotate(2, 1, wheel);
			counterClockRotate(&wheel[0]);
		}
	}
	if (rotwheel == 2) // 회전시켜야 하는 톱니바퀴가 2번인 경우
	{
		if (rotdirection == 1) // 시계 방향으로 회전 시키는 경우
		{
			if (shouldRotateRight(wheel[1], wheel[2]) && !didRotate[2]) // 3번 톱니바퀴의 회전 여부 결정, 회전이력이 없고 맞닿은 극이 다를때 실행
				rotate(3, -1, wheel);
			if (shouldRotateLeft(wheel[1], wheel[0]) && !didRotate[0]) // 1번 톱니바퀴의 회전 여부 결정, 회전이력이 없고 맞닿은 극이 다를때 실행
				rotate(1, -1, wheel);
			clockRotate(&wheel[1]);
		}
		else // 반시계 방향으로 회전 시키는 경우
		{, 회전이력이 없고 맞닿은 극이 다를때 실행
			if (shouldRotateRight(wheel[1], wheel[2]) && !didRotate[2]) // 3번 톱니바퀴의 회전 여부 결정, 회전이력이 없고 맞닿은 극이 다를때 실행
				rotate(3, 1, wheel);
			if (shouldRotateLeft(wheel[1], wheel[0]) && !didRotate[0]) // 1번 톱니바퀴의 회전 여부 결정, 회전이력이 없고 맞닿은 극이 다를때 실행
				rotate(1, 1, wheel);
			counterClockRotate(&wheel[1]);
		}
	}
	if (rotwheel == 3) // 회전시켜야 하는 톱니바퀴가 3번인 경우
	{
		if (rotdirection == 1) // 시계 방향으로 회전 시키는 경우
		{
			if (shouldRotateRight(wheel[2], wheel[3]) && !didRotate[3]) // 4번 톱니바퀴의 회전 여부 결정, 회전이력이 없고 맞닿은 극이 다를때 실행
				rotate(4, -1, wheel);
			if (shouldRotateLeft(wheel[2], wheel[1]) && !didRotate[1]) // 2번 톱니바퀴의 회전 여부 결정, 회전이력이 없고 맞닿은 극이 다를때 실행
				rotate(2, -1, wheel);
			clockRotate(&wheel[2]);
		}
		else // 반시계 방향으로 회전 시키는 경우
		{
			if (shouldRotateRight(wheel[2], wheel[3]) && !didRotate[3]) // 4번 톱니바퀴의 회전 여부 결정, 회전이력이 없고 맞닿은 극이 다를때 실행
				rotate(4, 1, wheel);
			if (shouldRotateLeft(wheel[2], wheel[1]) && !didRotate[1]) // 2번 톱니바퀴의 회전 여부 결정, 회전이력이 없고 맞닿은 극이 다를때 실행
				rotate(2, 1, wheel);
			counterClockRotate(&wheel[2]);
		}
	}
	if (rotwheel == 4) // 회전시켜야 하는 톱니바퀴가 4번인 경우
	{
		if (rotdirection == 1) // 시계 방향으로 회전 시키는 경우
		{
			if (shouldRotateLeft(wheel[3], wheel[2]) && !didRotate[2]) // 3번 톱니바퀴의 회전 여부 결정, 회전이력이 없고 맞닿은 극이 다를때 실행
				rotate(3, -1, wheel);
			clockRotate(&wheel[3]);
		}
		else // 반시계 방향으로 회전 시키는 경우
		{
			if (shouldRotateLeft(wheel[3], wheel[2]) && !didRotate[2]) // 3번 톱니바퀴의 회전 여부 결정, 회전이력이 없고 맞닿은 극이 다를때 실행
				rotate(3, 1, wheel);
			counterClockRotate(&wheel[3]);
		}
	}
}














