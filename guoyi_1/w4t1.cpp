//ì³²¨ÄÇÆõÊıÁĞ

#include<iostream>
using namespace std;
int main()
{
	int k;
	cin >> k;
	int n1=1,n2=1;
	if(k>2)
	{
		for(int i = 2;i<k;i++)
		{
			int temp;
			n1 += n2;
			temp = n2;
			n2 = n1;
			n1 = temp;
		
		}
		
	}
	cout << n2;	
 } 
