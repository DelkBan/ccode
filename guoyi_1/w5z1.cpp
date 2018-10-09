//第五周作业
 
 #include<iostream>
 using namespace std;
 
 int main()
 {
 	int n;
 	cin >> n;
 	int a[n];
 	for(int i = 0;i<n;i++)
 		cin >> a[i];
 	int m;
 	int count = 0;
 	cin >> m;
 	for(int i = 0; i<n;i++)
 	{
 		if ( m== a[i])
 			count ++;
	 }
	 cout << m << endl;
	 
 		
 }
