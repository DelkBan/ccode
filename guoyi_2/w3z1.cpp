//Boolean Expressions
//用递归，&和|相当于加减，！相当于乘除 
#include<iostream>
#include<cstring>

using namespace std;
char input[100001] = {0};
bool expression();
bool term();
bool factor();
int curCount = 0;//当前字符位置 

//将输入内容初始化 
void iniInput()
{
	cin.getline(input,10001);
	int len = strlen(input);//从头开始直到第一个'\0'的 长度
	char temp[10001] = {0};
	int j=0;
	for(int i = 0;i<len;i++)
	{
		if(input[i] != ' ')
			temp[j++] = input[i];
		input[i]='\0';
	 }
	 for(int i = 0;i<len;i++)
	 	input[i] = temp[i];
}

bool expression()
{
	bool result = term();
	while(true)
	{
		char op = input[curCount];
		if(op == '&' || op == '|')
		{
			curCount++;
			bool value = term();
			if(op == '&')
				result &= value;
			else
				result |= value;
				
		}
		else break;
	}
	return result;
}

bool term()
{
	bool result = factor();
	while(true)
	{
		char op = input[curCount];
		if(op == '!')
		{
			curCount++;
			result = !factor();
		}
		else break;
		
	}
	return result;
}

bool factor()
{
	bool result = true;
	char d = input[curCount];
	 if(d == '(')
	{
		curCount++;
		result = expression();
		curCount++;
		d = input[curCount];
	}
	else if(d == 'V'){
		curCount++;
		result =  true;}
	else if(d == 'F'){
		curCount++;
		result = false;}
	else if(d== '!'){
		result = term();
	}

}

void output()
{
	int n = 0;
	while(cin.getline(input,10001))
	{
		iniInput();
		cout << "Expression " << ++n <<": " << (expression()? "V":"F" )<<endl;
		curCount = 0;
	}
	memset(input,0,10001);//清零操作 
}

int main()
{
	output();
	return 0;
}
