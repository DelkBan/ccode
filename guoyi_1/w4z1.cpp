//½Ç¹È²ÂÏë

 #include<iostream>
 
 using namespace std;
 
 bool isEven(int n)
 {
 	if(n % 2) return true;
 	else return false;
 }
 
 int main()
 {
 	long long int n;
 	cin >> n;
 	while(n != 1)
 	{
 		cout << n ;
 		if(isEven(n))
 		{
 			n = 3*n + 1;
 			cout << "*3+1=" << n <<endl;
		 }
		 else if(!isEven(n))
		 {
		 	n /= 2;
		 	cout << "/2=" << n <<endl;
		 }
	 }
	 cout << "End"<<endl;
	 return 0;
 }
