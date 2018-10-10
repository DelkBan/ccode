//第四题 校门外的数

#include<iostream>
using namespace std;

int main()
{
	//freopen("C:\\Users\\DelkBan\\Downloads\\in (28).txt","r",stdin);
	int L,M,start,end;
		int count=0;
	cin >> L >> M;
	bool tree[L+1] = {true}; //真为没树 第一个量 
	for (int i=0;i<=L;i++)
		{
		tree[i]=false;}
	for (int i=0;i<M;i++)
	{
		cin >> start >> end;
		for(int j=start;j<=end;j++)
		{
			if(!tree[j]) //有树改为a没有，为真 
				tree[j] = true;
		}
	 }
	 for(int i=1;i<=L+1;i++) 
	 {
	 
	 	if(!tree[i])
	 		count++;
	 }
	 cout << count;
	return 0;
 } 
