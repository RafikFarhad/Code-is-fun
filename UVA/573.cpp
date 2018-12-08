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
//template <class T> void MyDebug(T x, T y) { cout << x << ", " << y << endl;}
//template <class T> void MyDebug(T x, T y, T z) { cout << x << ", " << y << ", " << z << endl;}


int main()
{
    //time_t t1=clock();
    freopen("573.txt", "r", stdin);

    ///                                    MAIN
    int i, day;
    double h, u, d, f, current;
    while(sf("%lf", &h)==1 && h)
    {
        sf("%lf %lf %lf", &u, &d, &f);
        current = 0;
        f =  u* f/100;
        for(day=1; ; day++)
        {
           // cout << current << endl;
            current = current + u;
            if(current > h) break;
            current = current - d;
            if(current < 0.0) break;
            u = u - f;
            if(u<0.0) u = 0.0;
        }
        if(current > h) pf("success on day %d\n", day);
        else pf("failure on day %d\n", day);
    }
    ///                                    ENDD
    //time_t t2=clock();
    //cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}


