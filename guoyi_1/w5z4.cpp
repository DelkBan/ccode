//������ У�������

#include<iostream>
using namespace std;

int main()
{
	//freopen("C:\\Users\\DelkBan\\Downloads\\in (28).txt","r",stdin);
	int L,M,start,end;
		int count=0;
	cin >> L >> M;
	bool tree[L+1] = {true}; //��Ϊû�� ��һ���� 
	for (int i=0;i<=L;i++)
		{
		tree[i]=false;}
	for (int i=0;i<M;i++)
	{
		cin >> start >> end;
		for(int j=start;j<=end;j++)
		{
			if(!tree[j]) //������Ϊaû�У�Ϊ�� 
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
