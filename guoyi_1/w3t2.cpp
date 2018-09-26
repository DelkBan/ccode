//第三周作业  第十题 鸡尾酒疗法 
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int n, a, b;
    double x, y;
    cin >> n;
    cin >> a >> b;
    x = (double)b/a;
    for (int i=1; i<n; i++){
        cin >> a >> b;
        y = (double)b/a;
        if ((y-x) > 0.05) cout << "better" << endl;
        else if ((x-y) > 0.05) cout << "worse" << endl;
        else cout << "same" << endl;
    }
    return 0;
}

