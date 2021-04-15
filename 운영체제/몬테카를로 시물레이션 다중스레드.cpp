#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<thread>
#include<cmath>
#include<time.h>

using namespace std;

#define CENTER_OF_CIRCLEX 500
#define CENTER_OF_CIRCLEY 500
#define REPEAT_NUM 40000000

void run(int* num);


int main()
{
	int num[4] = { 0, };
	int* ptr[4];
	for (int i = 0; i < 4; i++)
		ptr[i] = &num[i];
	clock_t start = clock();
	thread t1(run, ptr[0]);
	thread t2(run, ptr[1]);
	thread t3(run, ptr[2]);
	thread t4(run, ptr[3]);
	t1.join();
	t2.join();
	t3.join();
	t4.join();
	double total = num[0] + num[1] + num[2] + num[3];
	double PI = (total / REPEAT_NUM) * 4;
	printf("PI:%f\n", PI);
	clock_t end = clock();
	printf("실행시간: %lf초\n", (double)(end - start) / CLOCKS_PER_SEC);
}

void run(int* num)
{
	int randomX, randomY;
	int distance;
	for (int i = 0; i < REPEAT_NUM / 4; i++)
	{
		randomX = rand() % 1001;
		randomY = rand() % 1001;
		distance = sqrt(pow((randomX - CENTER_OF_CIRCLEX), 2) + pow((randomY - CENTER_OF_CIRCLEY), 2));
		if (distance < 500)
			(*num)++;
	}
}
