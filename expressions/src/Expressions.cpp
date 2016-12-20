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
	mExpreLength = 0;
	for (int i = 0; i < EXPRE_LENGTH; i++)
	{
		mExpre[i] = expre[i];
		mExpreLength++;
		if (expre[i] == '#') break;
	}
}

int Expressions::exeCalculate(int& result)
{
	if (!legalCheck(mExpre))
	{
		result = 0;
		return CODE_EXPRE_NOLEGAL;
	}

	char c;
	int a = 0;
	int b = 0;

	char result[EXPRE_LENGTH] = { 0 };
	char optrTop;
	int opndTop = 0;
	mOpnd.ClearStack();
	mOptr.ClearStack();
	mPoint = 0;
	mOptr.push('#');
	mOptr.GetTop(optrTop);
	Buffer buffer = getNext(mPoint);

	while (!(optrTop == '#' && buffer.buf[0] == '#'))
	{
		if (!isOptr(buffer.buf[0]))
		{
			mOpnd.push(char2Int(buffer.buf, buffer.length));
			buffer = getNext(mPoint);
		}
		else
		{
			switch (precede(optrTop, buffer.buf[0]))
			{
			case '<':
				mOptr.push(buffer.buf[0]);
				buffer = getNext(mPoint);
				break;
			case '>':
				mOpnd.pop(a);
				mOpnd.pop(b);
				mOptr.pop(c);
				mOpnd.push(operate(b, c, a));
				break;
			case '=':
				mOptr.pop(c);
				buffer = getNext(mPoint);
				break;
			default:
				break;
			}
		}
		mOptr.GetTop(optrTop);
	}

	mOpnd.GetTop(opndTop);
	result = opndTop;
	return CODE_SUCCESS;
}

char Expressions::precede(char c1, char c2)
{
	if (c1 == '+' || c1 == '-')
	{
		if (c2 == '+' || c2 == '-' || c2 == ')' || c2 == '#')
		{
			return '>';
		}
		else
		{
			return '<';
		}
	}
	else if (c1 == '*' || c1 == '/')
	{
		if (c2 == '+' || c2 == '-' || c2 == '*' || c2 == '/' || c2 == ')' || c2 == '#')
		{
			return '>';
		}
		else
		{
			return '<';
		}
	}
	else if (c1 == '(')
	{
		if (c2 == '+' || c2 == '-' || c2 == '*' || c2 == '/' || c2 == '(')
		{
			return '<';
		}
		else if (c2 == ')')
		{
			return '=';
		}
		else
		{
			return 'E';
		}
	}
	else if (c1 == ')')
	{
		if (c2 == '+' || c2 == '-' || c2 == '*' || c2 == '/' || c2 == ')' || c2 == '#')
		{
			return '>';
		}
		else
		{
			return 'E';
		}
	}
	else if (c1 == '#')
	{
		if (c2 == '+' || c2 == '-' || c2 == '*' || c2 == '/' || c2 == '(')
		{
			return '<';
		}
		else if (c2 == '#')
		{
			return '=';
		}
		else
		{
			return 'E';
		}
	}
	else
	{
		return 'E';
	}
}

int Expressions::operate(int a, char c, int b)
{
	int result = 0;
	switch (c)
	{
	case '+':
		result = a + b;
		break;
	case '-':
		result = a - b;
		break;
	case '*':
		result = a * b;
		break;
	case '/':
		result = a / b;
		break;
	default:
		break;
	}
	return result;
}

bool Expressions::legalCheck(char* expre)
{
	int point = 0;
	Buffer buf = getNext(point);
	while (buf.buf[0] != '#')
	{
		if (buf.length == 1)
		{
			if (buf.buf[0] != '+' &&
				buf.buf[0] != '-' &&
				buf.buf[0] != '*' &&
				buf.buf[0] != '/' &&
				buf.buf[0] != '(' &&
				buf.buf[0] != ')')
			{
				return false;
			}
		}
		buf = getNext(point);
	}
	return true;
}

Expressions::Buffer Expressions::getNext(int& point)
{
	Buffer buf;
	buf.buf[0] = '#';
	buf.length = 1;
	int count = 0;
		
	for (; mExpre[point] != '#'; count++, point++)
	{
		if (isOptr(mExpre[point]) && 0 == count)
		{
			buf.buf[count] = mExpre[point];
			buf.length = 1;
			point++;
			break;
		}
		else
		{
			if (isOptr(mExpre[point])) break;
			buf.buf[count] = mExpre[point];
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
	int result = 0;
	int n = 1;
	for (int i = length-1; i >= 0; i--)
	{
		result += (c[i] - '0')*n;
		n *= 10;
	}
	return result;
}

void Expressions::destory()
{
	if (gInstance)
	{
		delete gInstance;
		gInstance = NULL;
	}
}