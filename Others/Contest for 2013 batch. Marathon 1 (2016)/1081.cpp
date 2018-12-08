///Only Sakibul Mowla vai is real :P



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
#define csll                                    pf("Case %lld: ", ++keis)
#define _(o)                                    pf("%d\n", o)
#define ll                                      long long
#define ull                                     unsigned long long
#define exx                                     2.7182818284590452353602875

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
#define SIZE 505

int lca[SIZE][SIZE][11], n, ans[SIZE][SIZE][11], ar[SIZE][SIZE];

void INIT_LCA()
{
    int i, j, k;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {/*
            if(i==1)
                lca[i][j][0] = -1;
            else
                lca[i][j][0] = j-1;*/
            for(k=1; k<11; k++)
            {
                lca[i][j][k] = -1;
                ans[i][j][k] = -1;
            }
        }
    }

    for(i=0; i<n; i++)
    {
        for(k=1; k<11; k++)
        {
            for(j=0; j<n; j++)
            {
                if(j-(1<<(k-1))>0)
                {
                    //lca[i][j][k] = lca[i][lca[i][j][k-1]][k-1];
                    ans[j][i][k] = max(ans[j-(1<<(k-1))][i][k-1], ans[j][i][k-1]);
                }
            }
        }
    }
    return;
}

int QUERY(int r, int a, int b)
{
    int i, j, k, anss = 0;
    //deb(r, a, b);
    if(a<b) swap(a, b);
    for(i=10; i>=0; i--)
    {
        if(a-(1<<i)>=b)
        {
            anss = max(anss, ans[a][r][i]);
            //deb(r, a, i, ans[a][r][i]);
            a = a-(1<<i);
        }
    }
    if(a-1==b) anss = max(anss, ans[b][r][0]);
    //deb("##", a, b);
    return anss;
}

int main()
{
    //ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int i, j, k, l,  keis=0, a, b, c, d;
    int t;
    takei(t);
    while(t--)
    {
        takei(n);
        takei(d);
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                takei(a);
                ar[i][j] = a;
                if(i) ans[i][j][0] = max(ar[i-1][j], ar[i][j]);
            }
        }
        INIT_LCA();
       // deb(ans[2][3][0], ans[2][3][1]);
       // deb(ans[4][4][0], ans[4][4][1]);
        csi;
        while(d--)
        {
            takei(a);
            takei(b);
            takei(c);
            a--;
            b--;
            k = 0;
            //deb(a, b, c)
            if(c==1)
                k = ar[a][b];
            for(i=b; i<b+c and c>1; i++)
            {
                k = max(k, QUERY(i, a, a+c-1));
               // deb(k);
            }
            pf("%d\n", k);
        }
    }


    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}

