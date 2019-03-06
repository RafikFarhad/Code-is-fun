/**         HODOR          **/



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
#define csii                                     pf("Case %d:\n", ++keis)
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
//int SET(int mask, int pos){return mask singlebar (1<<pos);}
//bool CHK(int mask, int pos){return (1&(mask>>pos));}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1}; const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define LT (1<<31)-1
#define MX
#define MOD
#define MY INT_MIN
//ll FAST_EXP(ll base, ll power) /*base^power%MOD*/   {ll res=1ll;while(power){if(power&1)res=(res*base)%MOD;base=(base*base)%MOD;power>>=1;}return res%MOD;}
#define SIZE 200005
int  start, last;
long long tree[SIZE<<2], prop[SIZE<<2], n, val, ar[SIZE];
void INIT(int i, int j, int node)
{
    if(i==j)
    {
        tree[node] = ar[i];
        prop[node] = 0;
        return;
    }
    int left = node<<1;
    int right = left | 1;
    int mid = (i+j)>>1;
    INIT(i, mid, left);
    INIT(mid+1, j, right);
    tree[node] = min(tree[left] , tree[right]);
    prop[node] = 0;
    return;
}
void UPDATE(int i, int j, int node)
{
    if(i>last || j<start) return;
    if(i>=start and j<=last)
    {
        tree[node] += val;
        prop[node] += val;
        return;
    }
    int left = node<<1;
    int right = left | 1;
    int mid = (i+j)>>1;
    UPDATE(i, mid, left);
    UPDATE(mid+1, j, right);
    tree[node] = min(tree[left]+prop[node] , tree[right] + prop[node]);// * (j-i+1);
    return;
}
ll QUERY(int i, int j, int node, int carry)
{
    if(i>last or j<start) return 1<<30;
    if(i>=start and j<=last)
    {
        return tree[node] + carry;
    }
    int left = node<<1;
    int right = left | 1;
    int mid = (i+j)>>1;
    ll p1 = QUERY(i, mid, left, carry+prop[node]);
    ll p2 = QUERY(mid+1, j, right, carry+prop[node]);
    return min(p1, p2);
}
int main()
{
    //ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
    //clock_t ooo = clock();
#endif
    ///                                    MAIN
    int i, t, j, k, l,  keis(0), c, d,  a, b;
    ll x, y;
    char pp[100];

    takell(n);
    for(i=1; i<=n; i++)
    {
        takell(ar[i]);
    }
    INIT(1, n, 1);
    takei(t);
    getchar();
    while(t--)
    {
        gets(pp);
        //deb(pp);
        k = sscanf(pp, "%d %d %lld", &a, &b, &val);
        if(k==2)
        {
            a++;
            b++;
            if(a>b)
            {
                start = a;
                last = n;
                x = QUERY(1, n, 1, 0);
                start = 1;
                last = b;
                y = QUERY(1, n, 1, 0);
                x = min(x, y);
            }
            else
            {
                start = a;
                last = b;
                x = QUERY(1, n, 1, 0);
            }
            __(x);
        }
        else
        {
            a++;
            b++;
            if(a>b)
            {
                start = a;
                last = n;
                UPDATE(1, n, 1);
                start = 1;
                last = b;
                UPDATE(1, n, 1);
            }
            else
            {
                start = a;
                last = b;
                UPDATE(1, n, 1);
            }
        }
    }


    /* Coding is FUN  */
    ///                                    ENDD
#ifndef ONLINE_JUDGE
    //pf("-------ENDS OF OUTPUT------\n\n");
    //pf("Time Elapsed: %lu\n", (clock()-ooo));
#endif
    return 0;
}



