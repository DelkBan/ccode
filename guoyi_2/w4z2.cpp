//派
//问题的关键是要将rmax设置成最大派的面积，而不是最小的派 

#include<iostream>
#include<cstdio>
using namespace std;

#define PI 3.141592653

int main()
{
	//freopen("C:\\Users\\DelkBan\\Downloads\\in (28).txt","r",stdin);
	int n,f; 
	cin >> n >>f;
	double s[n];//记录输入的每个派的半径 
	double rmax = PI*0.0; //初始化最终寻找到的面积 
	for(int i=0;i<n;i++)
	{
		cin >> s[i];
		s[i] = PI * s[i]*s[i]; //转化成面积 
		rmax = rmax>s[i]? rmax:s[i]; //rmax设为最大的派的面积 
	}
	double rmin=1e-5; //定义左起点
	double root=rmin+(rmax-rmin)/2;//设定初始中间值 
	int time=0;
	while(rmax-rmin > 1e-6) //不满足精确度就循环 
	{
		int sum=0;
//		time++;//计数 
		root = rmin+(rmax-rmin)/2;
		for(int i=0;i<n;i++) //计算当前大小下能分几块 
		{
			sum += (s[i]/root);
		}
		if(sum<f+1) //数量不够，需要变小，将max设为root 
		{
			rmax = root;
		}
		else if(sum>=f-1) rmin = root;
		//相等则判断是否满足精度 
		
	 }
	 printf("%.3lf",root);
//	 cout << time;
	
}
