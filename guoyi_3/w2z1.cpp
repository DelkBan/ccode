//����ʦ���ڶ��ܲ���
 #include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <cstdlib>
using namespace std;

class Student {
private:
	char name[20];
	int age,num;
	float avr[4],average;
	char ch;

public:
	void input()
	{
		cin.get(name, 20, ',');
		cin>>ch>>age>>ch>>num>>ch>>avr[0]>>ch>>avr[1]>>ch>>avr[2]>>ch>>avr[3];
	}
	float calculate()
	{
		int i;
		float sum;
		
		for(i = 0;i<4;i++)
		{
			sum += avr[i];
		}
		average = sum / 4;
	}
	
	bool t()
	{
		int a = average;
		if(a == average) //����������ƽ����������������true���������  
			return true;
		else 
			return false;
	}
	void output()
	{
		cout<<name<<ch<<age<<ch<<num<<ch;
		if(t()) //�������
			printf("%d",int(average));
		else
			printf("%.1f",average); //����һλС�� 
	}
};

int main() {
	Student student;        // ������Ķ���
	student.input();        // ��������
	student.calculate();    // ����ƽ���ɼ�
	student.output();       // �������
}
