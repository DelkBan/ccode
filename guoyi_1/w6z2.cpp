//第二题 求最大公约数

#include<iostream>
using namespace std;

int number(int a,int b)
{
	if(a<b)//保证a大于b 
	{
		int temp=a;
		a=b;
		b=temp;
	}
	if(a%b) //a%b不为0，需要迭代 
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
