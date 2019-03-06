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

int main()
{
    //time_t t1=clock();
    //freopen("414.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ///                                    MAIN
    int a, b, v, an, s, res_a, res_b;
    while(sf("%d %d %d %d %d", &a, &b, &v, &an, &s) && a+b+an+v+s)
    {
        res_a = (a+v*s*cos(an * PI / 180.0))/( a * 2);
        res_b = (b+v*s* sin(an * PI / 180.0))/( b * 2);
        pf("%d %d\n", res_a, res_b);
    }
    ///                                    ENDD
    //time_t t2=clock();
    //cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}
