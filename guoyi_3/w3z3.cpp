// ����������ҵ   5 ħ������֮һ����ս

 #include<iostream>
 #include<string>
 #include<iomanip>
 
 using namespace std;
 
 class headquarters
 {
 	private:
 		static string oriNames[5]; //ԭʼսʿ����
		 int allLife; //��ǰ��Ӫȫ������ֵ
		 int count; //������սʿ���� 
		 int warCounts[5]; //ÿ��սʿ������
		 string headquartersName; //������Ӫ����
		 string warNames[5]; //ÿ��սʿ����
		 int warLife[5]; //ÿ��սʿ����ֵ
		 int currentPosition; //��ǰ������սʿ�����������е�λ��
		 int minWarLife; // սʿ�е���С����ֵ 
		 void product(int time, int position); //��time����position������
	public:
		bool warStop;//����ֹͣ����
		static int time; //����սʿ�Ĵ��� 
		headquarters(const int theAllLife, string theHeadquartersName, const int theWarLife[],
			const int order[]);
		void dispatchWar(); //�������� 
 		
 };
 
 string headquarters::oriNames[5] = {"dragon","ninja","iceman","lion","wolf"};
 int headquarters::time = 0; 
 
 /*
 ���캯��
 */
 headquarters::headquarters(const int theAllLife, string theHeadquartersName, const int theWarLife[],
		const int order[]):warStop(false),currentPosition(0),count(0),allLife(theAllLife),
		headquartersName(theHeadquartersName)
	{
		for(int i = 0;i<5;i++)
		{
			warCounts[i] = 0;
			warNames[i] = oriNames[order[i]]; //�Ӹ�����˳���ԭʼ���ֵõ���ǰ����
			warLife[i] = theWarLife[order[i]]; //�Ӹ�����˳���ԭʼ���ֵõ���ǰ������ֵ 
			}
		minWarLife = warLife[0];
		for(int i = 1;i<5;i++) //��������е���С����ֵ 
		{
			if(warLife[i] < minWarLife)
			{
				minWarLife = warLife[i];
			}
			}	
	}	

/*
����������սʿ
������ time�����������غ���
		position��������������λ��
*/
void headquarters::product(int time,int position)
{
	count++;
	warCounts[position]++;//��ǰ����������һ
	cout << setfill('0') << setw(3) << time << " " << headquartersName << " " << warNames[position]
    << " " << count << " born with strength " << warLife[position] << "," << warCounts[position]
    << " " << warNames[position] << " in " << headquartersName << " headquarter" << endl;
    allLife -= warLife[position];
}

/*
����������

		*/
 void headquarters::dispatchWar()
 {
 	//�����������ڱ���������Сֵ���޷����� 
 	if(allLife < minWarLife)
 	{
 		cout << setfill('0') << setw(3) << time << ' ' << headquartersName << " headquarter stops making warriors"<<endl;
 		warStop = true; //��ֹͣ������־ 
	 }
	 else{
	 	//����һ�����Գ����� �ӵ�ǰcurrentposition��ʼ����,��0��ʼ���������������ж���һ���� 
	 	while(1)
	 	{
	 		if(allLife >= warLife[currentPosition])
	 		{
	 			product(time,currentPosition); //��һ����
				 currentPosition == 4 ? currentPosition = 0 : currentPosition ++ ;
				 break; //������ɣ�����ѭ�� 
			 }
			 else
			 {
			 	currentPosition == 4 ? currentPosition = 0 : currentPosition ++ ;
			 }
		 }
	 }
 }
 
 int main()
 {
 	const int redOrder[5] = {2,3,4,1,0};
 	const int blueOrder[5] = {3,0,1,2,4};
 	int n; //����
	 cin >> n;
	 for(int i = 0;i<n;i++)
	 {
	 	int oriValue[5],headquartersValue; //սʿ��ʼ����ֵ���ܲ�����ֵ
		 cin >> headquartersValue;
		 for(int j = 0;j<5;j++)
		 //��ȡսʿ��ʼ����ֵ 
		 {
		 	cin >> oriValue[j];
		  } 
		  cout << "Case:" << i+1 << endl;
		  
		  //��ʼ��˫���ܲ�
		  headquarters red = headquarters(headquartersValue,"red",oriValue,redOrder);
		  headquarters blue = headquarters(headquartersValue,"blue",oriValue,blueOrder); 
		  headquarters::time = 0; //���ǵ���������������һ��Ҫ����
		   while(!red.warStop || !blue.warStop) //��������ʱ���� 
		   {
		   		if(!red.warStop) //�ȳ���ɫ
				   red.dispatchWar();
				if(!blue.warStop)
					blue.dispatchWar() ;
				headquarters::time++ ; //�����ｫʱ�����ӣ���Ϊ������Ӫ����ʱ�� 
		   }
	  }
	  return 0; 
	  
 }
