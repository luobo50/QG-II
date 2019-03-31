#include <iostream>

#include <string>

#include <stack>

#include <map>

using namespace std;
void InfixToPostfix(const string infix, string& postfix)

{

	stack<char> mark;                       // ����ջ



	std::map<char, int> priority;               // �������ȼ�

	priority['+'] = 0;

	priority['-'] = 0;

	priority['*'] = 1;

	priority['/'] = 1;



	int infix_length = infix.size();            // ��׺���ʽ���ַ�����

	postfix.reserve(infix_length);

	for (int i = 0; i < infix_length; ++i) {

		switch (infix[i]) {

		case '0':

		case '1':

		case '2':

		case '3':

		case '4':

		case '5':

		case '6':

		case '7':

		case '8':

		case '9':

			postfix.push_back(infix[i]);
			break;

		case '+':

		case '-':

		case '*':

		case '/':

			if (!mark.empty()) {

				char markTop = mark.top();

				while (markTop != '(' && priority[infix[i]] <= priority[markTop]) {

					postfix.push_back(markTop);
					mark.pop();

					if (mark.empty()) {

						break;

					}

					markTop = mark.top();

				}

			}

			mark.push(infix[i]);
			printf(" ");
			break;

		case '(':

			if (infix[i - 1] >= '0' && infix[i - 1] <= '9') {    // 5(6/2-1) <==> 5*(6/2-1)

				mark.push('*');

			}

			mark.push(infix[i]);

			break;

		case ')':

		{

			char markTop = mark.top();

			while (markTop != '(') {

				postfix.push_back(markTop);

				mark.pop();

				markTop = mark.top();

			}

			mark.pop();

		}

		break;

		default:

			break;

		}

	}



	// ʣ���ȫ����ջ

	while (!mark.empty()) {

		postfix.push_back(mark.top());

		mark.pop();
	}

}
/*int main(int argc, char const *argv[])

{

	std::string infix = "1+2*3+(4*5+6)*7+(1+2)";

	std::string postfix;



	cout << "infix : " << infix << endl;

	InfixToPostfix(infix, postfix);

	cout << "postfix : " << postfix << endl;



	return 0;

}*/