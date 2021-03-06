// algorithm10.cpp: 定义控制台应用程序的入口点。
//KMP算法求子串

#include "stdafx.h"
#include<stdlib.h>
int* Index(char* mostr, char* substr);
bool whetherSame(char * mostr, char * substr, int mostrLength, int substrLength, int start);
int main()
{
	char a[] = "abcdbcdbcdedebc";
	char b[] = "bc";

	int* c = Index(a, b);
	for (int i = 1; i < c[0]; i++) {
		if (c[i] != -1) {
			printf("%d ", c[i]);
		}
	}
    return 0;
}
int* Index(char * mostr, char * substr) {
	int mostrLength = 0;
	int substrLength = 0;
	int index = 1;
	while (mostr[mostrLength] != '\0') {
		mostrLength++;
	}
	while (substr[substrLength] != '\0') {
		substrLength++;
	}
	int* a = (int *)malloc(sizeof(int)*mostrLength);
	for (int i = 0; i < mostrLength; i++) {
		a[i] = -1;
	}
	a[0] = mostrLength;
	for (int i = 0; i < mostrLength; i++) {
		if (mostr[i] == substr[0]) {
			bool ifSame = whetherSame(mostr, substr, mostrLength, substrLength, i);
			if (ifSame) {
				a[index++] = i;
			}
			else {
				continue;
			}
		}
	}
	return a;
}
bool whetherSame(char * mostr, char * substr,int mostrLength,int substrLength, int start) {
	int a = start;
	for (int i = 0; i < substrLength; i++) {
		if (a == mostrLength) {
			return false;
		}
		else {
			if (substr[i] == mostr[a]) {
				a++;
				continue;
			}
			else {
				return false;
			}
		}
	}
	return true;
}

