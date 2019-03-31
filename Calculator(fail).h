#ifndef CALCULATOR_H
#define CALCULATOR_H
enum MAXSIZE
{
	STACK_INIT_SIZE=20,
	STACKINCREMENT=10,
	MAXBUFFER=10,
	MAX_EXP_LEN=100
};
template<typename ElemType>
class Calculator
{
public:
	struct Stack
	{
		ElemType *base;
		ElemType *top;
		int stackSize;

	};
	Calculator();
	~Calculator();
	void Push(ElemType e);
	bool Pop(ElemType &e);
	void clearStack();
	int StackLen();
	int Calculation(char Postfix[]);
	bool Infix2postfix(char infix[], char postfix[]);
private:
	Stack s;
};
#endif // CALCULATOR_H

