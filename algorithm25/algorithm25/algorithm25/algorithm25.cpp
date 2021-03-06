// algorithm25.cpp: 定义控制台应用程序的入口点。
//快速排序-->冒泡排序
#include "stdafx.h"
#include<time.h>
#include<stdio.h>
#include<stdlib.h>

void Sort(int data[], int length);
void PrintData(int data[], int length);
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
	for (int j = 1; j < length; j++) {
		for (int i = 0; i < length - j; i++) {
			if (data[i] > data[i + 1]) {
				int tmp = data[i];
				data[i] = data[i + 1];
				data[i + 1] = tmp;
			}
		}
	}
}
