#include <stdio.h>
#include <stdlib.h>
#include "Expressions.h"

int char2Int(char* c, int length)
{
	int sum = 0;
	int n = 1;
	for (int i = length - 1; i >= 0; i--)
	{
		sum += (c[i] - '0')*n;
		n *= 10;
	}
	return sum;
}

int main(int argc, char* argv[])
{
	char input[100] = { 0 };
	scanf("%s", input);
	Expressions* expressions = Expressions::getInstance();
	expressions->setExpre(input);
	int result;
	expressions->exeCalculate(result);
	printf("%d\n", result);
	expressions->destory();
	system("pause");
	return 0;
}

