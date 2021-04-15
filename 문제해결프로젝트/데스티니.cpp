#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<time.h>
#include<cmath>

using namespace std;

class Point2D // 점에대한 정보를 입력받을 Point2D 클래스
{
private:
	int x; // 점의 x좌표를 저장할 변수 x
	int y; // 점의 y좌표를 저장할 변수 y

public:
	Point2D(int x = 0, int y = 0) // x좌표와 y좌표를 초기화 하는 생성자
	{
		this->x = x;
		this->y = y;
	}
	double getDistance(Point2D target) // 점 this와 점 traget 까지의 거리를 return 하는 함수 
	{

		return sqrt(pow(x - target.getX(), 2) + pow(y - target.getY(), 2));
	}

	int getX() // x 가 private 이므로
	{
		return x;
	}
	int getY() //y 가 private 이므로
	{
		return y;
	}
};

int main()
{
	int n; // 천체수를 입력받을 변수 n
	Point2D* points; // 천체들의 좌표정보를 저장할 배열 points
	double** distance; // 천체들간의 거리정보를 저장할 2차원 배열 distance
	scanf("%d", &n); //천체수를 입력
	points = new Point2D[n]; // 입력받은 천체의 수만큼의 길이를 가진 Point2D 배열 생성
	distance = new double* [n]; // n X n 크기의 2차원 배열 생성
	for (int i = 0; i < n; i++)
		distance[i] = new double[n];
	for (int i = 0; i < n; i++) // 천체들의 좌표 정보를 입력
	{
		int x, y;
		scanf("%d %d", &x, &y);
		points[i]= Point2D(x, y);
	}
	double minDistance = points[0].getDistance(points[1]); // 가장 가까운 거리를 저장할 변수 minDistance를 초기화
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			distance[i][j] = points[i].getDistance(points[j]); 
			if (distance[i][j] != 0) // distance[n][m]에는 n-1번째 천체와 m-1번째 천체의 거리가 저장된다 그러므로  distance[n][n]은 무조건 0 이므로 0 이 아닐경우에만 minDistance값을 갱신하기로 한다
				if (minDistance > distance[i][j])
					minDistance = distance[i][j];
		}
	}
	int count = 0; // 같은거리인 경우를 저장하기 위한 변수 count
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (minDistance == distance[i][j])
				count++;
		}
	}
	printf("%.1f\n", minDistance);
	printf("%d\n", count/2); // distance[n][m]과 distance[m][n] 같은 거리이므로 count 변수는 중복으로 값이증가하였다 그러므로 2로 나눠준다
	delete[] points;
	delete[] distance;
	return0;
}
