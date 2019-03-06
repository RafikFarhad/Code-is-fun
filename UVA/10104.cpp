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
long long a, b, gcd, x, y;

void OT()
{
    long long x1=1, y1=0, x2=0, y2=1, mod, r;

    while(b)
    {
        r = a/b;
        mod = a%b;
        a = b;
        b = mod;
        x = x1 - x2*r;
        y = y1 - y2*r;
        x1 = x2;
        y1 = y2;
        x2 = x;
        y2 = y;
    }
    x = x1;
    y = y1;
    gcd = a;
   // cout << a<< endl;
}

int main()
{
    //time_t t1=clock();
    //freopen("10420.txt", "r", stdin);

    ///                                    MAIN
    while(sf("%lld %lld", &a, &b)!=EOF)
    {
        OT();
        pf("%lld %lld %lld\n", x, y, gcd);
    }
    ///                                    ENDD
    //time_t t2=clock();
    //cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}




