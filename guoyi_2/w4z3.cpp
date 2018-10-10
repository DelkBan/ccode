//月度开销

#include<iostream>
using namespace std;

int main()
{
		freopen("C:\\Users\\DelkBan\\Downloads\\in (28).txt","r",stdin);
	int n,m;
	cin >> n >> m;
	int a[n];
	int left,right=0;
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
		if(left<a[i])
			left = a[i]; //设定左值为最大的日开销 
		right += a[i];//设定右值为总的开销 
	}
	int mid=(left+right)/2;
	int sum,count;
	bool isCon=true;
	while(isCon)
	{
	
		mid = (left+right)/2;
		sum = 0;//置零临时量 
		count = 0;
		for(int i=0;i<n;i++)
		{
			if(sum+a[i]<mid)
			{
				sum += a[i];//不超过最大量，则继续增加 
			}
			else
			{
				sum=0;
				count++;
				sum += a[i];
			}
		}
		if(count<m) //数量少，减少上限 
			right = mid;
		else if(count < m)
			left = mid;
		else isCon=false;
	}
	cout << mid;
	return 0;
 } 
