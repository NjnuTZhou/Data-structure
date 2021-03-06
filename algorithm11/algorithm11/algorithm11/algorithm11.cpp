// algorithm11.cpp: 定义控制台应用程序的入口点。
//模式匹配KMP

#include "stdafx.h"
#include<stdlib.h>


void Next(int next[], char substr[], int Length);
int getLength(char str[]);
int *getIndex(char mostr[], char substr[], int mostrLength, int substrLength, int next[]);
int main()
{
	char mostr[] = "abcdcdnjasdcsagbcdcdnjhdasdklcsa";
	char substr[] = "bcdcdnj";
	int mostrLength = getLength(mostr);
	int substrLength = getLength(substr);

	int* next = (int*)malloc(sizeof(int)*substrLength);
	Next(next, substr, substrLength);
	printf("%s\n", substr);
	for (int i = 0; i < substrLength; i++) {
		printf("%d", next[i]);
	}
	printf("\n\n");

	int* index = getIndex(mostr, substr, mostrLength, substrLength, next);
	for (int i = 0; i, mostrLength; i++) {
		printf("%d ", index[i]);
	}
    return 0;
}


int getLength(char str[]) {
	int length = 0;
	while (str[length] != '\0') {
		length++;
	}
	return length;
}

int * getIndex(char mostr[], char substr[], int mostrLength, int substrLength, int next[]) {
	int i = 0;
	int j = 0;
	int *index = (int *)malloc(sizeof(int)*mostrLength);
	for (int i = 0; i < mostrLength; i++) {
		index[i] = 0;
	}
	int in = 0;
	while (i < mostrLength&&j<substrLength) {
		if (mostr[i] == substr[j] || j == -1) {
			i++;
			j++;
		}
		else {
			j = next[j];
		}
		if (j >= substrLength) {
			index[in++] = i - substrLength;
			j = 0;
		}
	}
	return index;
}
void Next(int next[], char substr[], int Length) {
	next[0] = -1;
	int i = 0, j = -1;
	while (i < Length - 1) {
		if (substr[i] == substr[j] || j == -1) {
			i++;
			j++;
			next[i] = j;
		}
		else {
			j = next[j];
		}
	}
}
