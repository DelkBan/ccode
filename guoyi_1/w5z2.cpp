//第五周第二题 摘苹果
 
 #include<iostream>
 using namespace std;
 
 int main()
 {
 	int a[10];
 	for (int i = 0 ; i < 10 ; i++){
 		cin >> a[i];
	 }
	 int arm;
	 cin >> arm;
	 int count = 0;
	 for(int i=0;i<10;i++)
	 {
	 	if(arm+30 >= a[i])
	 		count ++;
	 }
	 cout << count << endl;
  } 
