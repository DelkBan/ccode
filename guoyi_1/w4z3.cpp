// 数字反转

 #include<iostream>
 #include<cstring>
 
 using namespace std;
 
 string str;
 
 
 int main()
 {
 	cin >> str;
	 	int n = str.length();
	 bool notZero = false;
	 bool isNegtive = false;
	 if(str[0]=='-')
	 	isNegtive = true;
	string aa ;
	if(isNegtive)
	{
		for(int i = 0;i<n-1;i++)
			aa[i]=str[i+1];
		n = n-1;//缩短一位
		cout << '-'; 
	}
	else
		aa = str;

	 for(int i = n-1;i>=0;i--)
	 {
	 	if(aa[i] != '0')
	 		notZero = true;
	 	if(notZero)
	 		cout << aa[i];
		 }
	return 0;	
 }
