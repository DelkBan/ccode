//��������ҵ �ڶ��� ��һԪ���η��̵ĸ� 

#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;
double a,b,c;
double x1,x2;

int main()
{
	cin >> a >> b >> c;
	if(b*b == 4*a*c)
	{
		x1 = (-b+sqrt(b*b-4*a*c))/(2*a);
		cout << fixed << setprecision(5) <<  "x1=x2=" << x1;
	}
	else if(b*b > 4*a*c)
	{
		x1 = (-b+sqrt(b*b-4*a*c))/(2*a);
		x2 = (-b-sqrt(b*b-4*a*c))/(2*a);
		cout << fixed << setprecision(5) << "x1=" << x1 <<";x2=" << x2;
	}
	else
	{
		x1 = -b/(2*a); //ʵ��
		x2 = sqrt(4*a*c-b*b)/(2*a); //�鲿
		if(b==0) x1 =0; 
		cout<<fixed << setprecision(5) <<"x1="<<x1<<"+"<<x2<<"i;x2="<<x1<<"-"<<x2<<"i";
	}
	
	
	
	
	
	return 0;
 } 
