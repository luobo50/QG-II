#include<iostream>
#include"sqStack.h"
#include<stdlib.h>
#include<stdio.h>
#include"Lstack.cpp"
using std::cout;
using std::cin;;

int Priority(char ch)//�������ȼ��� 
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
	SqStack<char> s1(100);//�����ɺ�׺���ʽ
	SqStack<char> s2(100);//װ����
	SqStack<char> s3(100);//��������
	printf("������ʽ");
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
		while (s2.stackempty)//ʣ�µ������ȫ����ȥ
		{
			s1.push(s2.pop);
		}//��������˵��s1�Ѿ��Ǹ�����ĺ�׺���ʽ��
		s1.stackTranverse;
	
}
