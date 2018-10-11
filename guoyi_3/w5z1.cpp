//全面的MyString

 #include <cstdlib>
#include <iostream>
using namespace std;
int strlen(const char * s) 
{	int i = 0;
	for(; s[i]; ++i);
	return i;
}
void strcpy(char * d,const char * s)
{
	int i = 0;
	for( i = 0; s[i]; ++i)
		d[i] = s[i];
	d[i] = 0;
		
}
int strcmp(const char * s1,const char * s2)
{
	for(int i = 0; s1[i] && s2[i] ; ++i) {
		if( s1[i] < s2[i] )
			return -1;
		else if( s1[i] > s2[i])
			return 1;
	}
	return 0;
}
void strcat(char * d,const char * s)
{
	int len = strlen(d);
	strcpy(d+len,s);
}
class MyString
{
// 在此处补充你的代码
private:
	char *pstr; //用指针作为控制字符串的有力工具 
public:
	MyString() //无参构造函数，产生空字符串 
	{
		pstr = new char[1]; //指向新开出的空间 
		*pstr = '\0';
	}
	MyString(const char *str)  //字符串构造函数，字符串写入以pstr为首的地址中。 
	{
		int len =  strlen(str);
		pstr = new char[len + 1]; //比长度多出一位，用来存放'\0'
		strcpy(pstr,str); 
	}
	MyString(const MyString &rhs) //复制构造函数 
	{
		int len = strlen(rhs.pstr);
		pstr = new char[len + 1];
		strcpy(pstr,rhs.pstr);
	}
	MyString & operator=(const MyString & rhs) //重载赋值运算符，在右值为MyString类时 
	{
		if(this  == & rhs) //this指向本对象的开头，如果两个实体一样，则不用变化
			return *this;
		delete []pstr; //尚不明白为什么这里加入删除
		int len = strlen(rhs.pstr);
		pstr = new char[len + 1];
		strcpy(pstr,rhs.pstr);
		return *this; 
	}
	//没有写 参数为char*的赋值运算和加法重载，实际上是用字符串构造了一个临时对象，然后调用运算符重载 
	MyString & operator +=(const MyString &rhs)
	{
		MyString temp(*this);
		return *this = temp +rhs;
	}
	friend MyString operator+(const MyString &x,const MyString &y)  
	{ //运算符重载为友元函数，若重载为普通函数，将不能访问类的私有成员 
		char *temp = new char[strlen(x.pstr)+strlen(y.pstr)];
		strcpy(temp,x.pstr);
		strcat(temp,y.pstr);
		MyString re(temp); //调用参数为*char的构造函数构造实体
		delete []temp;
		return re; 
	}
	friend ostream & operator <<(ostream & os,const MyString & rhs)
	{
		os << rhs.pstr;
		return os;
	 } 
	friend bool operator<(const MyString &x,MyString &y)
	{
		return strcmp(x.pstr,y.pstr)<0;
	 } 
	friend bool operator==(const MyString &x,MyString &y)
	{
		return strcmp(x.pstr,y.pstr)==0;
	 }
	friend bool operator>(const MyString &x,MyString &y)
	{
		return strcmp(x.pstr,y.pstr)>0;
	 }
	char & operator[](int n)  //重载char中的[] 
	{
		return *(pstr+n);
	}
	MyString operator()(int b,int len)
	{
		char *temp = new char[strlen(pstr)+1];
		strcpy(temp,pstr+b);
		*(temp+len)='\0';
		MyString re(temp);
		delete []temp;
		return re;
	}
	~MyString(){delete[]pstr;
	}
	//补充代码到此结束 
	
};


int CompareString( const void * e1, const void * e2)
{
	MyString * s1 = (MyString * ) e1;
	MyString * s2 = (MyString * ) e2;
	if( * s1 < *s2 )
	return -1;
	else if( *s1 == *s2)
	return 0;
	else if( *s1 > *s2 )
	return 1;
}
int main()
{
	MyString s1("abcd-"),s2,s3("efgh-"),s4(s1);
	MyString SArray[4] = {"big","me","about","take"};
	cout << "1. " << s1 << s2 << s3<< s4<< endl;
	s4 = s3;
	s3 = s1 + s3;
	cout << "2. " << s1 << endl;
	cout << "3. " << s2 << endl;
	cout << "4. " << s3 << endl;
	cout << "5. " << s4 << endl;
	cout << "6. " << s1[2] << endl;
	s2 = s1;
	s1 = "ijkl-";
	s1[2] = 'A' ;
	cout << "7. " << s2 << endl;
	cout << "8. " << s1 << endl;
	s1 += "mnop";
	cout << "9. " << s1 << endl;
	s4 = "qrst-" + s2;
	cout << "10. " << s4 << endl;
	s1 = s2 + s4 + " uvw " + "xyz";
	cout << "11. " << s1 << endl;
	qsort(SArray,4,sizeof(MyString),CompareString);
	for( int i = 0;i < 4;i ++ )
	cout << SArray[i] << endl;
	//s1的从下标0开始长度为4的子串
	cout << s1(0,4) << endl;
	//s1的从下标5开始长度为10的子串
	cout << s1(5,10) << endl;
	return 0;
}
