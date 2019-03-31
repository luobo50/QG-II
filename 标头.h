#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<cctype>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define STACK_INIT_SIZE 100    //����ջ�ĳ�ʼ��С
#define STACK_INCR_SIZE 10    //����ջ��������С

#define MAXSIZE 100    //��׺���ʽ�ĳ���

typedef struct Data
{
	int flag;    //1Ϊ�ַ���2Ϊ������
	union
	{
		double num;
		char sign;
	}number;
}data;

typedef data ElemType;
typedef int Status;

typedef struct
{
	ElemType *base;    //ջ��ָ��
	ElemType *top;    //ջ��ָ��
	int stackSize;    //������������ǿ��޸ĵ�
}sqStack;



//�ĸ���������
Status InitStack(sqStack *s);    //��ʼ������������һ����ջ
Status ClearStack(sqStack *s);    //��ջ���
Status StackEmpty(sqStack s);    //��ջ���ڣ�����true�����򷵻�false
int StackLength(sqStack s);        //����ջS��Ԫ�ظ���

Status GetTop(sqStack s, ElemType *e);    //����ջ�����ҷǿգ���e����S��ջ��Ԫ��
Status Push(sqStack *s, ElemType e);    // ����ջ���ڣ�������µ�Ԫ��e��ջS�в���Ϊջ��Ԫ��
Status Pop(sqStack *s, ElemType *e);    //����ջ�����ҷǿգ�ɾ��ջ��Ԫ�أ�����e������ֵ
Status DestroyStack(sqStack *s);        //����ջ���ڣ���������

void PrintStack(sqStack s);    //��ӡ�������ݣ������ã������ν����ݳ�ջ


//��ʼ������������һ����ջ
Status InitStack(sqStack *s)
{
	s->base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
	if (!s->base)
		return ERROR;
	s->top = s->base;    //�ʼ��ջ������ջ��
	s->stackSize = STACK_INIT_SIZE;
	return OK;
}

//��ջ���,��ջ��ָ���ƶ���ջ�׼��ɣ�������С��Ҫ�޸ģ����ݲ���Ҫ��գ�������ջ�Ḳ��
Status ClearStack(sqStack *s)
{
	if (s == NULL)
		return ERROR;
	s->top = s->base;
	return OK;
}

//��ջ���ڣ�����true�����򷵻�false
Status StackEmpty(sqStack s)
{
	if (s.base == s.top)
		return TRUE;
	return FALSE;
}

//����ջS��Ԫ�ظ���
int StackLength(sqStack s)
{
	int length = s.top - s.base;    //ָ��֮�����㣬�ǰ����������ݴ�С�ֽ������
	return length;
}

//����ջ�����ҷǿգ���e����S��ջ��Ԫ��,ע�⣺ֻ�ǻ�ȡջ�����ݣ�����ջ
Status GetTop(sqStack s, ElemType *e)
{
	if (!e || StackEmpty(s) || !s.base)
		return ERROR;
	*e = *(s.top - 1);
	return OK;
}

//��ջ����������ջ���ڣ�������µ�Ԫ��e��ջS�в���Ϊջ��Ԫ��
Status Push(sqStack *s, ElemType e)
{
	ElemType* newStack;
	if (!s->base)
		return ERROR;

	if (s->top - s->base >= s->stackSize)    //ջ������Ҫ�ٷ���
	{
		newStack = (ElemType *)realloc(s->base, (s->stackSize + STACK_INCR_SIZE) * sizeof(ElemType));    //���·����С
		if (!newStack)    //���Ƿ���ʧ�ܣ��᷵��NULL
		{
			free(s->base);
			exit(0);    //����ʧ�ܣ�ֱ���˳�
		}
		s->base = newStack;
		//�������Ҫ��ջ��ָ������ƶ����µ�λ��
		s->top = s->base + s->stackSize;
	}
	*(s->top) = e;
	s->top++;
	return OK;
}

//����ջ�����ҷǿգ�ɾ��ջ��Ԫ�أ�ֻ��Ҫ��ջ��ָ�����Ƽ��ɣ�������e������ֵ
Status Pop(sqStack *s, ElemType *e)
{
	if (!s->base || !e || StackEmpty(*s))
		return ERROR;
	*e = *(--s->top);
	return OK;
}

//����ջ���ڣ�����������ֱ�ӽ�ջ��ָ���ͷż��ɣ���Ϊ�գ�
Status DestroyStack(sqStack *s)
{
	if (!s->base)    //����ջ����
	{
		s->stackSize = 0;
		free(s->base);
		s->base = s->top = NULL;
	}
	return OK;
}

//��ӡ����
void PrintStack(sqStack s)
{
	data d;
	int len = StackLength(s);
	for (int i = 0; i < len;i++)
	{
		Pop(&s, &d);
		if (d.flag == 1)
			printf("%c", d.number.sign);
		else
			printf("%lf", d.number.num);
	}
}

Status MatchBrack(char* str)
{
	char *cur = str;
	sqStack BrkSK;
	data d;
	char ch;
	Status sta = OK;;

	if (!str || !InitStack(&BrkSK))
		return ERROR;

	while (*cur != '\0')
	{
		if (*cur == '(' || *cur == '[' || *cur == '{')
		{
			d.flag = 1;
			d.number.sign = *cur;
			Push(&BrkSK, d);
		}
		else if (*cur == ')' || *cur == ']' || *cur == '}')
		{
			if (!GetTop(BrkSK, &d))
			{
				sta = ERROR;
				break;
			}
			ch = d.number.sign;
			if ((*cur == ')'&&ch == '(') || (*cur == ']'&&ch == '[') || (*cur == '}'&&ch == '{'))
				Pop(&BrkSK, &d);
			else
			{
				sta = ERROR;
				break;
			}
		}
		cur++;
	}
	DestroyStack(&BrkSK);
	return sta;
}

//��ȡ��׺���ʽ
Status GetMidStack(sqStack *s, char* str)
{
	char* cur, *start, *end;
	cur = start = end = str;
	char fnum[10] = { 0 };
	data d;

	if (!s || !str)
		return ERROR;

	while (*cur != '\0')
	{
		if (!isdigit(*cur) && *cur != '.')
		{
			if (cur > str&&isdigit(*(cur - 1)))
			{
				end = cur;
				memset(fnum, 0, 10);
				memcpy(fnum, start, (end - start));
				d.flag = 2;
				d.number.num = atof(fnum);
				Push(s, d);
			}
			d.flag = 1;
			d.number.sign = *cur;
			if (isdigit(*(cur + 1)))
				start = cur + 1;
			Push(s, d);
		}
		cur++;
	}
	if (start > end)    //��������ֽ�β����Ҫ�ٽ����ж�
	{
		end = cur;
		memset(fnum, 0, 10);
		memcpy(fnum, start, (end - start));
		d.flag = 2;
		d.number.num = atof(fnum);
		Push(s, d);
	}
	return OK;
}

//��ջ�е����ݷ�ת
Status RotateStack(sqStack* s)
{
	sqStack tempSk, *freeSk;
	if (!InitStack(&tempSk) || !s)
		return ERROR;
	data d;
	int length = StackLength(*s);
	for (int i = 0; i < length; i++)
	{
		Pop(s, &d);
		Push(&tempSk, d);
	}
	freeSk = s;
	*s = tempSk;
	DestroyStack(freeSk);
}

//��ȡ��׺���ʽ
Status GetBackStack(sqStack *s)
{
	sqStack OperaSk, ResSk, *tempSk;
	OperaSk.base = ResSk.base = NULL;
	data d, top;
	char pc;    //�洢���������
	int length = StackLength(*s);
	if (!s)
		return ERROR;
	if (!InitStack(&OperaSk) || !InitStack(&ResSk))
	{
		DestroyStack(&OperaSk);
		DestroyStack(&ResSk);
		return ERROR;
	}
	for (int i = 0; i < length; i++)
	{
		Pop(s, &d);
		if (d.flag == 2)
			Push(&ResSk, d);
		if (d.flag == 1)
		{
			if (GetTop(OperaSk, &top))
				pc = top.number.sign;

			if (d.number.sign == ')')
			{
				//��'('֮�ϵ������ȫ��������ResSk
				while (pc != '(')
				{
					Pop(&OperaSk, &d);
					Push(&ResSk, d);
					GetTop(OperaSk, &top);
					pc = top.number.sign;
				}
				Pop(&OperaSk, &d);    //��(һ�𵯳�
				continue;
			}

			if (StackEmpty(OperaSk) || pc == '(' || d.number.sign == '(')    //����OperaSkΪ�ջ���ջ��Ϊ(���߻�ȡ�������Ϊ(,����ֱ�ӽ���������ѹջ
				Push(&OperaSk, d);
			else if ((pc == '-' || pc == '+') && (d.number.sign == '*' || d.number.sign == '/'))    //����ջ�������ȼ��ͣ�Ҳѹջ������Ҫ�Ƚ�ջ����
				Push(&OperaSk, d);
			else if (pc == d.number.sign || (pc == '-'&&d.number.sign == '+') || (pc == '+'&&d.number.sign == '-') || (pc == '*'&&d.number.sign == '/') || (pc == '/'&&d.number.sign == '*'))    //��ջ�����ȼ��͵�ǰ�����һ�£��ȵ�����ResSk���ڽ���ѹջ
			{
				Pop(&OperaSk, &top);
				Push(&ResSk, top);
				Push(&OperaSk, d);
			}
			else  //����ȡ����������ȼ�����ջ�����ȼ����Ƚ�ջ���������ջ��ResSk��Ȼ���ٽ���ǰ���������һ�ν��бȽϣ�ѹջ��OperaSKջ
			{
				Pop(&OperaSk, &top);    //��ȡOperaSKջ������
				Push(&ResSk, top);        //�����ݷ���ResSKջ

				Push(s, d);    //���ڵ�ǰ����û�������ջ�����ǽ����Ż�ԭ��ջ�У��ٴν��бȽ�
				length++;
			}
		}
	}

	while (!StackEmpty(OperaSk))    //�������ջ�е�ʣ�������ȫ���Ƶ����ջ
	{
		Pop(&OperaSk, &d);
		Push(&ResSk, d);
	}

	tempSk = s;
	*s = ResSk;
	DestroyStack(tempSk);
	DestroyStack(&OperaSk);
	return OK;
}

//��ȡ��׺���ʽ��������Ľ��
Status GetBackValue(sqStack *s, double* val)
{
	sqStack OpValSk;    //��ȡ��������ջ
	int length = StackLength(*s);
	double op1, op2, value = 0;
	data d, top;

	if (!s || !InitStack(&OpValSk))
		return ERROR;

	for (int i = 0; i < length; i++)
	{
		Pop(s, &d);
		if (d.flag == 2)    //����
			Push(&OpValSk, d);
		else   //�����,ȡ����������󣬷Ż�ջ��
		{
			Pop(&OpValSk, &top);
			op2 = top.number.num;
			Pop(&OpValSk, &top);
			op1 = top.number.num;
			switch (d.number.sign)
			{
			case '+':
				value = op1 + op2;
				break;
			case '-':
				value = op1 - op2;
				break;
			case '*':
				value = op1 * op2;
				break;
			case '/':
				value = op1 / op2;
				break;
			default:
				break;
			}
			d.flag = 2;
			d.number.num = value;
			Push(&OpValSk, d);
		}
	}
	*val = value;
	DestroyStack(&OpValSk);
	return OK;
}