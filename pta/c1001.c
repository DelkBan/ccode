// PTA�Ҽ� 1001 �����˲�������(3n+1)����
//2018.9.7 8:40 -- 8:46

#include<stdio.h>
int n;
int i = 0;

int main()
{
	scanf("%d",&n);
	while(n != 1)
	{
		if(n % 2 == 0)
		{
			n = n/2;
		}
		else
			n = (3*n+1)/2;
		i++;
	}
	printf("%d",i);
}
