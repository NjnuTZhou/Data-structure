// algorithm24.cpp: 定义控制台应用程序的入口点。
//希尔排序,按步长进行排序。

#include "stdafx.h"
#include<time.h>
#include<stdio.h>
#include<stdlib.h>


void Sort(int data[], int length, int step);
void PrintData(int data[], int length);
int main()
{
	srand((unsigned)time(0));
	int data[10];
	for (int i = 0; i < 10; i++) {
		data[i] = rand() % 100 + 1;
	}
	printf("排序前：\n");
	for (int i = 0; i < 10; i++) {
		printf("%d ", data[i]);
	}
	printf("\n");
	int step = 0;
	while (true) {
		printf("请输入步长：");
		scanf_s("%d", &step);
		Sort(data, 10, step);
		printf("本次排序结果：\n");
		PrintData(data, 10);
	}
    return 0;
}
void PrintData(int data[], int length) {
	for (int i = 0; i < length; i++) {
		printf("%d ", data[i]);
	}
	printf("\n");
}
void Sort(int data[], int length, int step) {
	int flag = 0;
	for (int i = step; i < length; i++) {
		if (data[i] < data[i - step]) {
			flag = data[i];
			int j = i - step;
			for (j; j >= 0 && flag < data[j]; j -= step) {
				data[j + step] = data[j];
			}
			data[j + step] = flag;
		}
	}
}

