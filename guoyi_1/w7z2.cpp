//�ҵ�һ��ֻ����һ�ε��ַ�
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char str[100001];
	gets(str);
	int len=strlen(str); 
	for(int i=0;i<len;i++)
	{
		int j=0,count=0;
		for(;j<len;j++)
		{
			if(str[i]==str[j])
				count++;
		}
		if(count==1) //ѭ��������˻�û���ҵ���ȵ�
		{
			cout<<str[i]<<endl;
			return 0;
		 }  
	}
	cout<<"no"<<endl;
	return 0;
	
 } 
