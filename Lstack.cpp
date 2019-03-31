#include "Lstack.h"
#include<iostream>
void LSTACK::init(PSTACK pS)//栈初始化
{
	pS->pTop = (PNODE)malloc(sizeof(NODE));
	if (pS->pTop == NULL)
	{
		printf("内存分配失败");
		return;
	}
	else
	{
		pS->pBottom = pS->pTop;
		pS->pTop->pnext = NULL;
	}

}
bool LSTACK::isempty(PSTACK pS)//判定是否为空
{
	if (pS->pTop == pS->pBottom)
		return true;
	else
		return false;
}

void LSTACK::gettop(PSTACK pS)
{
	PNODE p = pS->pTop;
	printf ("%d ",p->data);
}

void LSTACK::push(PSTACK pS, int val)//入栈
{
	PNODE pnew= (PNODE)malloc(sizeof(NODE));
	pnew->data = val;
	pnew->pnext = pS->pTop;
	pS->pTop = pnew;

}

int LSTACK::pop(PSTACK pS, int *val)//出栈
{
	if (isempty(pS))
	{
		printf("栈空\n");
		return 0;
	}
	else
	{
		PNODE p = pS->pTop;
		pS->pTop = p->pnext;
		if (val != NULL)
		{
			*val = p->data;
			free(p);
			p = NULL;
		}
	}
	return 1;
}

void LSTACK::clearStack(PSTACK pS)  //清空栈
{
	if (isempty(pS))
	{
		free(pS);
		return;
	}
	else
	{
		PNODE p = pS->pTop;
		PNODE q = NULL;

		while (p != pS->pBottom)
		{
			q = p->pnext;
			free(p);
			p = q;
		}
		pS->pTop = pS->pBottom;
	}
}

void LSTACK::destoryStack(PSTACK pS)
{
	if (isempty(pS))
	{
		return;
	}
	else
	{
		PNODE p = pS->pTop;
		PNODE q = NULL;

		while (p != pS->pBottom)
		{
			q = p->pnext;
			free(p);
			p = q;
		}
		pS->pTop = pS->pBottom;
		free(pS);
	}

}

int LSTACK::Stacklength(PSTACK pS)
{
	PNODE p = pS->pTop;
	int i = 0;
	while (p != pS->pBottom)
	{
		p->pnext;
			i += 1;
	}
	return i;
}


