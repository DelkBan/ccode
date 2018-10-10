//二分法求方程的根
//f(x) =x^3-5x^2+10x-80=0

#include<iostream>
#include<cmath>
using namespace std;
double EPS=1e-6;
double f(double x){
	return x*x*x - 5*x*x + 10*x -80;
}
int main()
{
	double root,a=0,b=100,y;
	root = a+(b-a)/2; //一开始设置在区间中点
	y = f(root);
	while(fabs(y)>EPS)
	{
		if(y>0) //点在X轴上方，说明根在左侧 
		{
			b=root;
		}
		else a=root;
		root = a+(b-a)/2;
		y=f(root);
	 } 
	 printf("%.8f\n",root);
	 return 0;
	
}
