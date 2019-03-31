#ifndef Stack_H
#define Stack_H
#include<iostream>
class LSTACK {

	typedef struct Node
	{
		int data;
		struct Node *pnext;
	}*PNODE, NODE;

	typedef struct Stack
	{
		PNODE pTop;
		PNODE pBottom;
	}STACK, *PSTACK;
public:
	void init(PSTACK);
	bool isempty(PSTACK);
	void gettop(PSTACK);
	void push(PSTACK, int);
	int pop(PSTACK, int *);
	void clearStack(PSTACK);
	void destoryStack(PSTACK);
	int Stacklength(PSTACK);


};
#endif
