#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

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
	char temp[10] = { 0 };
	temp[0] = '1';
	temp[1] = '2';
	temp[2] = '3';
	temp[3] = '4';
	printf("%d\n", char2Int(temp, 4));

	system("pause");
	return 0;
}

