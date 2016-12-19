/*
#include "Stack.h"
#include<stdlib.h>
#include<stdio.h>
#include<iostream>

using namespace std;

Status Stack::InitStack()
{
	if (!IsEmpty()) return Status_Error;

	mBase = (int*)malloc(STACK_INT_SIZE* sizeof(int));
	if (!mBase)	return Status_Error;

	mTop = mBase;
	mStackSize = STACK_INT_SIZE;
	return Status_OK;
	
}

void Stack::DestroyStack()
{
	ClearStack();
	delete mBase;
	mBase = NULL;
	mTop = NULL;
}

void Stack::ClearStack()
{
	if (!mTop || !mBase) return;
	while (mBase != mTop)
	{
		mTop--;
	}
}

bool Stack::IsEmpty()
{
	if (mBase == mTop ) return true;
	else return false;
}

unsigned int Stack::GetStackLength()
{
	return 0;
}

Stack::Status Stack::GetTop(int* e)
{
	return Stack::Status_OK;
}

void Stack::push(int e)
{
	int n = mTop - mBase;
	if (mTop - mBase >= mStackSize - 1)
	{
		mBase = (int*)realloc(mBase, (mStackSize + STACK_INCREMENT)*sizeof(int));
		if (!mBase) return;
		mTop = mBase + mStackSize - 1 ;
		mStackSize += STACK_INCREMENT;
	}
	*mTop++ = e;
}

Stack::Status Stack::pop(int& e)
{
	if (mBase == mTop) return Status_Error;

	e = *mTop--;
	return Status_OK;
}

void Stack::StackTraverse()
{
	cout << endl;
	if (mBase == mTop) return;
	int* p = mTop;
	while (p != mBase)
	{
		cout << *--p<<endl;
	}
}
*/