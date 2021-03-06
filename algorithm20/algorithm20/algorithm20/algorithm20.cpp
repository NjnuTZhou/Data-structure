// algorithm20.cpp: 定义控制台应用程序的入口点。
//二叉排序树的构建及查找,插入，删除操作

#include "stdafx.h"
#include<stdlib.h>
#include<time.h>

//创建节点结构体
struct node {
	struct node*leftchild;
	int data;
	struct node*rightchild;
	struct node*parent;
};
void createTree(struct node*head, int data);//创建二叉排序树
void centerQuery(struct node* head);//中序遍历二叉树
bool Search(struct node*head, int data);//查找某个数据元素
bool Delete(struct node *head, int data);//删除数据元素
int main()
{
	srand((unsigned)time(0));
	int query[10];
	for (int i = 0; i < 10; i++) {
		query[i] = rand() % 100 + 1;
		printf("%d\n", query[i]);
	}

	struct node*head = (struct node*)malloc(sizeof(struct node));
	head->data = query[0];
	head->leftchild = NULL;
	head->rightchild = NULL;
	head->parent = NULL;
	for (int i = 1; i < 10; i++) {
		createTree(head, query[i]);
	}
	createTree(head, query[0]);

	printf("\n中序遍历构造的二叉树如下：\n");
	centerQuery(head);
	int d = 0;
	int op = 0;
	bool re = false;
	while (true) {
		printf("请选择操作：0为查找，1为删除。\n");
		scanf_s("%d", &op);
		switch (op)
		{
		case 0:
			printf("请输入需要查找的数：");
			scanf_s("%d", &d);
			re=Search(head, d);
			if (re == false) {
				createTree(head, d);
				printf("未查询到该数据，已插入\n");
				centerQuery(head);
			}
			break;
		case 1:
			printf("请输入需要删除的数据：");
			scanf_s("%d", &d);
			re=Delete(head, d);
			if (re == false) {
				printf("该数据不存在。\n");
			}
			else {
				printf("删除成功。新的列表为\n");
				centerQuery(head);
			}
			break;
		default:
			break;
		}
	}
    return 0;
}
void createTree(struct node*head,int data) {
	if (data < head->data) {
		if (head->leftchild != NULL) {
			createTree(head->leftchild, data);
		}
		else {
			struct node* n = (struct node*)malloc(sizeof(struct node));
			n->leftchild = NULL;
			n->rightchild = NULL;
			n->data = data;
			head->leftchild = n;
			n->parent = head;
		}
	}
	else if (data > head->data) {
		if (head->rightchild != NULL) {
			createTree(head->rightchild, data);
		}
		else {
			struct node* n = (struct node*)malloc(sizeof(struct node));
			n->leftchild = NULL;
			n->rightchild = NULL;
			n->data = data;
			head->rightchild = n;
			n->parent = head;
		}
	}
}
bool Search(struct node*head, int data) {
	if (head == NULL) {
		return false;
	}
	else {
		printf("head.data:%d\n", head->data);
		if (data == head->data) {
			printf("查找成功。\n");
			return true;
		}
		else if (data < head->data) {
			return Search(head->leftchild, data);
		}

		else if (data > head->data) {
			return Search(head->rightchild, data);
		}
	}
}
bool Delete(struct node *head, int data) {
	bool re = Search(head, data);
	if (re == false) {
		return false;
	}
	else {
		struct node *p = head;
		while (p != NULL) {
			if (p->data == data) {
				break;
			}
			else if (data < p->data) {
				p = p->leftchild;
			}
			else {
				p = p->rightchild;
			}
		}
		if (p->rightchild == NULL) {
			if (p->parent->leftchild == p) {
				p->parent->leftchild = p->leftchild;
			}
			else {
				p->parent->rightchild = p->leftchild;
			}
		}
		else if (p->leftchild == NULL) {
			if (p->parent->leftchild == p) {
				p->parent->leftchild = p->rightchild;
			}
			else {
				p->parent->rightchild = p->rightchild;
			}
		}
		else {
			struct node *s = p->rightchild;
			while (s->leftchild != NULL) {
				s = s->leftchild;
			}
			s->leftchild = p->leftchild;
			if (p->parent->leftchild == p) {
				p->parent->leftchild = p->rightchild;
			}
			else {
				p->parent->rightchild = p->rightchild;
			}
		}
		return true;
	}
}
void centerQuery(struct node* head) {
	if (head->leftchild != NULL) {
		centerQuery(head->leftchild);
	}
	printf("%d\n", head->data);
	if (head->rightchild != NULL) {
		centerQuery(head->rightchild);
	}
}
