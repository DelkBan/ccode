//郭老师一第三周上课，求平方根。

#include<iostream>
using namespace std;
double ERR = 0.001;//定义误差 

int main()
{
	double a;
	cin >> a;
	double x = a/2,lastx = a;
	while( x - lastx > ERR || lastx - x > ERR) //不满足精度需求的时候根据迭代共识进行计算 
	{
		lastx = x;
		x = ((x + a/x)/2);
	}
	cout << x << endl;
	return 0;
	
 } 
