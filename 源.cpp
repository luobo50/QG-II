
#include"��ͷ.h"


int main()
{
	sqStack sk;
	double value;
	ElemType e;
	char str[MAXSIZE] = { 0 };
	sk.base = sk.top = NULL;    //�����ж��Ƿ����
	//��ʼ����ջ
	InitStack(&sk);
	//�����������׺���ʽ
	printf("please enter expression<no space>:");
	scanf("%s", str);
	//�Ƚ�������ƥ��
	if (!MatchBrack(str))
		return 0;
	//���ַ����е���׺���ʽ�ָת��Ϊ��׺���ʽ�����ջ��'1+2+3'--->3.0 + 2.0 + 1.0ÿһ������һ��ջ�ռ�����
	GetMidStack(&sk, str);
	//���������׺���ʽ��ת����Ϊ������
	RotateStack(&sk);
	//���潫��׺���ʽת��׺���ʽ
	GetBackStack(&sk);
	//������ĺ�׺���ʽ��ת����Ϊ������
	RotateStack(&sk);
	//��ȡ��׺���ʽ���
	GetBackValue(&sk, &value);
	//PrintStack(sk);
	printf("Operation values:%lf", value);
	//PrintStack(sk);
	DestroyStack(&sk);
	system("pause");
	return 0;
}