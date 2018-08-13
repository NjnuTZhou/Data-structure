// algorithm5.cpp: 定义控制台应用程序的入口点。
//括号匹配检验

#include "stdafx.h"


int main()
{
	char data[100] = { '.' };

	char a[10] = { '{','[','(','(',']','(',')','(',')','}' };
	int index = 0;
	for (int i = 0; i < 10; i++) {
		if (a[i] == '{' || a[i] == '[' || a[i] == '(') {
			data[index] = a[i];
			index++;
		}
		else if (a[i] == ')') {
			if (data[index - 1] == '(') {
				data[index - 1] = '.';
				index--;
			}
			else {
				data[index] = a[i];
				index++;
			}
		}
		else if (a[i] == ']') {
			if (data[index - 1] == '[') {
				data[index - 1] = '.';
				index--;
			}
			else {
				data[index] = a[i];
				index++;
			}

		}
		else if (a[i] == '}') {
			if (data[index - 1] == '{') {
				data[index - 1] = '.';
				index--;
			}
			else {
				data[index] = a[i];
				index++;
			}
		}

	}
	for (int i = 0; i < 100; i++) {
		printf("%c", data[i]);
	}
	printf("\n");
	printf("%d\n", index);
	if (index == 0) {
		printf("括号正确。\n");
	}
	else {
		printf("括号不正确。\n");
	}
    return 0;
}

