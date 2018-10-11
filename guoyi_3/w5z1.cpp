//ȫ���MyString

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
// �ڴ˴�������Ĵ���
private:
	char *pstr; //��ָ����Ϊ�����ַ������������� 
public:
	MyString() //�޲ι��캯�����������ַ��� 
	{
		pstr = new char[1]; //ָ���¿����Ŀռ� 
		*pstr = '\0';
	}
	MyString(const char *str)  //�ַ������캯�����ַ���д����pstrΪ�׵ĵ�ַ�С� 
	{
		int len =  strlen(str);
		pstr = new char[len + 1]; //�ȳ��ȶ��һλ���������'\0'
		strcpy(pstr,str); 
	}
	MyString(const MyString &rhs) //���ƹ��캯�� 
	{
		int len = strlen(rhs.pstr);
		pstr = new char[len + 1];
		strcpy(pstr,rhs.pstr);
	}
	MyString & operator=(const MyString & rhs) //���ظ�ֵ�����������ֵΪMyString��ʱ 
	{
		if(this  == & rhs) //thisָ�򱾶���Ŀ�ͷ���������ʵ��һ�������ñ仯
			return *this;
		delete []pstr; //�в�����Ϊʲô�������ɾ��
		int len = strlen(rhs.pstr);
		pstr = new char[len + 1];
		strcpy(pstr,rhs.pstr);
		return *this; 
	}
	//û��д ����Ϊchar*�ĸ�ֵ����ͼӷ����أ�ʵ���������ַ���������һ����ʱ����Ȼ�������������� 
	MyString & operator +=(const MyString &rhs)
	{
		MyString temp(*this);
		return *this = temp +rhs;
	}
	friend MyString operator+(const MyString &x,const MyString &y)  
	{ //���������Ϊ��Ԫ������������Ϊ��ͨ�����������ܷ������˽�г�Ա 
		char *temp = new char[strlen(x.pstr)+strlen(y.pstr)];
		strcpy(temp,x.pstr);
		strcat(temp,y.pstr);
		MyString re(temp); //���ò���Ϊ*char�Ĺ��캯������ʵ��
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
	char & operator[](int n)  //����char�е�[] 
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
	//������뵽�˽��� 
	
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
	//s1�Ĵ��±�0��ʼ����Ϊ4���Ӵ�
	cout << s1(0,4) << endl;
	//s1�Ĵ��±�5��ʼ����Ϊ10���Ӵ�
	cout << s1(5,10) << endl;
	return 0;
}
