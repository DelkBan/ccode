//�¶ȿ���

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
			left = a[i]; //�趨��ֵΪ�����տ��� 
		right += a[i];//�趨��ֵΪ�ܵĿ��� 
	}
	int mid=(left+right)/2;
	int sum,count;
	bool isCon=true;
	while(isCon)
	{
	
		mid = (left+right)/2;
		sum = 0;//������ʱ�� 
		count = 0;
		for(int i=0;i<n;i++)
		{
			if(sum+a[i]<mid)
			{
				sum += a[i];//���������������������� 
			}
			else
			{
				sum=0;
				count++;
				sum += a[i];
			}
		}
		if(count<m) //�����٣��������� 
			right = mid;
		else if(count < m)
			left = mid;
		else isCon=false;
	}
	cout << mid;
	return 0;
 } 
