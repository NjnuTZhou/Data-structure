// algorithm13.cpp: 定义控制台应用程序的入口点。
//矩阵乘法，三元组求积

#include "stdafx.h"
#include<stdlib.h>
struct triple {
	int row;
	int col;
	int num;
};
int getNotZeroNum(int** matrix, int row, int col);
struct triple* getTriple(int **matrix, int row, int col,int notZero);
void printMatrix(int** matrix, int row, int col);
void printTriple(struct triple * tr, int num);
int *getRowStart(struct triple *tr, int row, int notZero);
void printStart(int* matrix, int row);
int main()
{

	int** matrixA = (int **)malloc(sizeof(int *) * 3);
	int** matrixB = (int **)malloc(sizeof(int *) * 4);
	for (int i = 0; i < 3; i++) {
		matrixA[i] = (int *)malloc(sizeof(int) * 4);
		for (int j = 0; j < 4; j++) {
			matrixA[i][j] = 0;
		}
	}
	for (int i = 0; i < 4; i++) {
		matrixB[i] = (int *)malloc(sizeof(int) * 2);
		for (int j = 0; j < 2; j++) {
			matrixB[i][j] = 0;
		}
	}
	matrixA[0][2] = 3;
	matrixA[1][0] = 2;
	matrixA[1][3] = 2;
	matrixA[2][1] = 4;

	matrixB[1][1] = 2;
	matrixB[2][0] = 1;
	matrixB[3][0] = 2;
	matrixB[3][1] = 3;

	int notZeroA = getNotZeroNum(matrixA, 3, 4);
	int notZeroB = getNotZeroNum(matrixB, 4, 2);
	printf("A中非0元的个数：%d\n", notZeroA);
	printMatrix(matrixA, 3, 4);
	printf("B中非0元的个数：%d\n", notZeroB);
	printMatrix(matrixB, 4, 2);

	struct triple* trA = getTriple(matrixA, 3, 4, notZeroA);
	struct triple* trB = getTriple(matrixB, 4, 2, notZeroB);
	printf("A的三元组：\n");
	printTriple(trA, notZeroA);
	printf("B的三元组：\n");
	printTriple(trB, notZeroB);

	int* startA = getRowStart(trA, 3, notZeroA);
	int* startB = getRowStart(trB, 4, notZeroB);
	printf("数组A中每行首个非零元的位置：\n");
	printStart(startA, 3);
	printf("数组B中每行首个非零元的位置：\n");
	printStart(startB, 4);

	struct triple*trC = (struct triple*)malloc(sizeof(struct triple) * 3 * 2);
	int startC[3] = { 0 };

	//开始计算
	int notZeroC = 0;
	for (int i = 0; i < 3; i++) {
		int ctemp[2] = { 0 };
		startC[i] = notZeroC;
		int startPosA = startA[i];
		int endPosA = 0;
		if (i < 2) {
			endPosA = startA[i + 1];
		}
		else {
			endPosA = notZeroA;
		}
		for (int p = startPosA; p < endPosA; p++) {
			int brow = trA[p].col;
			int startPosB = startB[brow];

			int endPosB = 0;
			if (brow < 3) {
				endPosB = startB[brow + 1];
			}
			else {
				endPosB = notZeroB;
			}

			for (int j = startPosB; j < endPosB; j++) {
				int ccol = trB[j].col;
				ctemp[ccol] += trA[p].num*trB[j].num;
			}
		}
		for (int m = 0; m < 2; m++) {
			if (ctemp[m] != 0) {
				trC[notZeroC].row = i;
				trC[notZeroC].col = m;
				trC[notZeroC].num = ctemp[m];
				notZeroC++;
			}
		}
	}
	printf("C的三元组：\n");
	printTriple(trC, notZeroC);
    return 0;
}
int getNotZeroNum(int** matrix, int row, int col) {
	int notZero = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (matrix[i][j] != 0) {
				notZero++;
			}
		}
	}
	return notZero;
}
struct triple* getTriple(int **matrix, int row, int col, int notZero) {
	struct triple* tr = (struct triple*)malloc(sizeof(struct triple)*notZero);
	int index = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (matrix[i][j] != 0) {
				tr[index].row = i;
				tr[index].col = j;
				tr[index].num = matrix[i][j];
				index++;
			}
		}
	}
	return tr;
}
void printMatrix(int** matrix, int row, int col) {
	for (int i = 0; i<row; i++) {
		for (int j = 0; j < col; j++) {
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void printTriple(struct triple * tr, int num) {
	for (int i = 0; i < num; i++) {
		printf("(%d,%d,%d)\n", tr[i].row, tr[i].col, tr[i].num);
	}
	printf("\n");
}
int *getRowStart(struct triple *tr, int row,int notZero) {
	int * start = (int *)malloc(sizeof(int)*row);
	int index = 0;
	for (int i = 0; i < row; i++) {
		start[i] = 0;
	}
	for (index; index < row; index++) {
		for (int i = 0; i < notZero; i++) {
			if (index == tr[i].row) {
				start[index] = i;
				break;
			}
		}
	}
	return start;
}
void printStart(int* matrix, int row) {
	for (int i = 0; i < row; i++) {
		printf("%d ",matrix[i]);
	}
	printf("\n");
}

