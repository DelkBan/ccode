#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	float a[4];
	float sum = 0;
//	int i;
	for(int i = 0;i<4;i++)
	{
		cin>>a[i];
	}
	sum = a[0]+a[1]+a[2]+a[3];
	float mid = sum / 4;
	int b = sum;
	cout<<"b= "<<b<<endl;
	cout<<"mid= "<<mid<<endl;
	printf("%.1f\n",mid);
	printf("%.0f",mid);

}
