
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

	void Push(float Elem);//入栈

	float Pop();//出栈

	float Top();//栈顶元素

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

	cout << "栈已清空" << endl;

}

float Stack::Pop()

{

	if (top == NULL)
	{
		cout << "栈空" << endl;
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

	//两次取出栈顶元素，放入num1,num2中，sum为它俩的运算结果

	float num1, num2, sum;

	char buffer[10];//缓冲区，存放操作数

	int i = 0;

	cout << "请输入后缀表达式:（用空格隔开，以#为结束标志）" << endl;

	scanf("%c", &ch);

	while (ch != '#')

	{

		while ((ch >= '0'&&ch <= '9') || ch == '.')//0~9间的数字或小数点存入缓存数组中

		{

			buffer[i] = ch;

			i++;

			buffer[i] = '\0';//让数组最后一位元素为‘\0'，构成字符串，调用atof函数

			scanf("%c", &ch);

			if (ch == ' ')//如果读取到空格，说明已读取完一个操作数

			{

				float temp = atof(buffer);//把字符串转为浮点数

				st.Push(temp);//进栈

				i = 0;//重置零

				break;//读取了一个数后跳出循环重新判断

			}

		}

		if (ch == '+' || ch == '-' || ch == '*' || ch == '/')//如果ch是运算符

		{

			num1 = st.Pop();//取出两个栈顶元素

			num2 = st.Pop();

			//后取出的那个数在运算符前

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