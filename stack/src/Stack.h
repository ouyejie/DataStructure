#ifndef __STACK_H__
#define __STACK_H__

#include<stdlib.h>
#include<iostream>

using namespace std;

#define STACK_INT_SIZE	32
#define STACK_INCREMENT	16

#define ERROE_INIT_NOT_EMPTY	(-2)
#define ERROR_MALLOC			(-1)

template<typename T>
class Stack
{
public:
	enum Status
	{
		Status_OK,
		Status_Error,
	};

private:
	T* mTop;
	T* mBase;
	T* mTravel;
	unsigned int mStackSize;

public:
	Status InitStack()
	{
		if (!IsEmpty()) return Status_Error;

		mBase = (T*)malloc(STACK_INT_SIZE* sizeof(T));
		if (!mBase)	return Status_Error;

		mTravel = mTop = mBase;
		mStackSize = STACK_INT_SIZE;
		return Status_OK;
	}

	void DestroyStack()
	{
		ClearStack();
		delete mBase;
		mBase = NULL;
		mTop = NULL;
		mTravel = NULL;
	}

	void ClearStack()
	{
		if (!mTop || !mBase) return;
		while (mBase != mTop)
		{
			mTop--;
		}
		mTravel = mTop;
	}

	bool IsEmpty()
	{
		if (mBase == mTop) return true;
		else return false;
	}

	unsigned int GetStackLength()
	{
		return mTop - mBase;
	}

	Status GetTop(T& e)
	{
		T* p = mTop;

		e = *--p;
		return Stack::Status_OK;
	}

	void push(T e)
	{
		int n = mTop - mBase;
		if (mTop - mBase >= mStackSize - 1)
		{
			mBase = (T*)realloc(mBase, (mStackSize + STACK_INCREMENT)*sizeof(T));
			if (!mBase) return;
			mTop = mBase + mStackSize - 1;
			mStackSize += STACK_INCREMENT;
		}
		*mTop++ = e;
		mTravel = mTop;
	}

	Status pop(T &e)
	{
		if (mBase == mTop) return Status_Error;

		e = *--mTop;
		mTravel = mTop;
		return Status_OK;
	}

	void resetTravel()
	{
		mTravel = mTop;
	}

	Status getTravel(T& e)
	{
		if (mTravel != mBase)
		{
			e = *(--mTravel);
			return Status_OK;
		}
		return Status_Error;
	}

	void StackTraverse()
	{
		cout << endl;
		if (mBase == mTop) return;
		T* p = mTop;
		while (p != mBase)
		{
			cout << *--p << endl;
		}
	}
};

#endif