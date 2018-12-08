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
#define SIZE 10000000
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

#define maxi 1002
#define len 2570

int fact[maxi+5][len+5];

void FACT()
{
    fact[0][0] = 1;
    fact[1][0] = 1;
    int i, j, k;
    for(i=2; i<maxi-1; i++)
    {
        for(j=0; j<len; j++)
        {
            fact[i][j] += fact[i-1][j] * i;
            if(fact[i][j]>9)
            {
                fact[i][j+1] += fact[i][j]/10;
                fact[i][j] %=10;
            }
        }
    }
    return;
}

int main()
{
    // time_t t1=clock();
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#ifndef ONLINE_JUDGE
    //freopen("623.inp","r",stdin);
#endif
    ///                                    MAIN
    int n, i, j;
    FACT();
    int ar[1001];
    memset(ar, 0, sizeof(ar));
    for(i=1; i<1001; i++)
        {
            for(j=0; j<len; j++)
                ar[i]+=fact[i][j];
        }
    while(sf("%d", &n)!=EOF)
    {
        pf("%d\n", ar[n]);
    }
    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}
