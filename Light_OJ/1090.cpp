/// #define_SUST
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
#define CLR(o) memset(o, 0, sizeof o)
#define CLR1(o) memset(o, -1, sizeof o)
#define MAX3(a, b, c) MAX(a , MAX(b,c))
#define MIN3(a, b, c) MIN(a , MIN(b,c))
#define sf scanf
#define ssf sscanf
#define pb push_back
#define PPP system("pause")
#define ok cout << "OK" <<endl;
#define pf printf
#define PI 2*acos(0)
#define SIZE 10000000
using namespace std;

template <class T> T MAX(T a, T b) { return a>b?a:b;}
template <class T> T MIN(T a, T b) { return a<b?a:b;}
template <class T1> void deb(T1 x){ cout << "Debugging: " << x << endl;}
template <class T1, class T2> void deb(T1 x, T2 y){ cout << "Debugging: " << x << ", " << y << endl;}
template <class T1, class T2, class T3> void deb(T1 x, T2 y, T3 z) { cout << "Debugging: " << x << ", " << y << ", " << z << endl;}

int COUNT(long a, int by)
{
    int cow = 0;
    while(a)
    {
        cow+=(a/by);
        a = a/by;
    }
    return cow;
}

int main()
{
    // time_t t1=clock();
#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    long n, r, p, q;
    int t, i, j, k, sum2, sum5;
    sf("%d", &t);
    for(i=0; i<t; i++)
    {
        sf("%ld %ld %ld %ld", &n, &r, &p, &q);
        sum2 = COUNT(n, 2) - COUNT(n-r, 2) - COUNT(r, 2);
        sum5 = COUNT(n, 5) - COUNT(n-r, 5) - COUNT(r, 5);
        k = 0;
        j = p;
        while(j>0 && j%2==0)
        {
            k++;
            j/=2;
        }
        sum2+=k*q;
        k = 0;
        j = p;
        while(j>0 && j%5==0)
        {
            k++;
            j/=5;
        }
        sum5+=k*q;
        pf("Case %d: %d\n",i+1, MIN(sum2, sum5));
    }
    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}

