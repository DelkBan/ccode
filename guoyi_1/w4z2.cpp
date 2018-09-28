// Õý³£ÑªÑ¹

 #include<iostream>
 
 using namespace std;
 
 int main()
 {
 	int n,p1,p2;
 	int time=0,maxTime=0;
 	cin >> n;
 	for(int i = 0;i<n;i++)
 	{
 		cin >> p1 >> p2;
 		if( (p1 >= 90 && p1<=140) && (p2>=60&&p2<=90))
 		{	time ++ ;
 			if(maxTime<time)
 				maxTime = time;}
 		else
 		{
 			time = 0;
		 }
	  }
	  cout << maxTime << endl;
	  return 0; 
  } 
