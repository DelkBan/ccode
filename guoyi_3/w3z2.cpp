// 三 第三周作业 2 封闭类问题 

#include <iostream>
#include <string>
using namespace std;
class Base {
public:
	int k;
	Base(int n):k(n) { }
};
class Big
{
public:
	int v;
	Base b;
// 在此处补充你的代码
	Big(int n):v(n),b(n){}; //声明Base的时候一定要声明它生成的对象b，而不是Base 
};
int main()
{
	int n;
	while(cin >>n) {
		Big a1(n);
		Big a2 = a1;
		cout << a1.v << "," << a1.b.k << endl;
		cout << a2.v << "," << a2.b.k << endl;
	}
} 


//下面是用到虚析构的动物问题 
class Animal{
	public:
		static int number;
		Animal(){
			number++;
		}
		virtual ~Animal(){
			number--;
		}
};
class Dog:public Animal{
	public:
		static int number;
		Dog(){
			number++;
		}
		~Dog(){
			number--;
		}
};
class Cat:public Animal{
	public:
		static int number;
		Cat(){
			number++;
		}
		~Cat(){
			number--;
		}
};
int Animal::number = 0,Dog::number = 0,Cat::number=0;
