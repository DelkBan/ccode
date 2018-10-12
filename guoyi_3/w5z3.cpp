//魔兽世界之二：装备


#include <iostream>
#include <stdio.h>
#include<cstring>
using namespace std;
#define WARRIOR_NUM 5
/*
char * CWarrior::names[WARRIOR_NUM] = { "dragon","ninja","iceman","lion","wolf" };
红方司令部按照 iceman、lion、wolf、ninja、dragon 的顺序制造武士。
蓝方司令部按照 lion、dragon、ninja、iceman、wolf 的顺序制造武士。
*/
class CHeadquarter;
class CWarrior
{
	private:
		CHeadquarter * pHeadquarter;
		int kindNo; //武士的种类编号 0 dragon 1 ninja 2 iceman 3 lion 4 wolf
		int nNo;
	public:
		static char * names[WARRIOR_NUM];
		static int InitialLifeValue [WARRIOR_NUM];
		CWarrior( CHeadquarter * p,int nNo_,int kindNo_ );
		void PrintResult(int nTime);
};
class CHeadquarter
{
	private:
		int totalLifeValue;
		bool bStopped;
		int totalWarriorNum;
		int color;
		int curMakingSeqIdx; //当前要制造的武士是制造序列中的第几个
		int warriorNum[WARRIOR_NUM]; //存放每种武士的数量
		CWarrior * pWarriors[1000];
	public:
		friend class CWarrior;
		static int makingSeq[2][WARRIOR_NUM]; //武士的制作顺序序列
		void Init(int color_, int lv);
		~CHeadquarter () ;
		int Produce(int nTime);
		void GetColor( char * szColor);
};
CWarrior::CWarrior( CHeadquarter * p,int nNo_,int
kindNo_ ):nNo(nNo_),kindNo(kindNo_),pHeadquarter(p) { }
void CWarrior::PrintResult(int nTime)
{
	char szColor[20];
	pHeadquarter->GetColor(szColor);
	printf("%03d %s %s %d born with strength %d,%d %s in %s headquarter\n",
		nTime, szColor, names[kindNo], nNo, InitialLifeValue[kindNo],
		pHeadquarter->warriorNum[kindNo],names[kindNo],szColor);
}
//司令部初始化函数，color表示颜色，红0蓝1，lv表示总生命值。 
void CHeadquarter::Init(int color_, int lv)
{
	color = color_;
	totalLifeValue = lv;
	totalWarriorNum = 0;
	bStopped = false;
	curMakingSeqIdx = 0;
	for( int i = 0;i < WARRIOR_NUM;i ++ )
		warriorNum[i] = 0;
}
CHeadquarter::~CHeadquarter () {
	for( int i = 0;i < totalWarriorNum;i ++ )
		delete pWarriors[i];
}
int CHeadquarter::Produce(int nTime)
{
	if( bStopped )
		return 0;
	int nSearchingTimes = 0;
	while( CWarrior::InitialLifeValue[makingSeq[color][curMakingSeqIdx]] >
	totalLifeValue && nSearchingTimes < WARRIOR_NUM ) //生命值不够生产并且尝试次数少于五次时循环，目的是找到下一个能生产的对象 
	{
		curMakingSeqIdx = ( curMakingSeqIdx + 1 ) % WARRIOR_NUM ; 
		nSearchingTimes ++;
	}
	int kindNo = makingSeq[color][curMakingSeqIdx];
	if( CWarrior::InitialLifeValue[kindNo] > totalLifeValue ) { //当前制造兵种所需声明大于总生命，无法制造 
		bStopped = true;
		if( color == 0)
			printf("%03d red headquarter stops making warriors\n",nTime);
		else
			printf("%03d blue headquarter stops making warriors\n",nTime);
		return 0; //不能制造要及时跳出 
	}
	totalLifeValue -= CWarrior::InitialLifeValue[kindNo]; //扣除生命值 
	curMakingSeqIdx = ( curMakingSeqIdx + 1 ) % WARRIOR_NUM ;//制造一个当前序列加一，语句可以保证不溢出 
	pWarriors[totalWarriorNum] = new CWarrior( this,totalWarriorNum+1,kindNo);//新建实例化一个战士对象 
	warriorNum[kindNo]++; //这种类型的武士数量增加 
	pWarriors[totalWarriorNum]->PrintResult(nTime);
	totalWarriorNum ++;
	return 1;
}
void CHeadquarter::GetColor( char * szColor)
{
	if( color == 0)
		strcpy(szColor,"red");
	else
		strcpy(szColor,"blue");
}
char * CWarrior::names[WARRIOR_NUM] = { "dragon","ninja","iceman","lion","wolf" };
int CWarrior::InitialLifeValue [WARRIOR_NUM];
int CHeadquarter::makingSeq[2][WARRIOR_NUM] = { { 2,3,4,1,0 },{3,0,1,2,4} }; //两个司令部武士的制作顺序序列
int main()
{
	int t;
	int m;
	CHeadquarter RedHead,BlueHead;
	scanf("%d",&t);
	int nCaseNo = 1;
	while ( t -- ) {
		printf("Case:%d\n",nCaseNo++);
		scanf("%d",&m);
		for( int i = 0;i < WARRIOR_NUM;i ++ )
			scanf("%d", & CWarrior::InitialLifeValue[i]);
		RedHead.Init(0,m);
		BlueHead.Init(1,m);
		int nTime = 0;
		while( true) {
			int tmp1 = RedHead.Produce(nTime);
			int tmp2 = BlueHead.Produce(nTime);
			if( tmp1 == 0 && tmp2 == 0)
				break;
			nTime ++;
		}
	}
	return 0;
} 
