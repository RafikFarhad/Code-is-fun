/*=============================================================================
#  Author:          RafikFarhad - https://github.com/RafikFarhad/Code_is_fun
#  Email:           rafikfarhad@gmail.com
#  FileName:        541 A.cpp
#  Type:            easy
#  Description:     
#  Version:         0.0.1
#  Created On:      01:10, 07-03-2019
=============================================================================*/
/*Return of Ghost*/
#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <math.h>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <new>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#define CLR(o) memset(o, 0x00, sizeof o)
#define CLR1(o) memset(o, -1, sizeof o)
#define takei(a) scanf("%d", &a)
#define takell(a) scanf("%lld", &a)
#define takellu(a) scanf("%llu", &a)
#define sf scanf
#define pb push_back
#define mp make_pair
#define ppp system("pause")
#define ok cout << "OKA" << endl;
#define pf printf
#define NL printf("\n")
#define PI 2 * acos(0)
#define all(o) o.begin(), o.end()
#define csi pf("Case %d: ", ++keis)
#define csii pf("Case %d:\n", ++keis)
#define _(o) pf("%d\n", o)
#define ll long long
#define ull unsigned long long
#define exx 2.7182818284590452353602875
#define xx first
#define yy second

///Helper
using namespace std;
template <class T1>
void __(T1 p) { cout << p << endl; }
void deb()
{
    cout << endl;
}
template <typename T, typename... T1>
void deb(T s, T1... ts)
{
    return (cout << s << " "), deb(ts...);
}
long int POOW(long long b, long long p)
{
    if (p == 0)
        return 1;
    return b * POOW(b, p - 1);
}
//int SET(int mask, int pos){return mask  singlebar  (1<<pos);}
//bool CHK(int mask, int pos){return (1&(mask>>pos));}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};
const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1};
const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1}; // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define LT (1 << 31) - 1
#define MX
#define MOD
//#define MY INT_MIN
//ll FAST_EXP(ll base, ll power) /*base^power%MOD*/   {ll res=1ll;while(power){if(power&1)res=(res*base)%MOD;base=(base*base)%MOD;power>>=1;}return res%MOD;}

int main()
{
    //ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    //freopen("/home/rafikfarhad/Desktop/000.txt","r",stdin);
    //freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
    //clock_t ooo = clock();
#endif
    ///                                    MAIN
    int i, t, j, k, l, keis(0), c, d, x, y, a, b;
    //    char inp[100];
    //    fgets(inp, 100, stdin);
    ll h1, h2, w1, w2, sum;
    while (sf("%lld %lld %lld %lld", &w1, &h1, &w2, &h2) != EOF)
    {
        sum = (h1+h2)*2 + (max(w1,w2)*2) + 4;
        __(sum);
    }
    /* Coding is FUN  */
    ///                                    ENDD
#ifndef ONLINE_JUDGE
    //pf("-------ENDS OF OUTPUT------\n\n");
    //pf("Time Elapsed: %lu\n", (clock()-ooo));1 4 3 3
#endif
    return 0;
}
