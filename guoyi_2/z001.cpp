//����ʦ�������㷨�Σ�������һ����ҵ001������������
/*
˼·���������еİ������������ÿһ���ܹ�ʵ��Ŀ��İ�����������ͳ�ƣ�������Сֵ 
*/

 
#include<iostream>
#include<cstring>
using namespace std;

int iniState;//���ԭʼ״̬
int aimState;//���Ŀ��״̬

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
	long int num = pow(2,len);//��������
	int count=0,mixCount=999; //�����������С������� 
	 
	for (int i = 0;i<len;i++) //��Ϊλ��ʾ 
	{
		SetBit(iniState,i,ini[i]);
		SetBit(aimState,i,aim[i]);
		
	}
	 for(int n = 0;n<num;n++)  //ö�����п��ܵİ��� 
	 {
	 	int state = iniState;
	 	count = 0;//�������� 
	 	for(int j = 0;j<len;j++) //�����j�� 
	 	{
	 		
	 		if(GetBit(n,j)){ //ö�ٵĵ�ǰλ����1�Ų��� 
	 			count ++;
	 			FlipBit(state,j); //��ת��ǰλ
				if(j>0) //ֻҪ���ǵ�һ�������Ͱ���ߵķ�ת   ��Ϊ�洢˳���ʵ��˳���Ƿ��ģ�����һ��Ҫע������Ĵ�С��ϵ 
					 FlipBit(state,j-1);
				if(j < len-1)
					FlipBit(state,j+1);
			 }
		 }
		 
		 //for(int m = 0; m < num; m++) //������ǰ��ö���Ƿ��ܴﵽĿ�� 
		// {
		 	if(aimState == state){
		 	if(count < mixCount)  //�õ����ٴ��� 
		 		mixCount = count;
		 	}
		// }
	 }
	 if(mixCount != 999)
	 	cout << mixCount <<endl;
	else 
		cout << "impossible"<<endl;
	 return 0;
	
}
