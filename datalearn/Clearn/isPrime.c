//�ж�����    ���ĳ�����ڵ��������� 

#include<stdio.h>
/*
int main()
{
	while(1){
	int x;
	printf("����һ�����֣��ҽ����������ǲ�������:\n");
	scanf("%d", &x);
	
	int i;
	int isPrime=1;
	
	if(x<2)
		printf("���������1������:\n");
	else
	{
	for(i=2;i<x;i++) //��2��x-1������x
	{
		if( !(x%i))
		{
			isPrime = 0;//��������������������� 
			break;
		}
	 } 
	 if(isPrime == 1)
	 	printf("%d��������\n",x);
	 else printf("%d��������\n",x);
	}
 } 
}
*/

int main()
{
	int x;
	printf("����һ�����֣�������������������������:\n");
	scanf("%d", &x);
	
	int i;
	int j;
	int isPrime=1;
	
	if(x<2)
		printf("���������1������:\n");
	else
	{
	for(i=2;i<=x;i++) //���� 
	{
		isPrime=1;
		for(j=2;j<i;j++)
		{
		if( !(i%j))
		{
			isPrime = 0;//��������������������� 
			break;
		}
	 } 
	 if(isPrime == 1)
	 	printf("%d\n",i);
	}
	}
}
