//PTA ������к����� ʹ�����ߴ����� 

#include<stdio.h>
 int K;
 int MaxSubseqSum(int A[], int N);

 
 int main()
 {
 	scanf("%d", &K);/*��ȡ��������*/
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
 		ThisSum += A[i]; //�����ۼ�
		if(ThisSum > MaxSum)
		 	MaxSum = ThisSum; //���ָ���ĺ;͸��½��
		else if (ThisSum < 0)
			ThisSum = 0; //����ǰ��С���㣬�򲻿���ʹ�����Ϊ������� 
	 }
	 return MaxSum;
 }

