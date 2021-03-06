// algorithm19.cpp: 定义控制台应用程序的入口点。
//静态次优查找树的构建及查找

#include "stdafx.h"
#include<stdlib.h>
#include<time.h>
#include<math.h>

struct List {
	char name;
	int weight;
	struct List *leftchild;
	struct List *rightchild;
};
struct List* createTree( struct List list[], int low, int high);
bool Search(struct List *head, char c);
int main()
{
	srand((unsigned)time(0));
	//构建列表
	struct List list[10];
	for (int i = 0; i < 10; i++) {
		list[i].name = i + 97;
		list[i].weight = rand() % 10 + 1;
		list[i].leftchild = NULL;
		list[i].rightchild = NULL;
	}
	for (int i = 0; i < 10; i++) {
		printf("%c,%d\n", list[i].name, list[i].weight);
	}
	struct List *head =createTree( list, 0, 9);
	char in;
	while (true) {
		printf("请输入需要查找的字符：");
		scanf_s("%c", &in);
		printf("查找的序列为：\n");
		bool re=Search(head, in);
		
	}
    return 0;
}
bool Search(struct List *head, char c) {
	printf("%c->", head->name);
	if (head->name == c) {
		printf("\n查找成功！\n");
		return true;
	}
	else if (head->leftchild != NULL) {
		if (!Search(head->leftchild, c)) {
			Search(head->rightchild, c);
		}

	}
	return false;
}
struct List* createTree( struct List list[], int low, int high) {
	int p[10];
	for (int i = low; i <= high; i++) {
		int leftsw = 0;
		int rightsw = 0;
		if (i == low) {
			leftsw = 0;
		}
		else {
			for (int j = low; j < i; j++) {
				leftsw += list[j].weight;
			}
		}
		if (i == high) {
			rightsw = 0;
		}
		else {
			for (int j = i + 1; j <= high; j++) {
				rightsw += list[j].weight;
			}
		}
		p[i] = abs(rightsw - leftsw);
	}
	int min = p[low];
	int j = low;
	for (int i = low; i < high; i++) {
		if (min > p[i]) {
			min = p[i];
			j = i;
		}
	}
	struct List*n = (struct List*)malloc(sizeof(struct List));
	n->name = list[j].name;
	n->weight = list[j].weight;
	if (j > low) {
		n->leftchild=createTree(list, low, j - 1);
	}
	else {
		n->leftchild = NULL;
	}
	if (j < high) {
		n->rightchild=createTree(list, j + 1, high);
	}
	else {
		n->rightchild = NULL;
	}
	return n;
}

