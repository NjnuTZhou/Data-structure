// algorithm6.cpp: 定义控制台应用程序的入口点。
//表达式求值

#include "stdafx.h"

char getPrior(char symbol, char top);
int Operate(char theta, int nd1, int nd2);
int main()
{


	char expression[12] = { '(','2', '+', '3',')', '*', '2', '+', '6', '/', '3','#' };

	int opnd[100] = { 0 };
	char optr[100] = { '.' };
	int ndindex = 0;
	int trindex = 0;

	optr[0] = '#';
	trindex = 1;
	int i = 0;
	while (expression[i]!='#' || optr[trindex - 1] != '#') {
		if ((int)expression[i] - '0' >= 0 && (int)expression[i] - '0' <= 9) {
			opnd[ndindex] = (int)(expression[i] - '0');
			ndindex++;
			i++;
		}
		else {
			char value = getPrior(expression[i], optr[trindex - 1]);
			printf("%c\n", value);

			switch (value) {
			case  '<':
				optr[trindex] = expression[i];
				trindex++;
				i++;
				break;

			case '=':
				optr[trindex - 1] = NULL;
				trindex--;
				i++;
				break;

			case '>':
				char theta = optr[trindex - 1];
				optr[trindex - 1] = NULL;
				trindex--;
				int nd1 = opnd[ndindex - 1];
				opnd[ndindex - 1] = 0;
				ndindex--;
				int nd2 = opnd[ndindex - 1];
				opnd[ndindex - 1] = 0;
				ndindex--;
				int nd = Operate(theta, nd1, nd2);
				opnd[ndindex] = nd;
				ndindex++;
				break;
			}
		}
	}
	printf("%d", opnd[ndindex - 1]);
    return 0;
}
char getPrior(char symbol,char top) {
	char prior[8][8] = { 
	{ '.','+','-','*','/','(',')','#' },
	{ '+','>','>','<','<','<','>','>' },
	{ '-','>','>','<','<','<','>','>' },
	{ '*','>','>','>','>','<','>','>' },
	{ '/','>','>','>','>','<','>','>' },
	{ '(','<','<','<','<','<','=',' ' },
	{ ')','>','>','>','>',' ','>','>' },
	{ '#','<','<','<','<','<',' ','=' } 
	};
	printf("%c,%c,", top,symbol);
	int rowNum = 0;
	int colNum = 0;
	for (int i = 0; i < 8; i++) {
		if (prior[i][0] == top) {
			rowNum = i;
		}
		if (prior[0][i] == symbol) {
			colNum = i;
		}
	}
	return prior[rowNum][colNum];

}

int Operate(char theta, int nd1, int nd2) {
	switch (theta) {
	case '+':
		return nd1 + nd2;
		break;
	case '-':
		return nd2 - nd1;
		break;
	case '*':
		return nd2 * nd1;
		break;
	case '/':
		return nd2 / nd1;
		break;
	}
	
}

