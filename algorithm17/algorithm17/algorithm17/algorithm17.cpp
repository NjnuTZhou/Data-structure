// algorithm17.cpp: 定义控制台应用程序的入口点。
//图的建立和遍历
//图的深度优先搜索,图的广度优先搜索

#include "stdafx.h"
#include<stdlib.h>
#include<time.h>
struct arc {
	int node;
	struct arc*next;
	int weight;
};
struct node {
	char nodeName;
	struct arc*firstArc;
};
//图的构建
void buildChart(struct node*nodes, int node, int weight);
void showAllNodes(struct node*nodes, struct node allNodes[]);
void build(struct node nodes[]);
//图的深度优先搜索
void DepthScan(struct node allnodes[], struct node* startNode, int i);
//图的广度优先搜索
void WidthScan(struct node allnodes[], struct node* startNode, int i);
int DeQueue(int queue[],int *queuetail);
void InQueue(int queue[], int *queuetail, int index);
int queue[100];
int queuetail = 0;
bool isChecked[10];
bool isChecked1[10];
int main()
{
	srand((unsigned)time(0));
	struct node nodes[10];
	int start = 'a';
	for (int i = 0; i < 10; i++) {
		nodes[i].nodeName = start++;
		nodes[i].firstArc = NULL;
	}
	build(nodes);
	while (true) {
		char startNode = '0';
		printf("请输入开始搜索的节点：");
		scanf_s("%c", &startNode);
		for (int i = 0; i < 10; i++) {
			isChecked[i] = false;
			isChecked1[i] = false;
		}
		printf("搜索路径为：\n");
		for (int i = 0; i < 10; i++) {
			if (nodes[i].nodeName == startNode) {
				printf("深度优先的搜索结果：\n");
				DepthScan(nodes, &nodes[i], i);
				printf("广度优先的搜索结果：\n");
				isChecked1[i] = true;
				WidthScan(nodes, &nodes[i], i);
			}
		}
	}
	return 0;
}

void DepthScan(struct node allnodes[],struct node* startNode,int i) {
	isChecked[i] = true;
	if (startNode->firstArc != NULL) {
		struct arc *f = startNode->firstArc;
		while (f != NULL) {
			int m = f->node;
			if (isChecked[m] == false) {
				printf("%8c-->%8c%8d\n", startNode->nodeName, allnodes[m].nodeName, f->weight);
				DepthScan(allnodes, &allnodes[m], m);
			}
			else {
				f = f->next;
			}
		}
	}
}
void WidthScan(struct node allnodes[], struct node* startNode, int i) {
	if (startNode->firstArc != NULL) {
		struct arc *f = startNode->firstArc;
		struct arc *f1 = startNode->firstArc;
		//int queue[10];
		//int queuetail = 0;
		while (f != NULL) {
			int m = f->node;
			if (isChecked1[m] == false) {
				InQueue(queue, &queuetail, m);
				printf("%8c-->%8c%8d\n", startNode->nodeName, allnodes[m].nodeName, f->weight);
				isChecked1[m] = true;
			}
			f = f->next;
		}
		while(queuetail>0){
			int n = DeQueue(queue, &queuetail);
			WidthScan(allnodes, &allnodes[n], n);
		}
	}
}
int DeQueue(int queue[], int *queuetail) {
	int m = queue[0];
	for (int i = 0; i < *queuetail; i++) {
		queue[i] = queue[i + 1];
	}
	(*queuetail)--;
	return m;
}
void InQueue(int queue[],int *queuetail,int index) {
	queue[(*queuetail)++] = index;
}
void build(struct node nodes[]) {
	buildChart(&nodes[0], 1, 3);
	buildChart(&nodes[0], 4, 6);
	buildChart(&nodes[0], 5, 7);
	buildChart(&nodes[0], 9, 4);
	buildChart(&nodes[1], 0, 3);
	buildChart(&nodes[1], 2, 6);
	buildChart(&nodes[1], 3, 4);
	buildChart(&nodes[1], 7, 10);
	buildChart(&nodes[2], 1, 6);
	buildChart(&nodes[2], 4, 5);
	buildChart(&nodes[2], 7, 11);
	buildChart(&nodes[3], 1, 4);
	buildChart(&nodes[3], 5, 6);
	buildChart(&nodes[3], 8, 12);
	buildChart(&nodes[4], 0, 6);
	buildChart(&nodes[4], 2, 5);
	buildChart(&nodes[5], 0, 7);
	buildChart(&nodes[5], 3, 6);
	buildChart(&nodes[5], 7, 5);
	buildChart(&nodes[5], 8, 7);
	buildChart(&nodes[6], 9, 5);
	buildChart(&nodes[7], 1, 10);
	buildChart(&nodes[7], 2, 11);
	buildChart(&nodes[7], 5, 5);
	buildChart(&nodes[8], 3, 12);
	buildChart(&nodes[8], 5, 7);
	buildChart(&nodes[9], 0, 4);
	buildChart(&nodes[9], 6, 5);
	for (int i = 0; i < 10; i++) {
		showAllNodes(&nodes[i],nodes);
	}
}
void showAllNodes(struct node*nodes,struct node allNodes[]) {
	printf("%c：\n", nodes->nodeName);
	printf("连接的节点       权值\n");
	if (nodes->firstArc != NULL) {
		struct arc*n = nodes->firstArc;
		while (n != NULL) {
			printf("%10c%10d\n", allNodes[n->node].nodeName, n->weight);
			n = n->next;
		}
	}
	printf("\n");
}
void buildChart(struct node *nodes, int node, int weight) {
	if (nodes->firstArc == NULL) {
		struct arc* n = (struct arc*)malloc(sizeof(struct arc));
		n->next = NULL;
		n->weight = weight;
		n->node = node;
		nodes->firstArc = n;
	}
	else {
		struct arc*tail = nodes->firstArc;
		while (tail->next != NULL) {
			tail = tail->next;
		}
		struct arc* n = (struct arc*)malloc(sizeof(struct arc));
		n->next = NULL;
		n->weight = weight;
		n->node = node;
		tail->next = n;
	}
}

