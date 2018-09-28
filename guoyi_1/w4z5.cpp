// 雇佣兵

#include<iostream>

using namespace std;

int maxm,m=0; //最大体力和当前体力 
int n; //战斗力 
int x; //能量元素

int main()
{
	cin>>maxm>>n>>x;
	while(maxm>=n )  //只有体力比战斗力高，战斗力才会提升。
	{
		if(m!=maxm) //当前体力不足，需要补充体力
		{
			while(x>0) //能量未用尽时继续
			{
				m += n;
				if(m>maxm)
					m = maxm; //溢出修正 
				x--;
				if(m == maxm) //能量充足，无需补充
					break; 
			 }
			
		 }
		 if(m == maxm)//体力充足，可以战斗
		 //这里不能只用else 因为通过上面的操作，出来就是满足条件了的 
		 {
		 	int t = m/n;
		 	n += t; //战斗力增加
			m = 0; 
		  }
		   if (x==0) //没有能量，无法战斗。退出战斗要最后判断。 
			 	break;  
	 }
	 cout << n<<endl; 
 } 
 
