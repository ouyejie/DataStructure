#ifndef __EXPRESSIONS_H__
#define __EXPRESSIONS_H__

#include "../../stack/src/Stack.h"

using namespace std;

#define EXPRE_LENGTH 100

class Expressions
{
	typedef struct{
		char buf[EXPRE_LENGTH];
		int length;
	}Buffer;

private:
	static Expressions* gInstance;

	char mExpre[EXPRE_LENGTH];
	
	Stack<int> mOpnd;	//²Ù×÷ÊýÕ»
	Stack<char> mOptr;	//²Ù×÷·ûÕ»

	int mPoint;

private:
	Expressions();
	~Expressions();

	void init();

public:
	static Expressions* getInstance();

	void setExpre(char* expre);

	char* exeCalculate();

	Buffer getNext();

	bool isOptr(char c);

	int char2Int(char* c, int length);

	void destory();

private:
	bool legalCheck();

};

#endif