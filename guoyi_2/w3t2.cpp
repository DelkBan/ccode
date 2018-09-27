///ÅÀÂ¥ÌİÎÊÌâ

#include<iostream>

using namespace std;

int stage(int n)
{
	if (n>2)
		return stage(n-1)+stage(n-2);
	if (n == 2)
		return 2;
	if (n == 1)
		return 1;
	if (n <= 0)
		return 0;
 } 
 
 int main()
 {
 	int num;
 	while(cin>>num){
 	cout<<stage(num)<<endl;
	}
	return 0;
 }
