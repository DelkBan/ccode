//快速排序
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
		return;//如果起始位置不比终止位置小，说明不用排序
	int k = a[s]; //将k定在最左侧
	int i = s,j = e;
	while( i != j)
	{
		while( j > i && a[j]>=k)
			--j;
		swap(a[i],a[j]); //起初k在a[i]中，交换后去a[j]中
		while( i < j && a[i]<=k)
			++i;
		swap(a[i],a[j]); 
	 } //处理完后，a[i]=a[j]=k
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
