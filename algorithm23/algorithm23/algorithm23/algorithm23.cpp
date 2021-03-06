// algorithm23.cpp: 定义控制台应用程序的入口点。
//直接插入排序

#include "stdafx.h"
#include<stdlib.h>
#include<time.h>

void Sort(int data[], int length);
int main()
{
	srand((unsigned)time(0));
	int data[10];
	printf("排序前：\n");
	for (int i = 0; i < 10; i++) {
		data[i] = rand() % 100;
		printf("%d ", data[i]);
	}
	printf("\n");
	printf("排序后：\n");
	Sort(data, 10);
	for (int i = 0; i < 10; i++) {
		printf("%d ", data[i]);
	}
	printf("\n");
    return 0;
}
void Sort(int data[], int length) {
	int flag = 0;
	for (int i = 1; i < length; i++) {
		if (data[i] < data[i - 1]) {
			flag = data[i];
			int j = i - 1;
			for (j; flag < data[j]; j--) {
				data[j + 1] = data[j];
			}
			data[j + 1] = flag;
		}
	}
}

