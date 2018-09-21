//三 第三周作业1 返回什么才好呢 

#include <iostream>
using namespace std;
class A {
public:
	int val;

	A(int x=123){
		val = x;
	}
	A &GetObj(){
		return *this;  
	}
// 在此处补充你的代码

};
int main()
{
	int m,n;
	A a;
	cout << a.val << endl;
	while(cin >> m >> n) {
		a.GetObj() = m;  //返回类型应当是引用，否则无法当左值。 
		cout << a.val << endl;
		a.GetObj() = A(n);
		cout << a.val<< endl;
	}
	return 0;
} 
