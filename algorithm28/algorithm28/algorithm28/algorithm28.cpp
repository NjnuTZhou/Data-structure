// algorithm28.cpp: 定义控制台应用程序的入口点。
// 堆排序
// 与书上使用的循环方法不同，使用递归方法实现新建一个堆
// 这样更容易理解。

#include "stdafx.h"
#include<time.h>
#include<stdio.h>
#include<stdlib.h>

void Sort(int data[], int length);
void HeapAjust(int data[], int s, int m);
void PrintData(int data[], int length);
int main()
{
	srand((unsigned)time(0));
	int index = 100;
	while (index--) {
		int data[11] /*= { 0,80,12,91,76,17,74,1,22,31,48 }*/;
		for (int i = 1; i < 11; i++) {
			data[i] = rand() % 100 + 1;
		}
		data[0] = 0;
		printf("排序前：\n");
		PrintData(data, 10);
		printf("堆排序后：\n");
		Sort(data, 10);
		//PrintData(data, 10);
		printf("\n");
	}
	return 0;
}
void PrintData(int data[], int length) {
	for (int i = 1; i < length+1; i++) {
		printf("%d ", data[i]);
	}
	printf("\n");
}
void HeapAjust(int data[], int s, int m) {

	int k1 = 2 * s;
	int k2 = 2 * s + 1;
	if (k1 <= m && k2 <= m) {
		if (data[k1] < data[k2]) {
			if (data[s] < data[k2]) {
				int tmp = data[s];
				data[s] = data[k2];
				data[k2] = tmp;
				HeapAjust(data, k2, m);
			}
		}
		else if(data[k1] > data[k2]){
			if (data[s] < data[k1]) {
				int tmp = data[s];
				data[s] = data[k1];
				data[k1] = tmp;
				HeapAjust(data, k1, m);
			}
		}
	}
	else if(k1<=m) {
		if (data[s] < data[k1]) {
			int tmp = data[s];
			data[s] = data[k1];
			data[k1] = tmp;
			HeapAjust(data, k1, m);
		}
	}
}
void Sort(int data[], int length) {
	for (int i = length  / 2; i > 0; i--) {
		HeapAjust(data, i, length);
	}
	for (int i = length; i > 1; --i) {
		printf("%d ", data[1]);
		int tmp = data[i];
		data[i] = data[1];
		data[1] = tmp;
		HeapAjust(data, 1, i - 1);
	}
	printf("%d ", data[1]);
	printf("\n");
}

