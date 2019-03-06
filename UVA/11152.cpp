/// RAFIK FARHAD
/// fb.com/rafikfarhad
/// SUST_CSE_13
#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>
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
//template <class T> void MyDebug(T x, T y) { cout << x << ", " << y << endl;}
//template <class T> void MyDebug(T x, T y, T z) { cout << x << ", " << y << ", " << z << endl;}

int main()
{
    //time_t t1=clock();
    //freopen("10176.txt", "r", stdin);

    ///                                    MAIN
    double a, b, c, tri, inc, outc;
    while(sf("%lf %lf %lf", &a, &b, &c)!=EOF)
    {
        double s = (a+b+c) /2;
        tri = sqrt(s*(s-a)*(s-b)*(s-c));
        inc = (tri/s)*(tri/s) * PI;
        double big = (a*b*c) / (4*tri);
        outc =  big * big * PI;
        pf("%.4lf %.4lf %.4lf\n",  outc-tri, tri-inc, inc);
    }
    ///                                    ENDD
    //time_t t2=clock();
    //cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}



