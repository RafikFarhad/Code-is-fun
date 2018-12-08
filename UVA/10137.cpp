/// RAFIK FARHAD
/// fb.com/rafikfarhad
/// SUST_CSE_13
#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <new>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#define MAX3(a, b, c) MAX(a , MAX(b,c))
#define sf scanf
#define ssf sscanf
#define pf printf
#define PI 2*acos(0)
#define TOOT 10000002
using namespace std;

template <class T> T MAX(T a, T b)
{
    return a>b?a:b;
}
template <class T> T MIN(T a, T b)
{
    return a<b?a:b;
}
template <class T> void MyDebug(T x, T y)
{
    cout << "Debugging: " << x << ", " << y << endl;
}
//template <class T> void MyDebug(T x, T y, T z) { cout << x << ", " << y << ", " << z << endl;}

int main()
{
    //time_t t1=clock();
    //freopen("414.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
    ///                                    MAIN
    int n;
    while(sf("%d",&n)==1 && n)
    {
        double ar[n];
        double sum = 0;
        for(int i=0;i<n;i++) sf("%lf",&ar[i]);
        for(int i = 0 ; i < n ; i++)    sum+=ar[i];

        sum/=n;

        double ans1=0,ans2=0;

        for(int i=0;i<n;i++)
        {
            double dif = (double)(long)((ar[i]-sum)*100.0)/100.0;
            if(dif > 0) ans1+=dif;
            else  ans2-=dif;
        }
        if(ans2 > ans1)   pf("$%.2lf\n",ans2);
        else pf("$%.2lf\n",ans1);
    }
    ///                                    ENDD
    //time_t t2=clock();
    //cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}



