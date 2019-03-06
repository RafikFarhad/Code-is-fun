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
#define sf scanf
#define ssf sscanf
#define pf printf
#define PI 2*acos(0)
using namespace std;

//template <class T> void MyDebug(T x, T y) { cout << x << ", " << y << endl;}
//template <class T> void MyDebug(T x, T y, T z) { cout << x << ", " << y << ", " << z << endl;}

int main()
{
    //time_t t1=clock();
    //freopen("10176.txt", "r", stdin);

    ///                                    MAIN
    double n ,m , a, b, res;
    long int t, keis=0;
    sf("%ld", &t);
    while(t--)
    {
        sf("%lf %lf %lf %lf", &n, &m, &a, &b);
        res = m * (a+b);
        res = res - (n*a);
        res /= b;
        if(res>=0 && res <=10) pf("Case #%ld: %.2lf\n", ++keis, res);
        else pf("Case #%ld: Impossible\n", ++keis);
    }

    ///                                    ENDD
    //time_t t2=clock();
    //cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}

