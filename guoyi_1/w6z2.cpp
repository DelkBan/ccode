//�ڶ��� �����Լ��

#include<iostream>
using namespace std;

int number(int a,int b)
{
	if(a<b)//��֤a����b 
	{
		int temp=a;
		a=b;
		b=temp;
	}
	if(a%b) //a%b��Ϊ0����Ҫ���� 
	{
		b=number(b,a%b);
	}
	return b;
 } 
 
 int main()
 {
 	int a,b;
 	cin >> a >> b;
 	cout << number(a,b) ;
 	return 0;
 }
