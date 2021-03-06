// algorithm9.cpp: 定义控制台应用程序的入口点。
//串连接
//求子串

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#define MAXLENGTH 15
void Concat(char* a, char* b);
void SubString(char a[], int start, int end,char * b);
int main()
{
	char a[MAXLENGTH] = "abcdefghijklmn";
	char b[10] = "ijklmnopq";
	Concat(a, b);
	printf("%s\n", a);
	char c[15];
	SubString(a, 3, 12, c);
	printf("%s", c);
    return 0;
}

void Concat(char* a, char* b){
	int aLength = 0;
	while (a[aLength] != '\0') {
		aLength++;
	}
	int bLength = 0;
	while (b[bLength] != '\0') {
		bLength++;
	}
	printf("%d,%d\n", aLength, bLength);
	if (aLength + bLength < MAXLENGTH) {
		for (int i = 0; i <= bLength; i++) {
			a[aLength++] = b[i];
		}
	}
	else {
		if (a = (char*)realloc(a, (aLength + bLength + 1) * sizeof(char))) {
			for (int i = 0; i < bLength; i++) {
				a[aLength++] = b[i];
			}
			a[aLength] = '\0';
		}
	}
}


void SubString(char a[], int start, int end,char * b) {
	int aLength = 0;
	while (a[aLength] != '\0') {
		aLength++;
	}
	if (start < aLength&&end >= 0 && start <= end) {
		if (start < 0) {
			int index = 0;
			if (end <= aLength) {
				for (int i = 0; i <= end; i++) {
					b[index++] = a[i];
				}
			}
			else {
				for (int i = 0; i < aLength; i++) {
					b[index++] = a[i];
				}
			}
			b[index] = '\0';
		}
		else {
			int index = 0;
			if (end <= aLength) {
				for (int i = start; i <= end; i++) {
					b[index++] = a[i];
				}
			}
			else {
				for (int i = start; i < aLength; i++) {
					b[index++] = a[i];
				}
			}
			b[index] = '\0';
		}
	}
	else {
		return;
	}
}

