// ��Ӷ��

#include<iostream>

using namespace std;

int maxm,m=0; //��������͵�ǰ���� 
int n; //ս���� 
int x; //����Ԫ��

int main()
{
	cin>>maxm>>n>>x;
	while(maxm>=n )  //ֻ��������ս�����ߣ�ս�����Ż�������
	{
		if(m!=maxm) //��ǰ�������㣬��Ҫ��������
		{
			while(x>0) //����δ�þ�ʱ����
			{
				m += n;
				if(m>maxm)
					m = maxm; //������� 
				x--;
				if(m == maxm) //�������㣬���貹��
					break; 
			 }
			
		 }
		 if(m == maxm)//�������㣬����ս��
		 //���ﲻ��ֻ��else ��Ϊͨ������Ĳ����������������������˵� 
		 {
		 	int t = m/n;
		 	n += t; //ս��������
			m = 0; 
		  }
		   if (x==0) //û���������޷�ս�����˳�ս��Ҫ����жϡ� 
			 	break;  
	 }
	 cout << n<<endl; 
 } 
 
