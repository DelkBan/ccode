// 郭老师一第三周例题  输出10000以内2的整数次幂
#include<iostream>
using namespace std;

int main()
{
	int x = 2;
	do{
		cout << x << endl;
		x *= 2;
	}while(x<10000);
	return 0;
	
 } 
