#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<cmath>
#include<time.h>

using namespace std;

#define CENTER_OF_CIRCLEX 500
#define CENTER_OF_CIRCLEY 500
#define REPEAT_NUM 40000000

void run();

int main()
{
	clock_t start = clock();
	run();
	clock_t end = clock();
	printf("실행시간: %lf초\n", (double)(end - start) / CLOCKS_PER_SEC);
}

void run()
{
	int randomX, randomY;
	int distance;
	double count = 0;
	for (int i = 0; i < REPEAT_NUM; i++)
	{
		randomX = rand() % 1001;
		randomY = rand() % 1001;
		distance = sqrt(pow((randomX - CENTER_OF_CIRCLEX), 2) + pow((randomY - CENTER_OF_CIRCLEY), 2));
		if (distance < 500)
			count++;
	}
	double PI = (count / REPEAT_NUM) * 4;
	printf("PI:%f\n", PI);
}
