//PTA 最大子列和问题 使用在线处理方法 

#include<stdio.h>
 int K;
 int MaxSubseqSum(int A[], int N);

 
 int main()
 {
 	scanf("%d", &K);/*获取数据数量*/
 	int A[K];
 	int i;
 	for(i=0;i<K;++i)
 	scanf("%d",&A[i]);
 	int Max = MaxSubseqSum(A,K);
 	printf("%d",Max);
 	return 0;
	  
 }
 
 int MaxSubseqSum(int A[], int N)
 {
 	int ThisSum, MaxSum;
 	int i;
 	ThisSum = MaxSum = 0;
 	for(i = 0; i < N; ++i)
 	{
 		ThisSum += A[i]; //向右累加
		if(ThisSum > MaxSum)
		 	MaxSum = ThisSum; //发现更大的和就更新结果
		else if (ThisSum < 0)
			ThisSum = 0; //若当前和小于零，则不可能使后面的为最大，清零 
	 }
	 return MaxSum;
 }

