//判断素数    输出某个数内的所有素数 

#include<stdio.h>
/*
int main()
{
	while(1){
	int x;
	printf("输入一个数字，我将告诉你这是不是素数:\n");
	scanf("%d", &x);
	
	int i;
	int isPrime=1;
	
	if(x<2)
		printf("请输入大于1的整数:\n");
	else
	{
	for(i=2;i<x;i++) //用2到x-1的数除x
	{
		if( !(x%i))
		{
			isPrime = 0;//如果能整除，则不是素数。 
			break;
		}
	 } 
	 if(isPrime == 1)
	 	printf("%d是素数。\n",x);
	 else printf("%d不是素数\n",x);
	}
 } 
}
*/

int main()
{
	int x;
	printf("输入一个数字，输出不大于这个数的所有素数:\n");
	scanf("%d", &x);
	
	int i;
	int j;
	int isPrime=1;
	
	if(x<2)
		printf("请输入大于1的整数:\n");
	else
	{
	for(i=2;i<=x;i++) //遍历 
	{
		isPrime=1;
		for(j=2;j<i;j++)
		{
		if( !(i%j))
		{
			isPrime = 0;//如果能整除，则不是素数。 
			break;
		}
	 } 
	 if(isPrime == 1)
	 	printf("%d\n",i);
	}
	}
}
