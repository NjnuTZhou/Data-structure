// algorithm15.cpp: 定义控制台应用程序的入口点。
//树的孩子兄弟表示法及其先序和后序遍历
//树的先序遍历相当于二叉树的先序遍历，树的后序遍历相当于二叉树的中序遍历。

#include "stdafx.h"
#include<stdlib.h>

struct tree {
	int data;
	struct tree* firstChild;
	struct tree* nextBro;
};
void first(struct tree*node);//树的先序遍历
void after(struct tree*node);//树的后序遍历	
int main()
{
	struct tree nodes[10];
	for (int i = 0; i < 10; i++) {
		nodes[i].data = i;
		nodes[i].firstChild = NULL;
		nodes[i].nextBro = NULL;
	}
	struct tree * source = &nodes[0];

	for (int i = 0; i < 3; i++) {
		nodes[i].firstChild = &nodes[i * 3 + 1];
		nodes[i * 3 + 1].nextBro = &nodes[i * 3 + 2];
		nodes[i * 3 + 2].nextBro = &nodes[i * 3 + 3];
	}
	printf("树的先序遍历：\n");
	first(source);
	printf("\n");
	printf("树的后序遍历：\n");
	after(source);
	printf("\n");
    return 0;
}
void first(struct tree*node) {
	printf("%d ", node->data);
	if (node->firstChild) {
		first(node->firstChild);
	}
	if (node->nextBro) {
		first(node->nextBro);
	}

}
void after(struct tree*node) {

	if (node->firstChild) {
		after(node->firstChild);
	}
	printf("%d ", node->data);
	if (node->nextBro) {
		after(node->nextBro);
	}

}
