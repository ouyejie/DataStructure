#include "Expressions.h"
#include <stdlib.h>


Expressions* Expressions::gInstance = NULL;

Expressions::Expressions()
{

}

Expressions::~Expressions()
{

}

Expressions* Expressions::getInstance()
{
	if (!gInstance)
	{
		gInstance = new Expressions();
	}
	gInstance->init();
	return gInstance;
}

void Expressions::init()
{
	mOpnd.InitStack();
	mOptr.InitStack();
}

void Expressions::setExpre(char* expre)
{
	for (int i = 0; i < EXPRE_LENGTH; i++)
	{
		mExpre[i] = expre[i];
	}
}

char* Expressions::exeCalculate()
{
	char result[EXPRE_LENGTH] = { 0 };

	mOpnd.ClearStack();
	mOptr.ClearStack();
	mPoint = 0;

	return NULL;
}

bool Expressions::legalCheck()
{
	return true;
}

Expressions::Buffer Expressions::getNext()
{
	Buffer buf;
	int count = 0;
		
	for (; mExpre[mPoint] = '#'; count++, mPoint++)
	{
		if (isOptr(mExpre[mPoint]) && 0 == count)
		{
			buf.buf[count] = mExpre[mPoint];
			buf.length = 1;
			break;
		}
		else
		{
			if (isOptr(mExpre[mPoint])) break;
			buf.buf[count] = mExpre[mPoint];
			buf.length = count+1;
		}
	}

	return buf;
}

bool Expressions::isOptr(char c)
{
	if (c == '+' ||
		c == '-' ||
		c == '*' ||
		c == '/' ||
		c == '(' ||
		c == ')' ||
		c == '#')
	{
		return true;
	}
	return false;
}

int Expressions::char2Int(char* c, int length)
{
	int sum = 0;
	int n = 1;
	for (int i = length-1; i >= 0; i--)
	{
		sum += (c[i] - '0')*n;
		n *= 10;
	}
	return sum;
}

void Expressions::destory()
{
	if (gInstance)
	{
		delete gInstance;
		gInstance = NULL;
	}
}