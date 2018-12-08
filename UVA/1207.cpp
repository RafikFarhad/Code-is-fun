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
#define MX 200005
#define MX2 100005
int tree[4*MX], prop[4*MX], start, last, n, val;

void INIT(int i, int j, int node)
{
    if(i==j)
    {
        tree[node] = 0;
        prop[node]= 0;
        return;
    }
    int left = node<<1;
    int right = left | 1;
    int mid = (i+j)>>1;
    INIT(i, mid, left);
    INIT(mid+1, j, right);
    tree[node] = tree[left]  + tree[right];
    prop[node] = 0;
    return;
}
void UPDATE(int i, int j, int node, int todo)
{
    if(i>last || j<start) return;
    if(i>=start and j<=last)
    {
        tree[node] = (j-i+1);
        prop[node] = 1;
        return;
    }
    int left = node<<1;
    int right = left | 1;
    int mid = (i+j)>>1;
    UPDATE(i, mid, left, 0);
    UPDATE(mid+1, j, right, 0);
    tree[node] = tree[left]  + tree[right] ;
    return;
}
int QUERY(int i, int j, int node, int carry)
{
    if(i>last or j<start) return 0;
    if(i>=start and j<=last)
    {
        if(prop[node]==1 or carry)
            return j-i+1;
        if(i==j)
            return 0;
    }
    int left = node<<1;
    int right = left | 1;
    int mid = (i+j)>>1;
    int p1 = QUERY(i, mid, left, carry|prop[node]);
    int p2 = QUERY(mid+1, j, right, carry|prop[node]);
    return p1+p2;
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
    pair<int, int> pii[MX2];
    takei(t);
    while(t--)
    {
        takei(n);
        INIT(1, MX, 1);
        for(i=0; i<n; i++)
        {
            takei(a);
            takei(b);
            pii[i] = make_pair(a, b);
        }
        a = 0;
        for(i=n-1; i>=0; i--)
        {
            start = pii[i].xx;
            last = pii[i].yy;
            x = QUERY(1, MX, 1, 0);
            //deb(start, last, x, a);

            if(x==last-start+1)
                continue;
            a++;
            UPDATE(1, MX, 1, last-start+1);
            //deb(tree[1]);
        }
        csi;
        _(a);
    }
    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}



