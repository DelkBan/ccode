//w3t1
//���ʽ��ֵ
 
#include<iostream>
//#include<cstring>

using namespace std;
int expression();
int term();
int factor();

//����һ�����ʽ���ҷ���ֵ 
int expression() 
{
	int result = term(); //��ȡ���ֻ��һ����ֱ�ӷ��� 
	while(true)
	{
		char op = cin.peek(); //�鿴���ǲ�ȡ�� 
		if (op == '+' || op == '-')
		{
			cin.get(); //������ȡ���� 
			int value = term(); //��ȡ��һ��
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
	int result = factor();//��ȡ����
	while(true)
	{
		char op = cin.peek();
		if (op == '*' || op == '/')
		{
			cin.get();
			int value = factor(); //��ȡ��һ��
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
	int result = 0;//����Ĭ����û�е�
	char d = cin.peek();
	if(d == '(') 
	{
		cin.get();
		result = expression();//��ȡ�����б��ʽ�Ľ��
		cin.get(); //ȡ�������� 
	}
	else
	{
		while(isdigit(d))
		{
			result = 10*result+d-'0'; //�����ȡ������һλ�����֣�����Ҫ��ԭ���Ļ����ϳ�10���ټ��϶�ȡ��������
			cin.get();//ȡ����ǰ���� 
			d = cin.peek();//ʶ����һ������ 
		}
	}
	return result;
}

int main()
{
	cout << expression() << endl;
	return 0;
}
