#ifndef __EXPRESSIONS_H__
#define __EXPRESSIONS_H__

#include "../../stack/src/Stack.h"

using namespace std;

/************************************************************************/
/* author	��yejie														*/
/* date		��20161220 pm												*/
/* contact	��1175016496@qq.com											*/
/* describe	�����ʽ���												*/															
/************************************************************************/

#define EXPRE_LENGTH		100
#define CODE_SUCCESS		0
#define CODE_EXPRE_NOLEGAL	1
#define CODE_ERR			2

class Expressions
{
	typedef struct{
		char buf[EXPRE_LENGTH];
		int length;
}Buffer;

private:
	static Expressions* gInstance;

	char mExpre[EXPRE_LENGTH];
	int mExpreLength;
	
	Stack<int> mOpnd;	//������ջ
	Stack<char> mOptr;	//������ջ

	int mPoint;

private:
	Expressions();
	~Expressions();

	void init();

public:
	static Expressions* getInstance();

	void setExpre(char* expre);

	int exeCalculate(int& result);

	void destory();

private:
	bool legalCheck(char* expre);

	Buffer getNext(int& point);

	bool isOptr(char c);

	int char2Int(char* c, int length);

	char precede(char c1, char c2);

	int operate(int a, char c, int b);

};

#endif