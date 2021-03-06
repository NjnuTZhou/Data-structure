// algorithm21.cpp: 定义控制台应用程序的入口点。
//平衡二叉树的构建，查询以及插入删除

#include "stdafx.h"

#include<stdlib.h>
#include<time.h>

#define lh 1
#define eh 0
#define rh -1

//创建节点结构体
struct node {
	int data;
	int bf;
	struct node*leftchild;
	struct node*rightchild;

};
int createTree(struct node**t, int data, bool &taller);//创建平衡二叉树
void LeftBalance(struct node **t);
void RightBalance(struct node **t);
void L_Rotate(struct node**t);
void R_Rotate(struct node**t);
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
	head->bf = eh;
	head->data = query[0];
	head->leftchild = head->rightchild = NULL;
	bool taller = false;

	for (int i = 1; i < 10; i++) {
		createTree((&head), query[i],taller);
	}

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
			re = Search(head, d);
			if (re == false) {
				createTree(&head, d, taller);
				printf("未查询到该数据，已插入\n");
				centerQuery(head);
			}
			break;
		case 1:
			printf("请输入需要删除的数据：");
			scanf_s("%d", &d);
			re = Delete(head, d);
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
int createTree(struct node**t, int data, bool &taller) {
	if ((*t) == NULL) {
		(*t) = (struct node*)malloc(sizeof(struct node));
		(*t)->data = data;
		(*t)->leftchild = (*t)->rightchild = NULL;
		(*t)->bf = eh;
		taller = true;
	}
	else {
		if (data == (*t)->data) {
			taller = false;
			return 0;
		}
		else if (data < (*t)->data) {
			if (!createTree(&((*t)->leftchild), data, taller)) {
				return 0;
			}
			if (taller) {
				switch ((*t)->bf) {
				case lh:
					LeftBalance(&(*t));
					taller = false;
					break;
				case eh:
					(*t)->bf = lh;
					taller = true;
					break;
				case rh:
					(*t)->bf = eh;
					taller = false;
					break;
				}
			}
		}
		else {
			if (!createTree(&((*t)->rightchild), data, taller)) {
				return 0;
			}
			if (taller) {
				switch ((*t)->bf) {
				case lh:
					(*t)->bf = eh;
					taller = false;
					break;
				case eh:
					(*t)->bf = rh;
					taller = true;
					break;
				case rh:
					RightBalance(&(*t));
					taller = false;
					break;
				}
			}
		}
	}
	return 1;
}
void LeftBalance(struct node **t) {
	struct node*lc = (*t)->leftchild;
	switch (lc->bf) {
	case lh:
		(*t)->bf = lc->bf = eh;
		R_Rotate(&(*t));
		break;
	case rh:
		if (lc->rightchild != NULL) {
			struct node*rd = lc->rightchild;
			switch (rd->bf) {
			case lh:
				(*t)->bf = rh;
				lc->bf = eh;
				break;
			case eh:
				(*t)->bf = lc->bf = eh;
				break;
			case rh:
				(*t)->bf = eh;
				lc->bf = lh;
				break;

			}
			rd->bf = eh;
		}
		L_Rotate(&((*t)->leftchild));
		R_Rotate(&(*t));

	}
}
void RightBalance(struct node **t) {
	struct node*rc = (*t)->rightchild;
	switch (rc->bf) {
	case lh:
		(*t)->bf = rc->bf = eh;
		L_Rotate(&(*t));
		break;
	case rh:
		if (rc->leftchild != NULL) {
			struct node*ld = rc->leftchild;
			switch (ld->bf) {
			case lh:
				(*t)->bf = eh;
				rc->bf = lh;
				break;
			case eh:
				(*t)->bf = rc->bf = eh;
				break;
			case rh:
				(*t)->bf = rh;
				rc->bf = eh;
				break;

			}
			ld->bf = eh;
		}
		L_Rotate(&(*t));
		R_Rotate(&((*t)->rightchild));


	}
}
void L_Rotate(struct node**t) {
	struct node*rc = (*t)->rightchild;
	if (rc->leftchild == NULL) {
		(*t)->rightchild = NULL;
	}
	else
	{
		(*t)->rightchild = rc->leftchild;
	}
	rc->leftchild = (*t);
	(*t) = rc;
}
void R_Rotate(struct node**t) {
	struct node*lc = (*t)->leftchild;
	if (lc->rightchild == NULL) {
		(*t)->leftchild = NULL;
	}
	else {
		(*t)->leftchild = lc->rightchild;
	}
	lc->rightchild = (*t);
	(*t) = lc;
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
	return false;
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


