// algorithm16.cpp: 定义控制台应用程序的入口点。
//哈夫曼树构建以及查询

#include "stdafx.h"
#include<iostream>
#include<stdlib.h>

struct tree {
	int weight;
	char name;
	struct tree *parent;
	struct tree *leftchild;
	struct tree *rightchild;
};

void sortNodes(struct tree nodes[]);//对哈夫曼树的所有节点进行顺序排序
int InsertNode(struct tree nodes[], struct tree node);
void first(struct tree*node);
void search(struct tree nodes[], char a);
void searchChar(struct tree *node);
void getAllCode(struct tree *head);//求所有字符的哈弗曼编码
void pop();
void push(char a);
int nodesNum = 10;
char code[10];
int codeIndex = 0;
int main()
{
	char name[10] = { 'a','b','c','d','e','f','g','h','i','j' };
	int weight[10] = { 3,8,12,1,15,6,9,5,13,10 };

	struct tree nodes[19];
	for (int i = 0; i < 10; i++) {
		nodes[i].weight = weight[i];
		nodes[i].name = name[i];
		nodes[i].parent = NULL;
		nodes[i].leftchild = NULL;
		nodes[i].rightchild = NULL;
	}
	sortNodes(nodes);
	struct tree *head;
	for (int i = 0; i < 18; i=i+2) {
		struct tree parent;
		parent.weight = nodes[i].weight + nodes[i + 1].weight;
		parent.name = '#';
		parent.leftchild = &nodes[i];
		parent.rightchild = &nodes[i + 1];
		parent.parent = NULL;

		int index=InsertNode(nodes,  parent);
		nodes[i].parent = &nodes[index];
		nodes[i + 1].parent = &nodes[index];
		head = &parent;
		//printf("当前节点数组如下：\n");
		//for (int j = 0; j < 19; j++) {
		//	printf("%d:%d,%c\n", j, nodes[j].weight, nodes[j].name);
		//}
	}
	//printf("当前构建的树如下：\n");
	//first(head);
	printf("哈夫曼树构建完毕。\n");
	//初始化栈
	for (int i = 0; i < 10; i++) {
		code[i] = '\0';
	}
	getAllCode(head);
	//查找某个字符的哈弗曼编码
	printf("请输入需要查询的字符：\n");
	while (true) {
		char a = '#';
		scanf_s("%c", &a);
		for (int i = 0; i < 10; i++) {
			code[i] = ' ';
		}
		code[9] = '\0';
		codeIndex = 8;
		search(nodes, a);
		for (int i = 0; i < 10; i++) {
			if (code[i] != ' ') {
				printf("%c", code[i]);
			}
		}
		printf("\n");

	}
    return 0;
}
void pop() {
	code[codeIndex--] = '\0';
}
void push(char a) {
	code[codeIndex++] = a;
}
void getAllCode(struct tree *head) {
	if (head->leftchild == NULL || head->rightchild == NULL) {
		printf("%c,%s\n", head->name, code);
		pop();
		return;
	}
	else {
		push('0');
		getAllCode(head->leftchild);
		push('1');
		getAllCode(head->rightchild);
		pop();
		return;
	}
}
void search(struct tree nodes[], char a) {
	for (int i = 0; i < nodesNum; i++) {
		if (nodes[i].name == a) {
			searchChar(&nodes[i]);
		}
	}
}

void searchChar(struct tree* node) {
	if (node->parent->leftchild == node) {
		code[codeIndex--] = '0';
	}
	else if (node->parent->rightchild == node) {
		code[codeIndex--] = '1';
	}
	if (node->parent->parent != NULL) {
		searchChar(node->parent);
	}
}
int InsertNode(struct tree nodes[], struct tree node) {
	for (int i = nodesNum-1; i > 0; i--) {
		if (node.weight > nodes[i].weight) {
			for (int j = 18; j > i+1; j--) {
				nodes[j] = nodes[j - 1];
			}
			nodes[i + 1] = node;
			nodesNum++;
			return i + 1;
		}
	}
}
void sortNodes(struct tree nodes[]) {
	for (int i = 0; i < 10; i++) {
		int wei = nodes[i].weight;
		for (int j = 0; j < i; j++) {
			if (wei < nodes[j].weight) {
				struct tree tmp = nodes[i];
				for (int m = i; m >j; m--) {
					nodes[m] = nodes[m - 1];
				}
				nodes[j] = tmp;
				break;
			}
		}
	}
}

void first(struct tree*node) {
	printf("%d,%c\n", node->weight, node->name);
	if (node->leftchild != NULL) {
		first(node->leftchild);
	}
	if (node->rightchild != NULL) {
		first(node->rightchild);
	}
	return;
}

