//郭老师程序与算法课（二）第一周作业001：特殊密码锁
/*
思路：只要第一个的状态确定了，后面的按法就确定了，只需要对比最后一位是否和目标相同即可。
	枚举次数为二，分别是第一个按/不按。 
*/

 
#include<iostream>
#include<cstring>
using namespace std;

int iniState;//存放原始状态
int aimState;//存放目标状态
int mixCount =999; //存放最小计数 

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
	int count=0,mixCount=999; //计算次数、最小计算次数 	 
	for (int i = 0;i<len;i++) //改为位表示 
	{
		SetBit(iniState,i,ini[i]);
		SetBit(aimState,i,aim[i]);
	}
	
	for(int n = 0; n < 2; n++) //枚举开头的两种可能
	{
		int state = iniState;
		int count = 0;

		int flag = n;//初始化标志位，1变0不变
		if(n){
			FlipBit(state,0); //处理第一个数据 
			FlipBit(state,1);//第二个数据也要翻转 
			count ++ ;
		}
		for(int i = 1; i < len; i++)  
		{
			if(GetBit(state,i-1) == GetBit(aimState,i-1))//若上个数据和目标一致，则flag为0
				flag = 0;
			else flag = 1;
			if(flag == 1) //需翻转
			{
				count ++ ;
				FlipBit(state,i); //翻转当前位
				 if(i != len-1)
				 	FlipBit(state,i+1); //未到边界，翻转下一位。
					 //上一位不需要操作，只需对比最后一位即可 
			 } 
		 }
		 if(GetBit(state,len-1) != GetBit(aimState,len-1)) //如果末位不一样，说明不可行，count置零 
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
