// 求排列的逆序数
/*
思路：
使用分治的方法，将数组分成两半，分别求出左半边的逆序数和右半边的逆序数
再计算由左一个数右一个数组成的逆序数的数量
两边各放一个指针，排好序以后对比，只需要各扫描一遍
时间复杂度 nlogn 
*/ 

//MergeSortAndCount

#include<iostream>
using namespace std;

long long int count=0;

void Merge(int a[],int s,int m,int e,int temp[])
{
	int pb=0;
	int p1=s,p2=m+1;
	while(p1 <= m && p2 <= e)
	{
		if(a[p1]<a[p2])
			temp[pb++] = a[p2++];  //这里是从大到小排 
		else{
			temp[pb++] = a[p1++];
			count += e-p2+1;}
	}
	//上述循环后两边一定有一边还没有结束，下面是把剩下的结束。 
	while(p1<=m)
		temp[pb++]=a[p1++];
	while(p2<=e)
		temp[pb++]=a[p2++];
	for(int i=0;i<e-s+1;++i)
		a[s+i]=temp[i];
}
void MergeSort(int a[],int s,int e,int temp[])
{
	if(s<e)
	{
		int m=s+(e-s)/2;
		MergeSort(a,s,m,temp);
		MergeSort(a,m+1,e,temp);
		Merge(a,s,m,e,temp);
	}
}
int main()
{
	freopen("C:\\Users\\DelkBan\\Downloads\\in (28).txt","r",stdin);
	int n;
	cin >> n;
	int a[n],b[n];
	for(int i=0;i<n;i++)
		cin >> a[i];
	MergeSort(a,0,n-1,b);
	cout<<count;
	return 0;
}
