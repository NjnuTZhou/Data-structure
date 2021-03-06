// algorithm12.cpp: 定义控制台应用程序的入口点。
//快速转置

#include "stdafx.h"
#include <time.h>
#include<stdlib.h>
#define ROW 10

struct triple {
	int row;
	int col;
	int num;
};

int main()
{
	int notZero = 0;
	srand((unsigned)time(NULL));
	int matrix[ROW][ROW];
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < ROW; j++) {
			if (rand() % 5 <= 3) {
				matrix[i][j] = 0;
			}
			else {
				matrix[i][j] = rand() % 5 + 1;
				notZero++;
			};
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	int index = 0;
	struct triple* A = (struct triple*)malloc(sizeof(struct triple)*notZero);
	struct triple* B = (struct triple*)malloc(sizeof(struct triple)*notZero);
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j< ROW; j++) {
			if (matrix[i][j] != 0) {
				A[index].row = i;
				A[index].col = j;
				A[index].num = matrix[i][j];
				printf("(%d,%d,%d)\n", A[index].row, A[index].col, A[index].num);
				index++;
			}
		}
	}

	printf("\n\n");

	int num[ROW] = { 0 };
	int cpos[ROW] = { 0 };
	for (int i = 0; i < notZero; i++) {
		num[A[i].col]++;
	}
	cpos[0] = 0;
	for (int i = 1; i < ROW; i++) {
		cpos[i] = cpos[i - 1] + num[i - 1];
	}

	for (int i = 0; i < notZero; i++) {
		int col = A[i].col;
		int pos = cpos[col];
		B[pos].row = A[i].col;
		B[pos].col = A[i].row;
		B[pos].num = A[i].num;
		cpos[col]++;
	}

	for (int i = 0; i < notZero; i++) {
		printf("(%d,%d,%d)\n", B[i].row, B[i].col, B[i].num);
	}
    return 0;
}

