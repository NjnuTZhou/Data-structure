#include<stdio.h>
#include<stdlib.h>
//有序线性表的合并
void main() {
	int a[5] = { 2,5,8,11,16 };
	int b[10] = { 3,4,6,9,10,11,16,19,20,21 };

	int c[15] = {};
	int i = 0;
	int j = 0;
	int p = 0;
	while (i < 5 && j < 10) {
		if (a[i] <= b[j]) {
			c[p] = a[i];
			i++;
		}
		else {
			c[p] = b[j];
			j++;
		}
		p++;
	}
	if (i == 5) {
		for (j; j < 10; j++) {
			c[p] = b[j];
			p++;
		}
	}
	else if (j == 10) {
		for (i; i < 5; i++) {
			c[p] = a[i];
			p++;
		}
	}
	for (int i = 0; i < 15; i++) {
		printf("%d,", c[i]);
	}
	return;
}