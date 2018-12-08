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
#define MX 100000
#define MOD 1000000007
#define MY INT_MIN
int tree[4*MX], start, last, n, val, ar[MX];
void INIT(int i, int j, int node)
{
    if(i==j)
    {
        tree[node] = 1;
        return;
    }
    int left = node<<1;
    int right = left | 1;
    int mid = (i+j)>>1;
    INIT(i, mid, left);
    INIT(mid+1, j, right);
    tree[node] = tree[left]  + tree[right];
    return;
}

void UPDATE(int i, int j, int node, int carry)
{
    if(i>last || j<start) return;
    if(i==j)
    {
        tree[node] = 0;
        return;
    }
    int left = node<<1;
    int right = left | 1;
    int mid = (i+j)>>1;
    if(tree[left]>=carry) UPDATE(i, mid, left, carry);
    else UPDATE(mid+1, j, right, carry-tree[left]);
    tree[node] = tree[left]  + tree[right];
    return;
}
int QUERY(int i, int j, int node, int carry)
{
    if(i>last or j<start) return 0;
    if(i==j)
    {
        return i;
    }
    int left = node<<1;
    int right = left | 1;
    int mid = (i+j)>>1;
    if(tree[left]>=carry) return QUERY(i, mid, left, carry);
    return QUERY(mid+1, j, right, carry-tree[left]);
}
int main()
{
    //ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int i, t, j, k, l,  keis=0, a, b, c, d, x, y, lo, hi, mid;
    takei(t);
    while(t--)
    {
        takei(n);
        for(i=0; i<n; i++)
            takei(ar[i]);
        CLR(tree);
        INIT(1, n, 1);
        for(i=n-1; i>=0; i--)
        {
            start = 1;
            last = n;
            //pf("%d -> %d\n", ar[i], n+1-QUERY(1, n, 1, ar[i]+1));
            x = n+1-QUERY(1, n, 1, ar[i]+1);
            UPDATE(1, n, 1, ar[i]+1);
        }
        csi;
        _(x);
    }
    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}


