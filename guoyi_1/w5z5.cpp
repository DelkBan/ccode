// 第五题 计算鞍点
 
 #include<iostream>
 using namespace std;
 
 int main()
 {
 	freopen("C:\\Users\\DelkBan\\Downloads\\in (28).txt","r",stdin);
 	int a[5][5];
 	for(int i=0;i<5;i++)
 	{
 		for (int j=0;j<5;j++)
 			cin>>a[i][j];
	 }
	 int min,max,mini,maxj;
	 bool isOk=false;
	 for(int i=0;i<5;i++)
	 {
	 	max=a[i][0];
	 	maxj=0;
	 	for(int j=0;j<5;j++)
	 	{
	 		if(a[i][j]>max) //寻找当前行最大值
			 {
			 		max=a[i][j]; 
			 		maxj=j; //列号 
			 		
			 }
		 }
		 //验证当前行最大值是否是鞍点 
		 min=max;//置行最大值为初值 
		 mini=i;  //行号 
		 for(int k=0;k<5;k++)
		 {
		 	if(a[k][maxj]<min) //如果出现比它小的，说明这个不行 
		 		break;
		 	if(k==4) isOk=true; //遍历结束还没有出现小的，找到。 
		 }
		 if(isOk)
		 	break; 
		 
	 }
	 if(isOk)
	 cout << mini+1 <<" "<< maxj+1<<" "<<min<<endl;
	 else cout<<"not found";
	 
  } 
