
#include<iostream>

#include<stack>

#include<string>



using namespace std;



//定义优先级

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

	string temp = "";   //作为返回的字符串

	stack <char> s;   //辅助栈

	s.push('#');



	for (int i = 0; i < str.length(); i++) {

		switch (str[i]) {

		case '(':

			s.push('(');

			break;

		case ')':

			while (!s.empty() && s.top() != '(') {

				temp = temp + s.top();  //添加进入后缀表达式

				s.pop(); //出栈

			}

			s.pop();  //将(出栈

			break;

		default:

			if (isalpha(str[i])) {  //如果是字母

				temp = temp + str[i];

			}

			else {

				if ((s.top() == '(') || (s.top() != '(' &&

					locate(str[i], priority) > locate(s.top(), priority))) { //当栈顶字符为'('时

					//或者优先级大于栈顶的字符优先级

					s.push(str[i]); //进栈

				}

				else {

					while (locate(str[i], priority) <= locate(s.top(), priority)) {

						//如果该字符优先级小于栈顶字符优先级

						temp = temp + s.top(); //添加进入后缀表达式

						s.pop();  //出栈

					}

					s.push(str[i]);//进栈

				}

			}

			break;

		}

	}







	while (!s.empty()) {  //将剩下的依次添加到后缀表达式

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
