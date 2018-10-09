//第六周第一题 Pell数列
//用递归没法做 只能用数组 
#include<iostream>
using namespace std;

int Pell[1000001]={1,2};
 
 int main()
 {
 	freopen("C:\\Users\\DelkBan\\Downloads\\in (28).txt","r",stdin);
 	int n,k;
 	//先把数据模拟出来
	 for(int i=0;i<1000001;i++)
	 {
	 	Pell[i+2]=Pell[i]+2*Pell[i+1];
	 	Pell[i+2] %= 32767;
	  } 
 	cin >> n; 
 	for(int i=0;i<n;i++)
 	{
 		cin>>k;
 		cout<<Pell[k-1]<<endl;
 	
	 }
	 return 0;
 }
