// algorithm8.cpp: 定义控制台应用程序的入口点。
//
//队列的链式的表示和实现

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>


struct node {
	int data;
	struct node* next;
};
void insertQueue();
void popQueue();

struct node* current = (struct node*)malloc(sizeof(struct node));
struct node* head;
struct node* tail = (struct node*)malloc((sizeof(struct node)));
int main()
{
	printf("0：插入队列   1：弹出队列\n");
	current->next = tail;
	head = current;
	tail->next = NULL;

	//插入队列
	while (true) {
		int index = 0;
		printf("请输入操作：");

		scanf_s("%d", &index);
		switch (index)
		{
		case 0:
			insertQueue();
			break;
		case 1:
			popQueue();
			break;
		default:
			return 0;
			break;
		}
		printf("当前队列为：\n");
		struct node *p = head->next;
		while (p != tail) {
			printf("%d ", p->data);
			p = p->next;
		}
		printf("\n");
	}
    return 0;
}

void insertQueue() {
	printf("请输入数据：");
	int num = 0;
	scanf_s("%d", &num);

	struct node* p = (struct node *)malloc(sizeof(struct node));
	p->next = tail;
	p->data = num;
	current->next = p;
	current = p;
}
void popQueue() {
	if (head->next == tail) {
		printf("当前队列为空！请先插入数据\n");
	}
	else {
		struct node * q = head->next;
		head->next = head->next->next;
		printf("弹出的数据为：%d\n", q->data);
	}
}

