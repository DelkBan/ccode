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

void change(int n,int &seven,int &nine)
{
	seperate(n,A,B,C);
	seven = C + B*7 + A*49;
	nine = C + B*9 + A*81;
}

bool isEqual(int sev,int nin)
{
	int sev1,sev2,sev3,nin1,nin2,nin3;
	seperate(sev,sev1,sev2,sev3);
	seperate(nin,nin1,nin2,nin3);
	if(sev1==nin3 && sev2 == nin2 && sev3 == nin1)
		return true;
	else
		return false;
}

int main()
{
	int ten=100,sev,nin;
	while(1)
	{
		change(ten,sev,nin);
		if(isEqual(sev,nin))
		{
			cout<<ten<<endl;
			cout<<sev<<endl;
			cout<<nin<<endl;
			break;
		}
		ten++;
		sev = 0;
		nin = 0;
	}
	
	
	return 0;
}
