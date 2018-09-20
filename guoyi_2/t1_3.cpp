//郭老师的课，第二级，第一周，例题。
//eg.3 称硬币
//跟写

#include<memory>
#include<string>
#include<cstring>
#include<iostream>
using namespace std;
char oriLights[5]; //存放原始输入灯状态矩阵
char lights[5]; //记录灯的变化（按键状态） 
char result[5]; //存储结果

int GetBit(char c, int i)  //取c的第i个比特
{
	return (c >> i ) & 1; //c右移i位，使c得第i位去零位，然后与1，结果取决于原来的i位值 
 } 

//设置字符c的第i位为v 
void SetBit(char &c, int i,int v)  //C++特性，加&是引用，函数里面改变形参，其实际的实参也跟着改变。 
{
	if(v){
		c |= ( 1 << i);  //v是一，将c的第i位置一：1左移i位 
	}
	else
	{
		c &= ~(1 << i); //v是零，将c的第i位置零：右边的第i位是0，与完后c的第i位就是零。 
	}
 } 
 
 //翻转第i位 :: 与一异或即可 
 void FlipBit(char &c,int i)
 {
 	c ^= (1<<i);
 }
 
 //输出结果
 void OutputResult(int t,char result[]) 
 {
 	cout << "PUZZLE #" << t<< endl;
 	for(int i = 0;i < 5;++i){
 		for(int j = 0;j<6;++j){
 			cout<< GetBit(result[i],j);
 			if( j < 5)
 				cout << " ";  //最后一个数字后面没有空格  其他的后面有一个空格 
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
		for(int  n = 0 ; n<64;++n){ //枚举第一行开关作用后的可能状态（二进制数）共64种可能 即给定64种初值，让后面的进行判断。
		//注意，遍历的n，即switchs是开关按下的情况，而不是灯的状态！ 
			int switchs  = n;
			memcpy(lights,oriLights,sizeof(oriLights)); //复制oriLights所指内存区中的oriLights长度个字节到lights   数组到数组的传递 
			for(int i = 0;i < 5; ++i){ //处理第i行 
				result[i] = switchs;
				for(int j =0;j < 6;j++){ //处理第i行第j个
					if(GetBit(switchs,j)){  //结果是1才需要处理 
						if(j > 0 )
							FlipBit(lights[i],j-1);
						FlipBit(lights[i],j);
						if(j < 5)
							FlipBit(lights[i],j+1);
					} 
				}
				if(i < 4)   //处理i+1行的数据 
					lights[i+1] ^= switchs; //异或swithcs里面是1 light就翻转  0不翻转 
				switchs = lights[i]; //将结果存入swithcs 下次循环存入result[i] 
			}
			//到此为止能保证前四行都是灭的，只需要判断第五行的是不是全灭即可
			if(lights[4] == 0)
			{
				OutputResult(t,result);
				break;
			 } 
		}
	 }
 }
