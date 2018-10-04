//第四周第三题

#include <iostream> 
using namespace std;
class Point { 
	private: 
		int x; 
		int y; 
	public: 
		Point() { };
// 在此处补充你的代码
	friend istream & operator >> (istream & i,Point &p)
	{
		i >> p.x >> p.y;
		return i;
	}
	friend ostream & operator << (ostream & o,Point &p)
	{
		o << p.x << "," << p.y ;
		return o;
	}

}; 
int main() 
{ 
	freopen("C:\\Users\\B_Delk\\Desktop\\临时通过码\\in (1).txt","r",stdin);
 	Point p;
 	while(cin >> p) {
 		cout << p << endl;
	 }
	return 0;
} 
