#include<bits/stdc++.h>
using namespace std;
const double pi=acos(-1.0);
double a[10002];
int main()
{
	freopen("C:\\Users\\DelkBan\\Downloads\\in (28).txt","r",stdin);
    int n,m,sum=0;
    double r=.0,l=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
      {
        cin>>a[i];
        a[i]=pi*a[i]*a[i];
        r=r>a[i]?r:a[i];
      }
    m++;
    while(l+0.0000001<r)
      {
        double mid=(l+r)/2;
        for(int i=1;i<=n;i++)
          sum+=a[i]/mid;
        if(sum>=m) l=mid;
        else r=mid;
        sum=0;
      }
    printf("%.3lf",l);
    return 0;
}


