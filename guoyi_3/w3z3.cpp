// 三第三周作业   5 魔兽世界之一：备战

 #include<iostream>
 #include<string>
 #include<iomanip>
 
 using namespace std;
 
 class headquarters
 {
 	private:
 		string oriNames[5]; //原始战士名字
		 int allLife; //当前阵营全部生命值
		 int count; //生产的战士数量 
		 int warCounts[5]; //每种战士的数量
		 string headquartersName; //当期阵营名称
		 string warNames[5]; //每种战士名字
		 int warLife[5]; //每种战士生命值
		 int currentPosition; //当前产生的战士类型在类型中的位置
		 int minWarLife; // 战士中的最小生命值 
		 void product(int time, int position); //第time次在position处出兵
	public:
		bool warStop;//真则停止出兵
		int time; //产生战士的次数 
		headquarters(const int theAllLife, string theHeadquartersName, const int theWarLife[],
			const int order[]);
		void dispatchWar(); //出兵操作 
 		
 };
 
 string headquarters::oriNames[5] = {"dragon","ninja","iceman","lion","wolf"};
 int headquarters::time = 0; 
 
 /*
 构造函数
 */
 headquarters::headquarters(const int theAllLife, string theHeadquartersName, const int theWarLife[],
		const int order[]):warStop(false),currentPosition(0),count(0),allLife(theAllLife),
		headquartersName(theHeadquartersName)
	{
		for(int i = 0;i<5;i++)
		{
			warCounts[i] = 0;
			warNames[i] = oriNames[order[i]]; //从给定得顺序和原始名字得到当前名字
			warLife[i] = theWarLife[order[i]]; //从给定的顺序和原始名字得到当前各生命值 
			}
		minWarLife = warLife[0];
		for(int i = 1;i<5;i++) //计算五个中的最小生命值 
		{
			if(warLife[i] < minWarLife)
			{
				minWarLife = warLife[i]
			}
			}	
	}	

/*
函数：生产战士
参数： time，给定出兵回合数
		position，给定兵种所在位置
*/
void headquarters::product(int time,int position)
{
	count++;
	warCounts[position]++;//当前兵种数量加一
	cout << setfill('0') << setw(3) << time << " " << headquarterName << " " << warNames[position]
    << " " << count << " born with strength " << warLife[position] << "," << warCounts[position]
    << " " << warNames[position] << " in " << headquarterName << " headquarter" << endl;
    allLife -= warLife[position];
}

/*
函数：出兵

		*/
 void headquarters::dispatchWar()
 {
 	//本部生命少于兵种生命最小值，无法出兵 
 	if(allLife < minWarLife)
 	{
 		cout << setfill('0') << setw(3) << time << ' ' << headquartersName << " stops making warriors"<<endl;
 		warStop = true;
	 }
	 else{
	 	//现在一定可以出兵了 从当前position开始增加 
	 }
 }
