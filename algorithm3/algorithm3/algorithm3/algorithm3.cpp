// algorithm3.cpp: 定义控制台应用程序的入口点。
//堆栈的数组实现

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>

int ifIn(int a[], int length, int num);
int main()
{
	int a[10] = {0,1,2,3,4,5,6,7,8,9};
	int c[100] = {-1};
	for (int i = 0; i < 10; i++) {
		c[i] = a[i];
	}

	int currentLength = 10;
	printf("当前数组数据：");
	for (int i = 0; i < currentLength; i++) {
		printf("%d ", c[i]);
	}
	printf("\n");
	while (1) {
		int d = 0;

		printf("请输入：");
		scanf("%d", &d);
		int index = ifIn(c, currentLength, d);
		if (index == -1) {
			c[currentLength] = d;
			currentLength += 1;
		}
		else {
			for (int i = index; i < currentLength; i++) {
				c[i] = c[i + 1];
			}
			c[currentLength] = -1;
			currentLength -= 1;
		}
		printf("当前数组数据：");
		for (int i = 0; i < currentLength; i++) {
			printf("%d ", c[i]);
		}
		printf("\n");
	}
    return 0;
}
int ifIn(int a[], int length, int num) {
	for (int i = 0; i < length; i++) {
		if (num == a[i]) {
			return i;
		}
	}
	return -1;
}

