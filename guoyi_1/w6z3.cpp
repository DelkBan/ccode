//����� ��iλ�滻 
/*
 #include <iostream>
using namespace std;

int bitManipulation1(int n, int m, int i) {
// �ڴ˴�������Ĵ���
return (m>>i)&0x1 ? 
		n |= (1<<i): //�û���һ
		n &~ (1<<i); //���� 
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
// �ڴ˴�������Ĵ���
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
// �ڴ˴�������Ĵ���
return n ^ (0xffffffff << (32-i));
//��n��һ�����iλ��1���ұ�ʣ�µ���0������򼴿ɡ� 
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
