// ������ ���㰰��
 
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
	 		if(a[i][j]>max) //Ѱ�ҵ�ǰ�����ֵ
			 {
			 		max=a[i][j]; 
			 		maxj=j; //�к� 
			 		
			 }
		 }
		 //��֤��ǰ�����ֵ�Ƿ��ǰ��� 
		 min=max;//�������ֵΪ��ֵ 
		 mini=i;  //�к� 
		 for(int k=0;k<5;k++)
		 {
		 	if(a[k][maxj]<min) //������ֱ���С�ģ�˵��������� 
		 		break;
		 	if(k==4) isOk=true; //����������û�г���С�ģ��ҵ��� 
		 }
		 if(isOk)
		 	break; 
		 
	 }
	 if(isOk)
	 cout << mini+1 <<" "<< maxj+1<<" "<<min<<endl;
	 else cout<<"not found";
	 
  } 
