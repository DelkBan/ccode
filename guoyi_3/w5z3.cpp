//ħ������֮����װ��


#include <iostream>
#include <stdio.h>
#include<cstring>
using namespace std;
#define WARRIOR_NUM 5
/*
char * CWarrior::names[WARRIOR_NUM] = { "dragon","ninja","iceman","lion","wolf" };
�췽˾����� iceman��lion��wolf��ninja��dragon ��˳��������ʿ��
����˾����� lion��dragon��ninja��iceman��wolf ��˳��������ʿ��
*/
class CHeadquarter;
class CWarrior
{
	private:
		CHeadquarter * pHeadquarter;
		int kindNo; //��ʿ�������� 0 dragon 1 ninja 2 iceman 3 lion 4 wolf
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
		int curMakingSeqIdx; //��ǰҪ�������ʿ�����������еĵڼ���
		int warriorNum[WARRIOR_NUM]; //���ÿ����ʿ������
		CWarrior * pWarriors[1000];
	public:
		friend class CWarrior;
		static int makingSeq[2][WARRIOR_NUM]; //��ʿ������˳������
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
//˾���ʼ��������color��ʾ��ɫ����0��1��lv��ʾ������ֵ�� 
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
	totalLifeValue && nSearchingTimes < WARRIOR_NUM ) //����ֵ�����������ҳ��Դ����������ʱѭ����Ŀ�����ҵ���һ���������Ķ��� 
	{
		curMakingSeqIdx = ( curMakingSeqIdx + 1 ) % WARRIOR_NUM ; 
		nSearchingTimes ++;
	}
	int kindNo = makingSeq[color][curMakingSeqIdx];
	if( CWarrior::InitialLifeValue[kindNo] > totalLifeValue ) { //��ǰ����������������������������޷����� 
		bStopped = true;
		if( color == 0)
			printf("%03d red headquarter stops making warriors\n",nTime);
		else
			printf("%03d blue headquarter stops making warriors\n",nTime);
		return 0; //��������Ҫ��ʱ���� 
	}
	totalLifeValue -= CWarrior::InitialLifeValue[kindNo]; //�۳�����ֵ 
	curMakingSeqIdx = ( curMakingSeqIdx + 1 ) % WARRIOR_NUM ;//����һ����ǰ���м�һ�������Ա�֤����� 
	pWarriors[totalWarriorNum] = new CWarrior( this,totalWarriorNum+1,kindNo);//�½�ʵ����һ��սʿ���� 
	warriorNum[kindNo]++; //�������͵���ʿ�������� 
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
int CHeadquarter::makingSeq[2][WARRIOR_NUM] = { { 2,3,4,1,0 },{3,0,1,2,4} }; //����˾���ʿ������˳������
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
