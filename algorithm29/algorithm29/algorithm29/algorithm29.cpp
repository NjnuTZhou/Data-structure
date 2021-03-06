// algorithm29.cpp: 定义控制台应用程序的入口点。
// 2-路归并排序,暂时只能处理长度为2的幂的数组。

#include "stdafx.h"
#include<time.h>
#include<stdio.h>
#include<stdlib.h>

void Sort(int data[], int length);
void PrintData(int data[], int length);
void Merge(int data[], int start1, int start2, int end);
int main()
{
	srand((unsigned)time(0));
	int index = 100;
	while (index--) {
		int data[8];
		for (int i = 0; i < 8; i++) {
			data[i] = rand() % 100 + 1;
		}
		printf("排序前：\n");
		PrintData(data, 8);
		printf("2-路归并排序后：\n");
		Sort(data, 8);
		PrintData(data, 8);
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
	int k = 2;
	while (k / 2 < length) {
		for (int i = 0; i < length; i += k) {
			if (i + k - 1 < length) {
				Merge(data, i, i + k / 2, i + k - 1);
			}

		}
		k *= 2;
	}
}
void Merge(int data[], int start1, int start2, int end) {
	int j = start1;
	for (int i = start2; i <= end; i++) {
		start2 = i;
		for (j; j < start2; j++) {
			if (data[i] < data[j]) {
				int tmp = data[i];
				int m = i;
				while (m > j) {
					data[m] = data[m - 1];
					m--;
				}
				data[j] = tmp;
				break;
			}
		}
	}
}

