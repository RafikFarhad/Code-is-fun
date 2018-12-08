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
#define csi                                     pf("Case %d:\n", ++keis)
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
#define MX 100005
#define MOD 1000000007
#define MY INT_MIN
int block = 500;
class DATA
{
public:
    int l, r, id;
    DATA(){};
    bool operator < (const DATA &a) const
    {
        if(l/block==a.l/block)
            return r/block<a.r/block;
        return l/block<a.l/block;
    }
};
DATA qu[50004];
int n, ar[MX], cow[MX];
int f[MX], k;

void ADD(int x)
{
    f[cow[ar[x]]]--;
    cow[ar[x]]++;
    f[cow[ar[x]]]++;
    if(k<cow[ar[x]])
        k++;
}
void REMOVE(int x)
{
    f[cow[ar[x]]]--;
    cow[ar[x]]--;
    f[cow[ar[x]]]++;
    if(f[k]==0)
        k--;
}


int main()
{
    //ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int i, t, j, l,  keis=0, a, b, c, d, x, y, ans[MX], r;

    takei(t);
    while(t--)
    {
        takei(n);
        takei(l);
        takei(a);
        for(i=1; i<=n; i++)
        {
            takei(ar[i]);
            f[i] = 0;
            cow[i] = 0;
        }
        for(i=0; i<a; i++)
        {
            takei(b);
            takei(c);
            qu[i].l = b;
            qu[i].r = c;
            qu[i].id = i;
        }
        sort(qu, qu+a);
        x = 1;
        y = 1;
        k = 1;
        f[0] = n;
        ADD(1);
        for(i=0; i<a; i++)
        {
            l = qu[i].l;
            r = qu[i].r;
            while(x<l)
            {
                REMOVE(x);
                x++;
            }
            while(x>l)
            {
                x--;
                ADD(x);
            }
            while(y>r)
            {
                REMOVE(y);
                y--;
            }
            while(y<r)
            {
                y++;
                ADD(y);
            }
            ans[qu[i].id] = k;
            //deb(qu[i].id, k, l, r);

        }
        csi;
        for(i=0; i<a; i++)
            _(ans[i]);
    }
    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}



