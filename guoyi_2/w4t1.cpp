//���ַ��󷽳̵ĸ�
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
	root = a+(b-a)/2; //һ��ʼ�����������е�
	y = f(root);
	while(fabs(y)>EPS)
	{
		if(y>0) //����X���Ϸ���˵��������� 
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
