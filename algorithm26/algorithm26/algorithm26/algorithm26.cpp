// algorithm26.cpp: 定义控制台应用程序的入口点。
//快速排序算法

#include "stdafx.h"
#include<stdio.h>
#include<time.h>
#include<stdlib.h>


int Sort(int data[], int low, int high);
void PrintData(int data[], int length);
void QSort(int data[], int low, int high);
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
		QSort(data, 0, 9);
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
void QSort(int data[], int low, int high) {
	if (low < high) {
		int flag = Sort(data, low, high);
		QSort(data, low, flag - 1);
		QSort(data, flag + 1, high);
	}
}
int Sort(int data[],  int low, int high) {
	int flag = data[low];

	while (low<high) {
		while (low < high&&data[high] >= flag) {
			--high;
		}
		int tmp = data[low];
		data[low] = data[high];
		data[high] = tmp;


		while (low < high&&data[low] <= flag) {
			++low;
		}
		tmp = data[low];
		data[low] = data[high];
		data[high] = tmp;
	}
	data[low] = flag;
	return low;
}

