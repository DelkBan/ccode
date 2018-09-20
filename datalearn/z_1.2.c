//最大序列和升级版：返回最大序列和和序列的首尾数字

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
 	
 	int NumStart = 0, NumEnd = 0;//定义首尾数字初始位置 
 //	void MaxSubseqSum(A,K,NumStart,NumEnd,Max);
 
 
    int ThisSum, MaxSum;
 	int j;
 	
 	int ChangeCount = 0;//记录起点改变次数 
 	int temp = 0;//记录最大和更新时的起点改变次数 
 	int ChangeNum = 0;//临时记录改变后的新起点 
 	int AddCount = 0;//记录最大和更新次数 
 	ThisSum = MaxSum = 0;
 	for(j = 0; j < K; ++j)
 	{
 		ThisSum += A[j]; //向右累加
		if(ThisSum > MaxSum)
		{
			MaxSum = ThisSum; //发现更大的和就更新结果
			AddCount++;
			NumEnd = j;
			if(temp != ChangeCount) //如果此时起点已经改变 
				NumStart = ChangeNum;//将临时起点值注入NumStart 
			
		}	
		else if (ThisSum < 0)
		{
			ThisSum = 0; //若当前和小于零，则不可能使后面的为最大，清零
			ChangeCount++;
			ChangeNum = j+1;
		}
		
			 
	 }
	 
	 if(AddCount == 0)//说明没有正数 
	 {
	 	if(ChangeCount == K)//说明全是负数，则输出首尾 
			 NumEnd = K-1;
			 else  //有0存在
			 {
			 	A[NumStart]=0;
			 	A[NumEnd]=0;
			  } 
	  } 
 
 
 
 
 	printf("%d %d %d",MaxSum,A[NumStart],A[NumEnd]);
 	return 0;
	  
 }
 
 
 /*
 void MaxSubseqSum(int A[], int N,int &NumStart, int &NumEnd, int &MaxSum)
 {
 	int ThisSum, MaxSum;
 	int i;
 	
 	int ChangeCount = 0;//记录起点改变次数 
 	int temp = 0;//记录最大和更新时的起点改变次数 
 	int ChangeNum = 0;//临时记录改变后的新起点 
 	ThisSum = MaxSum = 0;
 	for(i = 0; i < N; ++i)
 	{
 		ThisSum += A[i]; //向右累加
		if(ThisSum > MaxSum)
		{
			MaxSum = ThisSum; //发现更大的和就更新结果
			NumEnd = i;
			if(temp != ChangeCount) //如果此时起点已经改变 
				NumStart = ChangeNum;//将临时起点值注入NumStart 
			
		}	
		else if (ThisSum < 0)
		{
			ThisSum = 0; //若当前和小于零，则不可能使后面的为最大，清零
			ChangeCount++;
			ChangeNum = i+1;
		}
			 
	 }
	 return;
 }
 */
