//第六题 图像模糊处理

 #include<iostream>
 using namespace std;
 
 
 int main()
 {
 	freopen("C:\\Users\\DelkBan\\Downloads\\in (28).txt","r",stdin);
 	int m,n;
 	cin >> n >>m;
 	int a[n][m];

	for(int i=0;i<n;i++)
 	{
 		for(int j=0;j<m;j++)
 			cin >> a[i][j];
	 }
	 //开始处理 
	 int b[n][m];//创建临时数组 
	 for(int i=1;i<n-1;i++)
	 {
	 	
	 	for(int j=1;j<m-1;j++)
	 	{
	 		int temp;
	 		temp=a[i-1][j]+a[i+1][j]+a[i][j+1]+a[i][j-1]+a[i][j];
	 		b[i][j]=int(temp+2.5)/5; //+2是为了凑成四舍五入 
		 }
		
	 }
	  //赋值
	  for(int i=1;i<n-1;i++)
	 {
		 for(int j=1;j<m-1;j++)
		 {
		 	a[i][j]=b[i][j];
		  }
	}
	 //输出
	 for(int i=0;i<n;i++)
	 {
	 	for(int j=0;j<m;j++)
	 		cout << a[i][j] <<" ";
	 	cout << endl;
	  } 
 }
