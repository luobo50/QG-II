
#include<iostream>

#include<stack>

#include<string>



using namespace std;



//�������ȼ�

string priority = "#(+-*/)";



int locate(char c, string str) {

	int locate = str.find(c);

	if (locate == 2 || locate == 3) {

		return 2;

	}

	else {

		if (locate == 4 || locate == 5) {

			return 4;

		}

		else {

			return locate;

		}

	}



}





string MidToBack(string str) {

	string temp = "";   //��Ϊ���ص��ַ���

	stack <char> s;   //����ջ

	s.push('#');



	for (int i = 0; i < str.length(); i++) {

		switch (str[i]) {

		case '(':

			s.push('(');

			break;

		case ')':

			while (!s.empty() && s.top() != '(') {

				temp = temp + s.top();  //��ӽ����׺���ʽ

				s.pop(); //��ջ

			}

			s.pop();  //��(��ջ

			break;

		default:

			if (isalpha(str[i])) {  //�������ĸ

				temp = temp + str[i];

			}

			else {

				if ((s.top() == '(') || (s.top() != '(' &&

					locate(str[i], priority) > locate(s.top(), priority))) { //��ջ���ַ�Ϊ'('ʱ

					//�������ȼ�����ջ�����ַ����ȼ�

					s.push(str[i]); //��ջ

				}

				else {

					while (locate(str[i], priority) <= locate(s.top(), priority)) {

						//������ַ����ȼ�С��ջ���ַ����ȼ�

						temp = temp + s.top(); //��ӽ����׺���ʽ

						s.pop();  //��ջ

					}

					s.push(str[i]);//��ջ

				}

			}

			break;

		}

	}







	while (!s.empty()) {  //��ʣ�µ�������ӵ���׺���ʽ

		temp = temp + s.top();

		s.pop();

	}

	return temp;

}




/*
int main() {

	string str;

	cin >> str;



	cout << MidToBack(str) << endl;

	system("pause");

	return 0;



}
*/


/*

a+b-a*((c+d)/e-f)+g

*/
