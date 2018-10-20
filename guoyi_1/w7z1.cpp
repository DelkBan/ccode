//统计数字字符个数
 #include<iostream>
 #include<cstring>
 using namespace std;
 
 int main()
 {
 	freopen("c:\\Users\\DelkBan\\Desktop\\test.txt","r",stdin);
 	char a[256];
 	gets(a);
 	int count=0;
 	for(int i=0;a[i];i++)
 	{
 		if(a[i]>='0' && a[i]<='9')
 			count++;
	 }
	 cout << count <<endl;
	 return 0;
 }
