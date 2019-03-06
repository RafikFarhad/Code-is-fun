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
/** Author      : Rafik Farhad            */
/** Mail to     : rafikfarhad@gmail.com   */
/******************************************/
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
int SET(int mask, int pos){mask = mask|(1<<pos);return mask;}
bool CHK(int mask, int pos){return (1&(mask>>pos));}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1}; const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define MX INT_MAX
#define MOD 1000000007
#define MY INT_MIN
int ar[22][22], n, m, all, dp[(1<<15)+5], life[22];

int DIST(int a, int b)
{
    //deb(ceil(b/(double)a), a);
    //ok
    if(!a) deb("$", a);
    return ceil((double)b/(double)a);
}


int GO(int mask)
{
    //if(!CHK(mask, 2) and mask!=0) return 10000000;
    if(mask==(1<<all)-1)
        return 0;
    int &ret=dp[mask], i, k;
    if(~ret) return ret;
    ret = 1<<30;
    for(i=0; i<all; i++)
    {
        if(CHK(mask, i)) continue;
        k = 1;
        ret = min(ret, GO(SET(mask, i)) + life[i] );
        for(int j=0; j<all; j++)
        {
            if(CHK(mask, j))
            {
                k = ar[j][i];
                if(k==0) continue;
                ret = min(ret, GO(SET(mask, i)) + DIST(k, life[i])  );
            }
        }

    }
    return ret;
}



int main()
{
    //ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
    //clock_t ooo = clock();
#endif
    ///                                    MAIN

    int i, t, j, k, l,  keis=0, c, d;
    takei(t);
    char in[20][20];
    while(t--)
    {
        takei(n);
        for(i=0; i<n; i++)
        {
            ar[20][i] = 1;
            takei(life[i]);
        }
        getchar();
        for(i=0; i<n; i++)
        {
            gets(in[i]);
            //puts(in[i]);
        }
        all = 0;
        CLR1(dp);
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                //deb("----------->", in[i][j]);
                ar[i][j] = in[i][j]-'0';
                //deb(ar[i][j]);
            }
        }
        all = n;
        csi;
        _(GO(0));
    }
    /* Coding is FUN  */
    ///                                    ENDD
#ifndef ONLINE_JUDGE
    //pf("-------ENDS OF OUTPUT------\n\n");
    //pf("Time Elapsed: %lu\n", (clock()-ooo));
#endif
    return 0;
}


