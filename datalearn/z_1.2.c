//������к������棺����������кͺ����е���β����

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
 	
 	int NumStart = 0, NumEnd = 0;//������β���ֳ�ʼλ�� 
 //	void MaxSubseqSum(A,K,NumStart,NumEnd,Max);
 
 
    int ThisSum, MaxSum;
 	int j;
 	
 	int ChangeCount = 0;//��¼���ı���� 
 	int temp = 0;//��¼���͸���ʱ�����ı���� 
 	int ChangeNum = 0;//��ʱ��¼�ı�������� 
 	int AddCount = 0;//��¼���͸��´��� 
 	ThisSum = MaxSum = 0;
 	for(j = 0; j < K; ++j)
 	{
 		ThisSum += A[j]; //�����ۼ�
		if(ThisSum > MaxSum)
		{
			MaxSum = ThisSum; //���ָ���ĺ;͸��½��
			AddCount++;
			NumEnd = j;
			if(temp != ChangeCount) //�����ʱ����Ѿ��ı� 
				NumStart = ChangeNum;//����ʱ���ֵע��NumStart 
			
		}	
		else if (ThisSum < 0)
		{
			ThisSum = 0; //����ǰ��С���㣬�򲻿���ʹ�����Ϊ�������
			ChangeCount++;
			ChangeNum = j+1;
		}
		
			 
	 }
	 
	 if(AddCount == 0)//˵��û������ 
	 {
	 	if(ChangeCount == K)//˵��ȫ�Ǹ������������β 
			 NumEnd = K-1;
			 else  //��0����
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
 	
 	int ChangeCount = 0;//��¼���ı���� 
 	int temp = 0;//��¼���͸���ʱ�����ı���� 
 	int ChangeNum = 0;//��ʱ��¼�ı�������� 
 	ThisSum = MaxSum = 0;
 	for(i = 0; i < N; ++i)
 	{
 		ThisSum += A[i]; //�����ۼ�
		if(ThisSum > MaxSum)
		{
			MaxSum = ThisSum; //���ָ���ĺ;͸��½��
			NumEnd = i;
			if(temp != ChangeCount) //�����ʱ����Ѿ��ı� 
				NumStart = ChangeNum;//����ʱ���ֵע��NumStart 
			
		}	
		else if (ThisSum < 0)
		{
			ThisSum = 0; //����ǰ��С���㣬�򲻿���ʹ�����Ϊ�������
			ChangeCount++;
			ChangeNum = i+1;
		}
			 
	 }
	 return;
 }
 */
