//����ʦһ�������ϿΣ���ƽ������

#include<iostream>
using namespace std;
double ERR = 0.001;//������� 

int main()
{
	double a;
	cin >> a;
	double x = a/2,lastx = a;
	while( x - lastx > ERR || lastx - x > ERR) //�����㾫�������ʱ����ݵ�����ʶ���м��� 
	{
		lastx = x;
		x = ((x + a/x)/2);
	}
	cout << x << endl;
	return 0;
	
 } 
