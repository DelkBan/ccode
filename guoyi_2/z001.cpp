//郭老师程序与算法课（二）第一周作业001：特殊密码锁
/*
思路：遍历所有的按键情况，对于每一种能够实现目标的按键次数进行统计，保留最小值 
*/

 
#include<iostream>
#include<cstring>
using namespace std;

int iniState;//存放原始状态
int aimState;//存放目标状态

int GetBit(int c,int i)//取c的第i位
{
	return(c >> i) & 1;
 } 
 
 //设置c的第i位为v 
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

//翻转c的第i位
void FlipBit(int &c, int i){
	c ^= (1 << i);
} 

int main()
{
	string ini,aim;
	getline(cin,ini);
	getline(cin,aim);
	
	int len = ini.size(); //len为输入的数据的长度
	long int num = pow(2,len);//迭代长度
	int count=0,mixCount=999; //计算次数、最小计算次数 
	 
	for (int i = 0;i<len;i++) //改为位表示 
	{
		SetBit(iniState,i,ini[i]);
		SetBit(aimState,i,aim[i]);
		
	}
	 for(int n = 0;n<num;n++)  //枚举所有可能的按法 
	 {
	 	int state = iniState;
	 	count = 0;//重新置零 
	 	for(int j = 0;j<len;j++) //处理第j个 
	 	{
	 		
	 		if(GetBit(n,j)){ //枚举的当前位置是1才操作 
	 			count ++;
	 			FlipBit(state,j); //翻转当前位
				if(j>0) //只要不是第一个数，就把左边的翻转   因为存储顺序和实际顺序是反的，所以一定要注意这里的大小关系 
					 FlipBit(state,j-1);
				if(j < len-1)
					FlipBit(state,j+1);
			 }
		 }
		 
		 //for(int m = 0; m < num; m++) //分析当前的枚举是否能达到目标 
		// {
		 	if(aimState == state){
		 	if(count < mixCount)  //得到最少次数 
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
