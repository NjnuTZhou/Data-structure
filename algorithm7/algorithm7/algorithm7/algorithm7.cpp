// algorithm7.cpp: 定义控制台应用程序的入口点。
//汉诺塔的实现

#include "stdafx.h"


int c = 0;
void hanoi(int n, char x, char y, char z);
void move(char x, int n, char z);
int main()
{
	while (1) {
		int num = 0;
		c = 0;
		printf("请输入汉诺塔的层数：");
		scanf_s("%d", &num);
		hanoi(num, 'x', 'y', 'z');
		printf("\n");

	}
	return 0;
}
void move( char x,int n, char z) {
	printf("%i. Move disk %i from %c to %c\n", ++c, n, x, z);
}
void hanoi(int n, char x, char y, char z) {
	if (n == 1) {
		move(x, 1, z);
	}
	else {
		hanoi(n - 1, x, z, y);
		move(x, n, z);
		hanoi(n - 1, y, x, z);
	}
}

