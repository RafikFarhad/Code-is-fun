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
/******************************************/
/** Author     : Rafik Farhad              */
/** Mail to     : rafikfarhad@gmail.com   */
/*****************************************/
#define CLR(o)                                  memset(o, 0x00, sizeof o)
#define CLR1(o)                                 memset(o, -1, sizeof o)
#define takei(a)                                scanf("%d", &a)
#define takell(a)                               scanf("%lld", &a)
#define takellu(a)                              scanf("%llu", &a)
#define sf                                      scanf
#define pb                                      push_back
#define mp                                      make_pair
#define ppp                                     system("pause")
#define ok                                      cout << "OKA" <<endl;
#define pf                                      printf
#define NL                                      printf("\n")
#define PI                                      2*acos(0)
#define all(o)                                  o.begin(), o.end()
#define csi                                     pf("Case %d: ", ++keis)
#define csll                                    pf("Case %lld: ", ++keis)
#define _(o)                                    pf("%d\n", o)
#define ll                                      long long
#define ull                                     unsigned long long
#define exx                                     2.7182818284590452353602875
#define xx                                      first
#define yy                                      second

///Helper
using namespace std;
template <class T> T MAX(T a, T b) { return a>b?a:b;}template <class T> T MIN(T a, T b) { return a<b?a:b;}
template <class T1> void __(T1 p) { cout << p << endl;}
template <class T1> void deb(T1 p) { cout << "Debugging: " << p << endl;}
template <class T1, class T2> void deb(T1 p, T2 q) { cout << "Debugging: " << p << "\t" << q  << endl;}
template <class T1, class T2, class T3> void deb(T1 p, T2 q, T3 r) { cout << "Debugging: " << p << "\t " << q << "\t " << r << endl;}
template <class T1, class T2, class T3, class T4> void deb(T1 p, T2 q, T3 r, T4 s) { cout << "Debugging: " << p << "\t " << q << "\t " << r << "\t " << s << endl;}
long long int POOW(long long b, long long p) { if(p==0) return 1; return b*POOW(b, p-1);}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1}; const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define SIZE 100005
long long tree[4*SIZE+7], val, mod=1000000007ll;
int start, last, n;

void UPDATE(int i, int j, int node)
{
    if(i>last or j<start) return;
    if(i>=start and j<=last)
    {
        tree[node] = val;
        return;
    }
    int left = node<<1;
    int right = left | 1;
    int mid = (i+j)>>1;
    UPDATE(i, mid, left);
    UPDATE(mid+1, j, right);
    tree[node] = tree[left] + tree[right];
    tree[node]%=mod;
    return;
}
ll QUERY(int i, int j, int node)
{
    if(i>last or j<start) return 0;
    if(i>=start and j<=last)
    {
        return tree[node];
    }
    int left = node<<1;
    int right = left | 1;
    int mid = (i+j)>>1;
    ll p1 = QUERY(i, mid, left);
    ll p2 = QUERY(mid+1, j, right);
    return (p1+p2)%mod;
}

bool COMPA(pair <ll, int> a, pair <ll, int> b)
{
    if(a.xx==b.xx)
        return a.yy>b.yy;
    else
        return a.xx<b.xx;
}

int main()
{
    //ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int i, t, j, k, l,  keis=0, a, b, c, d, x, y;
    pair <ll, int> ar[SIZE+7];
    takei(t);
    ll ans;
    while(t--)
    {
        takei(n);
        CLR(tree);
        ans = 0ll;
        for(i=0; i<n; i++)
        {
            takell(val);
            ar[i] = make_pair(val, i);
        }
        sort(ar, ar+n, COMPA);
        a = 1;
        for(i=0; i<n; i++)
        {
            start = 1;
            last = ar[i].yy + 1;
            val = QUERY(1, n, 1) + 1;
            ans+=val;
            //deb(ar[i].xx, ar[i].yy, val);
            start = last;;
            UPDATE(1, n, 1);
            ans%=mod;
            /*deb("test");
            for(j=1; j<=12; j++)
                pf("%d -> %lld\n", j, tree[j]);
            deb("test");*/
           // start = 1;
           // ans = ans + QUERY(1, n, 1)+1 - val;
         //   deb(start, last, ans, ar[i].xx);
        }
        while(ans<0) ans+=mod;
        ans%=mod;
        csi;
        pf("%lld\n", ans);
    }
    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}



