// 求特殊自然数

#include<iostream>

using namespace std;

int A,B,C;//代表三个位数

void seperate(int n,int &a,int& b,int& c)
{
	a = n/100;
	c = n%10;
	b = n/10 %10;
  }  

bool change(int &ten,int &seven,int &nine)
{
	seperate(seven,A,B,C);
	if(A*49+B*7+C ==C*81+B*9+A)  //找到了
		 {
		 	ten = A*49+B*7+C;
		 	nine = C*100+B*10+A;
		 	return true;
		 }
	else return false;
}



int main()
{
	int ten,sev=100,nin;
	while(sev<1000)
	{
		if(change(ten,sev,nin))
		{
			cout<<ten<<endl;
			cout<<sev<<endl;
			cout<<nin<<endl<<endl;
			//break;
		}
		sev++;
		ten = 0;
		nin = 0;
	}
	
	
	return 0;
}
