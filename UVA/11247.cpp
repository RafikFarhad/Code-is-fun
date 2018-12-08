/// RAFIK FARHAD
/// fb.com/rafikfarhad
/// SUST_CSE_13
#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <new>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#define PI 2*acos(0)
using namespace std;

//template <class T> void MyDebug(T x, T y) { cout << x << ", " << y << endl;}
//template <class T> void MyDebug(T x, T y, T z) { cout << x << ", " << y << ", " << z << endl;}

int main()
{
    long long m, x;
    double v;
    while(scanf("%lld %lld", &m, &x)==2 && m + x)
    {
        if(m==1 || x==0 || x==100)
        {
            puts("Not found");
        }
        else
        {
            v=100.0*(m-1)/(100.0-(double)x) - 1.0;
            v = ceil(v);
            if(v<m)
                puts("Not found");
            else
                printf("%.0lf\n", v);
        }
    }
    return 0;
}
