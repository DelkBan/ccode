// �� ��������ҵ 2 ��������� 

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
// �ڴ˴�������Ĵ���
	Big(int n):v(n),b(n){}; //����Base��ʱ��һ��Ҫ���������ɵĶ���b��������Base 
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


//�������õ��������Ķ������� 
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
