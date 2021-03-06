// algorithm.cpp: 定义控制台应用程序的入口点。
//哈希表的链地址表示法及其查询和删除。

#include "stdafx.h"
#include<stdlib.h>
struct node {
	int key;
	char name;
	struct node*next;

};
void insertNode(struct node*head, int key, char name);
char Search(struct node*head, int key);
bool Delete(struct node*head, int key);
int main()
{
	struct node list[13];
	int key[12] = { 19,14,23,1,68,20,84,27,55,11,10,79 };
	char name[12] = { 19,14,23,1,68,20,84,27,55,11,10,79 };
	for (int i = 0; i < 12; i++) {
		name[i] += 40;
	}
	for (int i = 0; i < 13; i++) {
		list[i].key = -1;
		list[i].name = '\0';
		list[i].next = NULL;
	}
	for (int i = 0; i < 12; i++) {
		int index = key[i] % 13;
		insertNode(&list[index], key[i], name[i]);
	}
	int op = 0;
	int d = 0;
	int pp = 0;
	char re = '\0';
	while (true) {
		printf("请选择操作：0表示查询，1表示删除\n");
		scanf_s("%d", &op);
		switch (op) {
		case 0:
			printf("请选择需要查询的关键值：");
			scanf_s("%d", &d);
			pp = d % 13;
			re = Search(&list[pp], d);
			if (re != '\0') {
				printf("该关键字对应的值为：'%c'\n", re);
			}
			else {
				printf("该关键字不存在。\n");
			}
			break;
		case 1:
			printf("请选择需要删除的关键值：");
			scanf_s("%d", &d);
			pp = d % 13;
			if (Delete(&list[pp], d)) {
				printf("删除成功。\n");
			}
			else {
				printf("该关键字不存在。\n");
			}
			break;
		}
	}
    return 0;
}
bool Delete(struct node*head, int key) {
	struct node*p = head;
	while (p->next != NULL) {
		if (p->next->key == key) {
			if (p->next->next != NULL) {
				p->next = p->next->next;
			}
			else {
				p->next = NULL;
			}
			return true;
		}
		else {
			p = p->next;
		}
	}
	return false;
}
char Search(struct node*head, int key) {
	struct node*p = head;
	while (p->next != NULL) {
		p = p->next;
		if (p->key == key) {
			return p->name;
		}
	}
	return '\0';
}
void insertNode(struct node*head,int key,char name) {
	struct node*p = head;
	while (p->next != NULL) {
		p = p->next;
	}
	struct node* n = (struct node*)malloc(sizeof(struct node));
	n->key = key;
	n->name = name;
	n->next = NULL;
	p->next = n;
}

