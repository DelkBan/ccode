//w3t1
//表达式求值
 
#include<iostream>
//#include<cstring>

using namespace std;
int expression();
int term();
int factor();

//读入一个表达式并且返回值 
int expression() 
{
	int result = term(); //读取项，若只有一项则直接返回 
	while(true)
	{
		char op = cin.peek(); //查看但是不取出 
		if (op == '+' || op == '-')
		{
			cin.get(); //将符号取出来 
			int value = term(); //读取下一项
			if(op == '+')
				result += value;
			else
				result -= value; 
		}
		else break;
	}
	return result;
	 
}

int term()
{
	int result = factor();//读取因子
	while(true)
	{
		char op = cin.peek();
		if (op == '*' || op == '/')
		{
			cin.get();
			int value = factor(); //读取下一项
			if(op == '*')
				result *= value;
			else
				result /= value; 
		}
		else break;
	}
	return result;
}

int factor()
{
	int result = 0;//因子默认是没有的
	char d = cin.peek();
	if(d == '(') 
	{
		cin.get();
		result = expression();//获取括号中表达式的结果
		cin.get(); //取出右括号 
	}
	else
	{
		while(isdigit(d))
		{
			result = 10*result+d-'0'; //如果读取到的下一位是数字，则结果要在原来的基础上乘10，再加上读取到的数据
			cin.get();//取出当前数字 
			d = cin.peek();//识别下一个数字 
		}
	}
	return result;
}

int main()
{
	cout << expression() << endl;
	return 0;
}
