//第三周作业 

#include<iostream>
#include<cstdio>
using namespace std;



int main()
{
	double x,y,a,b;
	int n;
	cin >> n;
	cin >> a >>b;
	x=b/a;
	int i;
	int ju[n];
	for(i=1;i<n;i++)
	{
		cin >> a >>b;
		y=b/a;
		if(y-x > 0.05)
			ju[i]=1;
		else if(x-y > 0.05)
			ju[i]=2;
		else
			ju[i]=0;
	}
	
	for(i=0;i<n-1;i++)
	{
		switch(ju[i]){
			case 0: 
				cout<<"same"<<endl;
				break;
			case 1:
				cout<<"better"<<endl;
				break;
			case 2:
				cout<<"worse"<<endl;
				break;
		}
	}
	
	switch(ju[n-1]){
			case 0: 
				cout<<"same";
				break;
			case 1:
				cout<<"better";
				break;
			case 2:
				cout<<"worse";
				break;
		}
	
		 
	
	
	
	return 0;
 } 
