//郭老师的课，第二级，第一周，例题。

//eg.1 完美立方
#include<iostream>
#include<cstdio>
int main()
{
	int a,b,c,d,n;
	scanf("%d",&n);
	for(a = 1; a <= n;a++){
		for(b = 2; b < n;b++){
			for(c = b;c < n;c++){
				for(d = c;d < n;d++){
					if(a*a*a == b*b*b + c*c*c + d*d*d)
					printf("Cube = %d, Triple = (%d,%d,%d)\n",a,b,c,d);
				}
			}
		}
	}
	
 } 
