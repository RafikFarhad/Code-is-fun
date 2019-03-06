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
#define TAKE(a) scanf("%lld", &a)
#define sf scanf
#define ssf sscanf
#define pb push_back
#define PPP system("pause")
#define ok cout << "OK" <<endl;
#define pf printf
#define PI 2*acos(0)
using namespace std;

template <class T> T MAX(T a, T b) { return a>b?a:b;}
template <class T> T MIN(T a, T b) { return a<b?a:b;}
template <class T1> void deb(T1 x){ cout << "Debugging: " << x << endl;}
template <class T1, class T2> void deb(T1 x, T2 y){ cout << "Debugging: " << x << ", " << y << endl;}
template <class T1, class T2, class T3> void deb(T1 x, T2 y, T3 z) { cout << "Debugging: " << x << ", " << y << ", " << z << endl;}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};
const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1};      // diagonal -> 8 horizontal/vertical->4
const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // Knight moovs
#define SIZE 5000003
pair <long long, long long> EE(long long a, long long b)
{
    if(b==0)
        return make_pair(1, 0);
    long long k = a%b;
    pair <long long, long long> m = EE(b, k);
    k = a/b;
    return make_pair(m.second, m.first-k*m.second);
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
    long long t, n, r, i, j, k, m, up, down, res, mod = 1000003, *f, h=1;
    f = new long long[1000005];
    pair <long long, long long> p;
    f[0] = 1;
    for(i=1; i<1000002; i++)
        f[i] = (f[i-1]%mod*i%mod)%mod;
    TAKE(t);
    while(t--)
    {
        TAKE(n); TAKE(r);
        if(r>n) {pf("Case %lld: 0\n", h++); continue;}
        up = f[n];
        down = (f[n-r]%mod*f[r]%mod)%mod;
        //deb(up, down);
        p = EE(down, mod);
        down = p.first;
        while(down<0) down+=mod;
        //deb(p.first, p.second);
        res = (up*down%mod)%mod;
        pf("Case %lld: %lld\n", h++, res);
    }
    delete(f);
    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}

