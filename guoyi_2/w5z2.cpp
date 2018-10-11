// �����е�������
/*
˼·��
ʹ�÷��εķ�����������ֳ����룬�ֱ�������ߵ����������Ұ�ߵ�������
�ټ�������һ������һ������ɵ�������������
���߸���һ��ָ�룬�ź����Ժ�Աȣ�ֻ��Ҫ��ɨ��һ��
ʱ�临�Ӷ� nlogn 
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
			temp[pb++] = a[p2++];  //�����ǴӴ�С�� 
		else{
			temp[pb++] = a[p1++];
			count += e-p2+1;}
	}
	//����ѭ��������һ����һ�߻�û�н����������ǰ�ʣ�µĽ����� 
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
