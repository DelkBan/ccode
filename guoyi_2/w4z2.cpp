//��
//����Ĺؼ���Ҫ��rmax���ó�����ɵ��������������С���� 

#include<iostream>
#include<cstdio>
using namespace std;

#define PI 3.141592653

int main()
{
	//freopen("C:\\Users\\DelkBan\\Downloads\\in (28).txt","r",stdin);
	int n,f; 
	cin >> n >>f;
	double s[n];//��¼�����ÿ���ɵİ뾶 
	double rmax = PI*0.0; //��ʼ������Ѱ�ҵ������ 
	for(int i=0;i<n;i++)
	{
		cin >> s[i];
		s[i] = PI * s[i]*s[i]; //ת������� 
		rmax = rmax>s[i]? rmax:s[i]; //rmax��Ϊ�����ɵ���� 
	}
	double rmin=1e-5; //���������
	double root=rmin+(rmax-rmin)/2;//�趨��ʼ�м�ֵ 
	int time=0;
	while(rmax-rmin > 1e-6) //�����㾫ȷ�Ⱦ�ѭ�� 
	{
		int sum=0;
//		time++;//���� 
		root = rmin+(rmax-rmin)/2;
		for(int i=0;i<n;i++) //���㵱ǰ��С���ּܷ��� 
		{
			sum += (s[i]/root);
		}
		if(sum<f+1) //������������Ҫ��С����max��Ϊroot 
		{
			rmax = root;
		}
		else if(sum>=f-1) rmin = root;
		//������ж��Ƿ����㾫�� 
		
	 }
	 printf("%.3lf",root);
//	 cout << time;
	
}
