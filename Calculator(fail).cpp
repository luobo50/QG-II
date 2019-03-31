#include<stdio.h>
#include<iostream>
#include"Calculator(fail).h"
//stackSize
template<typename ElemType>
Calculator<ElemType>::Calculator()
{
	s.base = new ElemType[STACK_INIT_SIZE];
	if (s.base == NULL)
		exit(0);
	s.top = s.base;
	s.stackSize = STACK_INIT_SIZE;
}
template<typename ElemType>
Calculator<ElemType>::~Calculator()
{
	delete[]s.base;
}
template<typename ElemType>
void Calculator<ElemType>::Push(ElemType e)
{
	if (s.top - s.base >= s.stackSize)
	{
		s.base = (ElemType *)realloc(s.base, (s.stackSize + STACKINCREMENT) * sizeof(ElemType));
		if (s.base == NULL)
			exit(0);
		s.top = s.base + s.stackSize;
		s.stackSize = s.stackSize + STACKINCREMENT;
		
	}
	*(s.top) = e;
	s.top++;
}

template<typename ElemType>
bool Calculator<ElemType>::Pop(ElemType & e)
{    if(s.top==s.base)//空栈
	return false;
e = *(--(s.top));
return true;
}

template<typename ElemType>
void Calculator<ElemType>::clearStack()
{
	s.top = s.base;
}

template<typename ElemType>
int Calculator<ElemType>::StackLen()
{
	return s.top-s.base;
}

template<typename ElemType>
int Calculator<ElemType>::Calculation(char Postfix[])
{
	int i = 0, j;
	char c;
	char str[MAXBUFFER];
		double a = 0, b = 0;
	for (j = 0;Postfix[j] != '/0';j++)
	{
		//   c=Postfix[j];
		while ((Postfix[j]>=48)&&(Postfix[j]<=57)||Postfix[j]=='.')//输入数字
		{
			str[i] = Postfix[j];
			i++;
			str[i] = '\0';
			if (i >= 10)
			{
				printf("数据太长\n");
					return -1;
			}
			//scanf("%c,&c);
			j++;
			if ((Postfix[j] == ' '))
			{
				//str[i]='\0';
				//printf("str[%d]=%c\n,i,Postfix[j]);
				a = atof(str);
				//printf("%f \n",a);
				Push(a);
				i = 0;

			}
		}
		switch (Postfix[j])
		{
		case'+':
				Pop(a);
				if (!Pop(b))
				{
					Push(a);
					break;
				}
				Pop(b);
				Push(b + a);
				break;
			case'-':
				Pop(a);
				if (!Pop(b))
				{
					Push(-a);
					break;
				}
				Push(b - a);
				break;
			case'*':
				Pop(a);
				Pop(b);
				Push(b*a);
				break;
			case'/':
				Pop(a);
				if (a == 0)
				{
					printf("除数不能为零\n");
					return -1;
				}
				Pop(b);
				Push(b / a);
				break;
			default:break;
		}
		Pop(a);
		return a;
	}
	
}
template<typename ElemType>
bool Calculator<ElemType>::Infix2postfix(char infix[], char postfix[])
{
	Calculator<char> s;
	int i = 0, j = 0;
	char e;
	printf("输入表达式（中缀）");
	while (infix[j]!='\0');
	{
		while (infix[j] >= '0'&&infix[j] <= '9')
		{
			printf("%c", infix[j]);
			postfix[i++] = infix[j];
			j++;
			if (infix[j]<'0' || infix[j]>'9')
			{
				postfix[i++] = ' ';
				printf(" ");
			}
		}
		switch (infix[j])
		{
		case ')':
			s.Pop(e);
			while ('(' != e)
			{
				printf("%c", e);
				postfix[i++] = e;
				postfix[i++] = ' ';
				s.Pop(e);
			}
			break;
		case '+':
		case '-':if (s.StackLen() == 0)
			s.Push(infix[j]);
				 else
		{
			do {
				s.Pop(e);
				if ('(' == e)
				{
					s.Push(e);
				}
				else
				{
					printf("%c", e);
					postfix[i++] = e;
					postfix[i++] = ' ';
				}

			} while (s.StackLen() && '(' != e);
			s.Push(infix[j]);
		}
				 break;
		case '*':
		case '/':
		case '(':
			s.Push(infix[j]);
			break;
		case '\0':
			break;
		default:printf("输入格式有误\n");
			return 0;
			if (infix[j] == '/0')
				break;
			j++;
		}
	}
	while (s.StackLen())
	{
		s.Pop(e);
		printf("%c", e);
		postfix[i++] = e;
		postfix[i++] = ' ';
	}
	postfix[i] = '\0';
	printf("\n");
	return true;
}

