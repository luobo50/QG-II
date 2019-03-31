#include<iostream>
#include"sqStack.h"
#include<stdlib.h>
#include<stdio.h>
#include"Lstack.cpp"
using std::cout;
using std::cin;;

int Priority(char ch)//定义优先级别 
{
	int i;
	switch (ch)
	{
	case'+':i = 2;break;
	case'-':i = 2;break;
	case'*':i = 4;break;
	case'/':i = 4;break;
	default:i = -1;break;
	}
	return i;
}

int main()
{
	char ch[1000], ch2[1000];
	SqStack<char> s1(100);//最后会变成后缀表达式
	SqStack<char> s2(100);//装符号
	SqStack<char> s3(100);//用于运算
	printf("输入表达式");
	cin >> ch;
	int i = 0;
		while (i < sizeof(ch))
		{
			if (ch[i] >= '0'&&ch[i] <= '9' || ch[i] == '.')
			{
				s1.push(ch[i]);
				i++;
			}
			if (ch[i] == '(')
			{
				s2.push(ch[i]);
				i++;
			}
			if (ch[i] == ')')
			{
				while (s2.stackTop != '(')
				{
					s1.push(s2.pop);
				}
				i++;
			}
			if (ch[i] == '+' || '-' || '*' || '/')
			{
				if (s2.stackempty)
				{
					s2.push(ch[i]);
					i++;
				}
				else if (Priority(ch[i]) < Priority(s2.stackTop))
				{
					while (s2.stackempty || Priority(s2.stackTop) < Priority(ch[i]))
					{
						s1.push(s2.pop);
					}
					s2.push(ch[i]);
					i++;
				}
			}

		}
		while (s2.stackempty)//剩下的运算符全部进去
		{
			s1.push(s2.pop);
		}//理论上来说，s1已经是个成熟的后缀表达式了
		s1.stackTranverse;
	
}
