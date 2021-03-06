// algorithm14.cpp: 定义控制台应用程序的入口点。
//二叉树的先序、中序、后序遍历

#include "stdafx.h"
#include<stdlib.h>
struct tree {
	struct tree*leftchild;
	int data;
	struct tree*rightchild;
};
void first(struct tree*node);
void center(struct tree*node);
void after(struct tree*node);
int main()
{
	struct tree* nodes = (struct tree*)malloc(sizeof(struct tree) * 50);
	for (int i = 0; i < 50; i++) {
		nodes[i].data = i;
		nodes[i].leftchild = NULL;
		nodes[i].rightchild = NULL;
	}
	for (int i = 1; i < 25; i++) {
		if (i * 2 + 1 < 50) {
			nodes[i].leftchild = &nodes[i * 2 + 1];
		}
		if (i * 2 + 2 < 50) {
			nodes[i].rightchild = &nodes[i * 2 + 2];
		}
	}
	nodes[0].leftchild = &nodes[1];
	nodes[0].rightchild = &nodes[2];

	struct tree *source = &nodes[0];
	printf("二叉树的先序遍历：\n");
	first(source);
	printf("\n");
	printf("二叉树的中序遍历：\n");
	center(source);
	printf("\n");
	printf("二叉树的后序遍历：\n");
	after(source);
	printf("\n");
    return 0;
}


void first(struct tree*node) {
	printf("%d ", node->data);
	if (node->leftchild != NULL) {
		first(node->leftchild);
	}
	if (node->rightchild != NULL) {
		first(node->rightchild);
	}
	return;
}
void center(struct tree*node) {
	if (node->leftchild != NULL) {
		center(node->leftchild);
	}
	printf("%d ", node->data);

	if (node->rightchild != NULL) {
		center(node->rightchild);
	}
	return;
}
void after(struct tree*node) {
	if (node->leftchild != NULL) {
		after(node->leftchild);
	}
	if (node->rightchild != NULL) {
		after(node->rightchild);
	}
	printf("%d ", node->data);
	return;
}

