//填空题 第i位替换 
/*
 #include <iostream>
using namespace std;

int bitManipulation1(int n, int m, int i) {
// 在此处补充你的代码
return (m>>i)&0x1 ? 
		n |= (1<<i): //用或置一
		n &~ (1<<i); //置零 
}

int main() {
	int n, m, i, t;
	cin >> t;
	while (t--) { 
		cin >> n >> m >> i;
		cout << bitManipulation1(n, m, i) << endl;
	}
	return 0;
}


#include <iostream>
using namespace std;

int bitManipulation2(int n, int i) {
// 在此处补充你的代码
return (n>>i)&0x1 ? n &~(1<<i) : n |=(1<<i);
}

int main() {
	int t, n, i;
	cin >> t;
	while (t--) {
		cin >> n >> i;
		cout << bitManipulation2(n, i) << endl;
	}
	return 0;
}
*/

#include <iostream>
using namespace std;

int bitManipulation3(int n, int i) {
// 在此处补充你的代码
return n ^ (0xffffffff << (32-i));
//将n和一个左边i位是1，右边剩下的是0的数异或即可。 
}

int main() {
	freopen("C:\\Users\\DelkBan\\Downloads\\in (28).txt","r",stdin);
	int t, n, i;
	cin >> t;
	while (t--) {
		cin >> n >> i;
		cout << bitManipulation3(n, i) << endl;
	}
	return 0;
}
