//郭老师的课，第二级，第一周，例题。
//eg.2 生理周期

#include<iostream>
#include<cstdio>
 
int main()
{
	int p,e,i,d,next;
	int flg = 1;
	scanf("%d %d %d %d",&p,&e,&i,&d);
	int di = d;
	while(flg)
	{
		d++;
		if(!((d-p)%23|| (d-e)%28 || (d-i)%33)){
			next = d;
			flg = 0;
		}
		
	}
	printf("the next triple peak occurs in %d days.",next - di);
	
}
