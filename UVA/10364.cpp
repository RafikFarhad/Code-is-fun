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
#define SIZE INT_MAX
int ar[25], n, side;
bool mark, flag[10000006];

void CALL(int mask=0, int tot=0, int bahu=0)
{
    if(mask==(1<<n)-1)
    {
        if(tot==0 and bahu==4)
            mark = true;
        return;
    }
    if(flag[mask]) return;
    flag[mask] = 1;
    //if(bahu==4) return;
    if(mark) return;
    int i;
    for(i=0; i<n; i++)
    {
        if(!(mask&(1<<i)))
        {
            if(tot+ar[i]>side)
                continue;
            else if(tot+ar[i]==side)
            {
                CALL(mask|(1<<i), 0, bahu+1);
            }
            else
            {
                CALL(mask|(1<<i), tot+ar[i], bahu);
            }
        }
    }
    return;
}

int main()
{
    //ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("000.txt","r",stdin);
    freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int i, t, j, k, l,  keis=0, a, b, c, d, x, y;
    takei(t);
    while(t--)
    {
        takei(n);
        a = 0;
        for(i=0; i<n; i++)
        {
            takei(ar[i]);
            a+=ar[i];
        }
        CLR(flag);
        mark = false;
        //deb(a, a%4, (1<<n)-1, a/4);
        if(a%4==0 and n>3)
        {
            side = a/4;
            CALL();
        }
        //csi;
        if(mark) pf("yes\n");
        else pf("no\n");
    }
    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}
