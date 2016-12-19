#include<stdlib.h>
#include "Stack.h"

int main()
{
	Stack<char>* stack = new Stack<char>();
	stack->InitStack();
	
	char e;

	stack->push('1');
	stack->StackTraverse();
	stack->push('2');
	stack->StackTraverse();
	stack->push('3');
	stack->StackTraverse();
	stack->push('4');
	stack->StackTraverse();
	stack->push('5');
	stack->StackTraverse();
	stack->pop(e);
	stack->StackTraverse();
	stack->pop(e);
	stack->StackTraverse();
	stack->pop(e);
	stack->StackTraverse();
	stack->pop(e);
	stack->StackTraverse();
	stack->pop(e);
	stack->StackTraverse();
	stack->pop(e);
	stack->StackTraverse();
	stack->pop(e);
	stack->StackTraverse();
	system("pause");
	return 0;
}