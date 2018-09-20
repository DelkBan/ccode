//郭老师三第二周测试
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
		if(a == average) //如果求出来的平均数是整数，返回true，输出整数  
			return true;
		else 
			return false;
	}
	void output()
	{
		cout<<name<<ch<<age<<ch<<num<<ch;
		if(t()) //输出整数
			printf("%d",int(average));
		else
			printf("%.1f",average); //保留一位小数 
	}
};

int main() {
	Student student;        // 定义类的对象
	student.input();        // 输入数据
	student.calculate();    // 计算平均成绩
	student.output();       // 输出数据
}
