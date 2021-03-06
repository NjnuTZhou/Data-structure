// algorithm27.cpp: 定义控制台应用程序的入口点。
//简单选择排序

#include "stdafx.h"
#include<time.h>
#include<stdio.h>
#include<stdlib.h>

void Sort(int data[], int length);
void PrintData(int data[], int length);
int SelectMin(int data[], int length, int i);
int main()
{
	srand((unsigned)time(0));
	int index = 100;
	while (index--) {
		int data[10];
		for (int i = 0; i < 10; i++) {
			data[i] = rand() % 100 + 1;
		}
		printf("排序前：\n");
		PrintData(data, 10);
		printf("冒泡排序后：\n");
		Sort(data, 10);
		PrintData(data, 10);
		printf("\n");
	}
	return 0;
}
void PrintData(int data[], int length) {
	for (int i = 0; i < length; i++) {
		printf("%d ", data[i]);
	}
	printf("\n");
}
void Sort(int data[], int length) {
	for (int i = 0; i < 10; i++) {
		int j = SelectMin(data, length, i);
		if (i != j) {
			int tmp = data[i];
			data[i] = data[j];
			data[j] = tmp;
		}
	}
}
int SelectMin(int data[], int length, int i) {
	int j = i;
	int min = data[i];
	for (int m = i; m < length; m++) {
		if (min > data[m]) {
			min = data[m];
			j = m;
		}
	}
	return j;
}

