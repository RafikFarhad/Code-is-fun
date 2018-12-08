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
#define MAX3(a, b, c) MAX(a , MAX(b,c))
#define sf scanf
#define ssf sscanf
#define pf printf
#define PI 2*acos(0)
using namespace std;

template <class T> T MAX(T a, T b)
{
    return a>b?a:b;
}
template <class T> T MIN(T a, T b)
{
    return a<b?a:b;
}
//template <class T> void MyDebug(T x, T y) { cout << x << ", " << y << endl;}
//template <class T> void MyDebug(T x, T y, T z) { cout << x << ", " << y << ", " << z << endl;}


int main()
{
    //time_t t1=clock();
    //freopen("573.txt", "r", stdin);

    ///                                    MAIN
    int h, m;
    double ha, ma;
    while(sf("%d:%d", &h, &m) && h + m)
    {
        int ot = h*60 + m;
        ma = (ot%60) * 6.0;
        ha = ot / 2.0;
        if(ma<1.0 && ha > 180.1)
        {
            ma = 360.0;
        }
      //  cout << ha << "  " << ma << endl;
        double p = fabs(ma-ha);
        if(p>180)
        {
            p = 360 - p;
        }
        pf("%.3lf\n", p);
    }
    ///                                    ENDD
    //time_t t2=clock();
    //cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}


