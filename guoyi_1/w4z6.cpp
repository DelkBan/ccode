// Êı×ÖÍ³¼Æ

#include<iostream>

using namespace std;

int main()
{
	int start,end;
	cin>>start>>end;
	int temp,count=0;
	for(int i = start;i<=end;i++)
	{
		int j = i;
		while(j!=0)
		{
			temp = j%10;
			j /= 10;
			if(temp == 2)
				count++;
		}
	}
	cout << count;
	return 0;
}
