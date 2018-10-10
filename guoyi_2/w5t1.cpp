//��������
#include<iostream>
using namespace std;
void swap(int &a,int &b)
{
	int temp=a;
	a = b;
	b = temp;
 } 
void QuickSort(int a[],int s,int e)
{
	if( s >= e)
		return;//�����ʼλ�ò�����ֹλ��С��˵����������
	int k = a[s]; //��k���������
	int i = s,j = e;
	while( i != j)
	{
		while( j > i && a[j]>=k)
			--j;
		swap(a[i],a[j]); //���k��a[i]�У�������ȥa[j]��
		while( i < j && a[i]<=k)
			++i;
		swap(a[i],a[j]); 
	 } //�������a[i]=a[j]=k
	 QuickSort(a,s,i-1);
	 QuickSort(a,i+1,e); 
}
int a[] = { 99,28,29,3,6,11,2,8,29,89};
int main()
{
	int size = sizeof(a)/sizeof(int);
	QuickSort(a,0,size-1);
	for(int i = 0;i<size;++i)
		cout << a[i] << ",";
	cout << endl;
		return 0;
}
