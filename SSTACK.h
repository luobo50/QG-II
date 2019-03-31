
#include <iostream>

#include <stdlib.h>

#include <stdio.h>
using namespace std;
struct Node {

	float date;

	Node *next;

};

class Stack {

private:

	Node *top;

public:

	Stack()

	{

		top = NULL;

	}

	~Stack();

	void Push(float Elem);//��ջ

	float Pop();//��ջ

	float Top();//ջ��Ԫ��

	bool Empty()

	{

		return (top == NULL);

	}

};

Stack::~Stack()

{

	Node *p;

	while (top)

	{

		p = top->next;

		delete top;

		top = p;

	}

	cout << "ջ�����" << endl;

}

float Stack::Pop()

{

	if (top == NULL)
	{
		cout << "ջ��" << endl;
		return -1;
	}

	Node *p;

	float temp;

	temp = top->date;

	p = top;

	top = top->next;

	delete p;

	return temp;

}

void Stack::Push(float Elem)

{

	Node *s;

	s = new Node;

	s->date = Elem;

	s->next = top;

	top = s;

}

float Stack::Top()

{

	return top->date;

}
/*
int main()

{

	Stack st;

	char ch;

	//����ȡ��ջ��Ԫ�أ�����num1,num2�У�sumΪ������������

	float num1, num2, sum;

	char buffer[10];//����������Ų�����

	int i = 0;

	cout << "�������׺���ʽ:���ÿո��������#Ϊ������־��" << endl;

	scanf("%c", &ch);

	while (ch != '#')

	{

		while ((ch >= '0'&&ch <= '9') || ch == '.')//0~9������ֻ�С������뻺��������

		{

			buffer[i] = ch;

			i++;

			buffer[i] = '\0';//���������һλԪ��Ϊ��\0'�������ַ���������atof����

			scanf("%c", &ch);

			if (ch == ' ')//�����ȡ���ո�˵���Ѷ�ȡ��һ��������

			{

				float temp = atof(buffer);//���ַ���תΪ������

				st.Push(temp);//��ջ

				i = 0;//������

				break;//��ȡ��һ����������ѭ�������ж�

			}

		}

		if (ch == '+' || ch == '-' || ch == '*' || ch == '/')//���ch�������

		{

			num1 = st.Pop();//ȡ������ջ��Ԫ��

			num2 = st.Pop();

			//��ȡ�����Ǹ����������ǰ

			switch (ch)

			{

			case '+':

				sum = num2 + num1;

				st.Push(sum);

				break;

			case '-':

				sum = num2 - num1;

				st.Push(sum);

				break;

			case '*':

				sum = num1 * num2;

				st.Push(sum);

				break;

			case '/':

				sum = num2 / num1;

				st.Push(sum);

				break;

			}

		}

		scanf("%c", &ch);

	}

	cout << st.Pop() << endl;

	return 0;

}
*/