// 1002 写出这个数 
// 2018.9.7 8:49--

#include<stdio.h>
#include<string.h>


int main()
{
	char n[100];
	int i = 0, sum = 0;
	int j;
	
	scanf("%s",n);
	while(n[i] != '\0')
	{
		sum += n[i] - '0'; //求和
		i++; 
	}
	char output[10][10] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
	
	int a,b,c = 0;
	c = sum % 10;
	b = sum/10 % 10;
	a = sum / 100;
	if(a==0 && b==0) printf("%s",output[c]);
	else if(a==0) printf("%s %s",output[b],output[c]);
	else printf("%s %s %s",output[a],output[b],output[c]);
	
}

//遇到过的问题：字符串的初始赋值，一定要先定义空间。字符串的定义有两种，一种是指针 
 




/*
int n;
int len;
int sum = 0;
void judge(int a[],int *);
int size(int n);

int main()
{
	scanf("%d",&n);
	len = size(n);
	int i;
	for(i =0;i<len;i++) //获取个位数字并求和 
	{
		sum += n % 10;
		n /= 10;
	}
	len = size(sum);
	int a[len];//存储结果各位数字
	for(i = 0;i<len;i++)
	{
		a[i] = sum %10;
		sum /= 10;
	 } 
	i = len - 1;
	while(i)
	{
		judge(a,&i);
		i--;
		printf(" ");
	}
	judge(a,&i);//输出最后一位 
	
	return 0;
}

int size(int n) //判断数字长度
{
	int size=0;
	while(n>0){
		n /= 10;
		size++ ;
	}
	return size;
 } 

void judge(int a[],int *i)
{
	int m = a[*i];
	char word[3];
	switch(m)
		{
			case 1: strcpy(word,"yi");break;
			case 2: strcpy(word,"er");break;
			case 3: strcpy(word,"san");break;
			case 4: strcpy(word,"si");break;
			case 5: strcpy(word,"wu");break;
			case 6: strcpy(word,"liu");break;
			case 7: strcpy(word,"qi");break;
			case 8: strcpy(word,"ba");break;
			case 9: strcpy(word,"jiu");break;
			case 0: strcpy(word,"ling");break;
		}
		printf("%s",word);
	return ;
}*/
