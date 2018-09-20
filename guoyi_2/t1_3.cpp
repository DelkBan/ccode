//����ʦ�ĿΣ��ڶ�������һ�ܣ����⡣
//eg.3 ��Ӳ��
//��д

#include<memory>
#include<string>
#include<cstring>
#include<iostream>
using namespace std;
char oriLights[5]; //���ԭʼ�����״̬����
char lights[5]; //��¼�Ƶı仯������״̬�� 
char result[5]; //�洢���

int GetBit(char c, int i)  //ȡc�ĵ�i������
{
	return (c >> i ) & 1; //c����iλ��ʹc�õ�iλȥ��λ��Ȼ����1�����ȡ����ԭ����iλֵ 
 } 

//�����ַ�c�ĵ�iλΪv 
void SetBit(char &c, int i,int v)  //C++���ԣ���&�����ã���������ı��βΣ���ʵ�ʵ�ʵ��Ҳ���Ÿı䡣 
{
	if(v){
		c |= ( 1 << i);  //v��һ����c�ĵ�iλ��һ��1����iλ 
	}
	else
	{
		c &= ~(1 << i); //v���㣬��c�ĵ�iλ���㣺�ұߵĵ�iλ��0�������c�ĵ�iλ�����㡣 
	}
 } 
 
 //��ת��iλ :: ��һ��򼴿� 
 void FlipBit(char &c,int i)
 {
 	c ^= (1<<i);
 }
 
 //������
 void OutputResult(int t,char result[]) 
 {
 	cout << "PUZZLE #" << t<< endl;
 	for(int i = 0;i < 5;++i){
 		for(int j = 0;j<6;++j){
 			cout<< GetBit(result[i],j);
 			if( j < 5)
 				cout << " ";  //���һ�����ֺ���û�пո�  �����ĺ�����һ���ո� 
		 }
		 cout << endl;
	 }
 }
 
 int main()
 {
 	int T;
 	cin >>T;
 	for(int t = 1; t<=T; ++t){
 		for(int i = 0;i<5;++i)
 			for(int  j = 0; j<6 ; ++j){
 				int s;
 				cin >>s;
 				SetBit(oriLights[i],j,s);
			 }
		for(int  n = 0 ; n<64;++n){ //ö�ٵ�һ�п������ú�Ŀ���״̬��������������64�ֿ��� ������64�ֳ�ֵ���ú���Ľ����жϡ�
		//ע�⣬������n����switchs�ǿ��ذ��µ�����������ǵƵ�״̬�� 
			int switchs  = n;
			memcpy(lights,oriLights,sizeof(oriLights)); //����oriLights��ָ�ڴ����е�oriLights���ȸ��ֽڵ�lights   ���鵽����Ĵ��� 
			for(int i = 0;i < 5; ++i){ //�����i�� 
				result[i] = switchs;
				for(int j =0;j < 6;j++){ //�����i�е�j��
					if(GetBit(switchs,j)){  //�����1����Ҫ���� 
						if(j > 0 )
							FlipBit(lights[i],j-1);
						FlipBit(lights[i],j);
						if(j < 5)
							FlipBit(lights[i],j+1);
					} 
				}
				if(i < 4)   //����i+1�е����� 
					lights[i+1] ^= switchs; //���swithcs������1 light�ͷ�ת  0����ת 
				switchs = lights[i]; //���������swithcs �´�ѭ������result[i] 
			}
			//����Ϊֹ�ܱ�֤ǰ���ж�����ģ�ֻ��Ҫ�жϵ����е��ǲ���ȫ�𼴿�
			if(lights[4] == 0)
			{
				OutputResult(t,result);
				break;
			 } 
		}
	 }
 }
