// algorithm18.cpp: 定义控制台应用程序的入口点。
//二分法查找

#include "stdafx.h"
struct node {
	int index;
	char name;
};
int Search(struct node list[],int low,int high,int index);
int main()
{
	//构建查找表
	struct node list[50];
	for (int i = 0; i < 50; i++) {
		list[i].index = i * 2 + 1;
		list[i].name = (char)i+33;
		printf("%d.%d,%c\n", i, list[i].index, list[i].name);
	}
	int in = 0;
	while (true) {
		printf("请输入查找的序号：");
		scanf_s("%d", &in);
		if (in == -1) {
			break;
		}
		else {
			int result = Search(list, 0, 49, in);
			if (result == -1) {
				printf("该序号不在列表中。\n");
			}
			else {
				printf("查找的序号为：%d，位于列表的第%d位，字符为：%c\n", in, result, list[result].name);
			}
		}
	}
    return 0;
}
int Search(struct node list[], int low, int high, int index) {
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (list[mid].index == index) {
			return mid;
		}
		else {
			if (list[mid].index < index) {
				low += 1;
			}
			else {
				high = mid - 1;
			}
		}
	}
	return -1;
}

