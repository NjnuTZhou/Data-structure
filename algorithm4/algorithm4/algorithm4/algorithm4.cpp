// algorithm4.cpp: 定义控制台应用程序的入口点。
//十进制转八进制

#include "stdafx.h"


int main()
{
	int data[100] = { -1 };
	int num = 5224;
	int index = 0;
	while (num) {
		data[index] = num % 8;
		index++;
		num = num / 8;
	}
	for (int i = index - 1; i >= 0; i--) {
		printf("%d", data[i]);
	}
    return 0;
}

