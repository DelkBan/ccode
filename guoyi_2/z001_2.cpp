//����ʦ�������㷨�Σ�������һ����ҵ001������������
/*
˼·��ֻҪ��һ����״̬ȷ���ˣ�����İ�����ȷ���ˣ�ֻ��Ҫ�Ա����һλ�Ƿ��Ŀ����ͬ���ɡ�
	ö�ٴ���Ϊ�����ֱ��ǵ�һ����/������ 
*/

 
#include<iostream>
#include<cstring>
using namespace std;

int iniState;//���ԭʼ״̬
int aimState;//���Ŀ��״̬
int mixCount =999; //�����С���� 

int GetBit(int c,int i)//ȡc�ĵ�iλ
{
	return(c >> i) & 1;
 } 
 
 //����c�ĵ�iλΪv 
void SetBit(int &c, int i,char v) 
{
	
	if(v == '1'){
		c |= (1 << i);
	}
	else if (v == '0')
	{
		c &= ~(1 << i);
	}
}

//��תc�ĵ�iλ
void FlipBit(int &c, int i){
	c ^= (1 << i);
} 

int main()
{
	string ini,aim;
	getline(cin,ini);
	getline(cin,aim);
	
	int len = ini.size(); //lenΪ��������ݵĳ���
	int count=0,mixCount=999; //�����������С������� 	 
	for (int i = 0;i<len;i++) //��Ϊλ��ʾ 
	{
		SetBit(iniState,i,ini[i]);
		SetBit(aimState,i,aim[i]);
	}
	
	for(int n = 0; n < 2; n++) //ö�ٿ�ͷ�����ֿ���
	{
		int state = iniState;
		int count = 0;

		int flag = n;//��ʼ����־λ��1��0����
		if(n){
			FlipBit(state,0); //�����һ������ 
			FlipBit(state,1);//�ڶ�������ҲҪ��ת 
			count ++ ;
		}
		for(int i = 1; i < len; i++)  
		{
			if(GetBit(state,i-1) == GetBit(aimState,i-1))//���ϸ����ݺ�Ŀ��һ�£���flagΪ0
				flag = 0;
			else flag = 1;
			if(flag == 1) //�跭ת
			{
				count ++ ;
				FlipBit(state,i); //��ת��ǰλ
				 if(i != len-1)
				 	FlipBit(state,i+1); //δ���߽磬��ת��һλ��
					 //��һλ����Ҫ������ֻ��Ա����һλ���� 
			 } 
		 }
		 if(GetBit(state,len-1) != GetBit(aimState,len-1)) //���ĩλ��һ����˵�������У�count���� 
			count = 0; 	
		 if (count != 0)
		 {
		 	if(count < mixCount)
		 		mixCount = count;
		 }
		
	 } 
	
	 if(mixCount != 999)
	 	cout << mixCount <<endl;
	else 
		cout << "impossible"<<endl;
	 return 0;
}
