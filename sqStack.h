#ifndef sqStack_H
#define sqStack_H
#include<iostream>
using std::cout;
template <typename T>
class SqStack
{
private:
	T *m_pStack;
	int m_iSize;
	int m_iTop;
public:
	SqStack(int size);
	~SqStack();
	bool stackempty();
	void clearstack();
	int stacklength();
	bool push(T elem);
	bool pop(T &elem);
	int stackTop(T &elem);
	void stackTranverse();
};

template <typename T>
SqStack<T>::SqStack(int size)
{
	m_iSize = size;
	m_pStack = new T[m_iSize];
		m_iTop = 0;
}
template<typename T>
SqStack<T>::~SqStack()
{
	delete m_pStack;
	m_pStack = NULL;
}
template <typename T>
bool SqStack<T>::stackempty()
{
	return m_iTop == 0 ? true : false;
}

template<typename T>
 void SqStack<T>::clearstack()
{
	 m_iTop = 0;
}

template<typename T>
int SqStack<T>::stacklength()
{
	return m_iTop;
}

template<typename T>
 bool SqStack<T>::push(T elem)
{    if(stackFull())
	return false;
else {
	 m_pStack[m_iTop++] = elem;
	 return true;
 }
}

template<typename T>
 bool SqStack<T>::pop(T & elem)
{   if(stackempty())
	return false;
else {
	 elem = m_pStack[--m_iTop];
	 return true;
 }
}

template<typename T>
int SqStack<T>::stackTop(T & elem)
{
	if (stackEmpey())
		return false;
	else
	{
		elem = m_pStack[m_iTop - 1];
			return elem;
	}
}

template<typename T>
 void SqStack<T>::stackTranverse()
{
	 int i = 0;
	 for (i = 0;i < m_iTop;i++) {
		 cout << m_pStack[i];
	 }
}

#endif// sqStack_H