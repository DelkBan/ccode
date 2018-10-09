//第三题 年龄与疾病

#include<iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int a[n];
	int b[4]={0};
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
		if(a[i]<=18)
			b[0]++;
		else if(a[i]>=18 && a[i]<=35)
			b[1]++;
		else if(a[i]>=36 && a[i]<=60 )
			b[2]++;
		else if(a[i]>=61)
			b[3]++;}
		float c[4];
		for (int i=0;i<4;i++)
		{
			c[i]=(float)b[i]/n * 10;
		}
		printf("%.2f%\n%.2f%\n%.2f%\n%.2f%\n",c[0],c[1],c[2],c[3]);
	
 } 
