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

long long unsigned MODD(long long unsigned base, long long unsigned poow, long long unsigned mod)
{
    long long unsigned r =1;
    while(poow>0)
    {
        if(poow%2) r = (r*base)%mod;
        base = (base*base)%mod;
        poow/=2;
    }
    return r;
}

int main()
{
    long long unsigned base, poow, mod;
    int t;
    ;
    while(scanf("%d", &t)==1 &&t)
    {
        for(int i=0; i<t; i++)
        {
            scanf("%llu %llu %llu", &base, &poow, &mod);
            printf("%llu\n", MODD(base, poow, mod));
        }
    }
        return 0;
}




