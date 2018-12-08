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
int SET(int mask, int pos){return mask|(1<<pos);}
bool CHK(int mask, int pos){return (1&(mask>>pos));}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};
const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1}; const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define LT (1<<31)-1
#define MX
#define MOD
#define MY INT_MIN
//ll FAST_EXP(ll base, ll power) /*base^power%MOD*/   {ll res=1ll;while(power){if(power&1)res=(res*base)%MOD;base=(base*base)%MOD;power>>=1;}return res%MOD;}
char mat[202][202];
bool flag[202][202];
int mark;
int m, n, ans1, ans2;
unsigned lev[202][202];
vector <int> tlprt;

int BFS(int i, int j)
{
    queue <int> qu;
    qu.push(i);
    qu.push(j);
    CLR(flag);
    lev[i][j] = 0;
    flag[i][j] = 1;
//    deb(i, j);
    while(qu.size())
    {
        int x = qu.front(); qu.pop();
        int y = qu.front(); qu.pop();
        int l = lev[x][y];
        for(int ii=0; ii<4; ii++)
        {
            int u = x+xx[ii];
            int v = y+yy[ii];
            if(u==-1 or v==-1 or u==m or v==n or mat[u][v]=='#') continue;
            //deb(u, v, l);
            //lev[u][v] = l+1;
            if(mat[u][v]=='*')
            {
                for(int i=0; i<tlprt.size() and mark<3; i+=2)
                {
                    //if(lev[tlprt[i]][tlprt[i+1]]>=l+1)
                    {
                        if(tlprt[i]==u and tlprt[i+1]==v)
                        {
                            if(tlprt.size()>2 and lev[tlprt[i]][tlprt[i+1]]==-1)
                            {
                                lev[tlprt[i]][tlprt[i+1]] = l+3;
                                qu.push(tlprt[i]);
                                qu.push(tlprt[i+1]);
                            }
                        }
                        else if(lev[tlprt[i]][tlprt[i+1]]>l+2)
                        {
                            lev[tlprt[i]][tlprt[i+1]] = l+2;
                            qu.push(tlprt[i]);
                            qu.push(tlprt[i+1]);
                        }
                    }

                }
                mark++;
                continue;
            }
            else if(lev[u][v]>l+1)
            {
                lev[u][v] = l+1;
                qu.push(u);
                qu.push(v);
            }
        }
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
    //clock_t ooo = clock();
#endif
    ///                                    MAIN
    int i, t, j, k, l,  keis(0), c, d, x, y, a, b, p,q, r, s;
//    char pp[100];
//    fgets(pp, 100, stdin);
    takei(t);
    while(t--)
    {
        takei(m);
        takei(n);
        getchar();
        tlprt.clear();
        for(i=0; i<m; i++)
        {
            sf("%s", mat[i]);
            for(j=0; j<n; j++)
            {
                if(mat[i][j]=='*')
                {
                    tlprt.pb(i);
                    tlprt.pb(j);
                }
                else if(mat[i][j]=='P')
                {
                    p = i;
                    q = j;
                }
                else if(mat[i][j]=='D')
                {
                    r = i;
                    s = j;
                }
            }
        }
        CLR1(lev);
        mark = false;
        BFS(p, q);
//        deb(lev[5][5]);
//        deb(lev[6][5]);
//        deb(a, b, c);
        csi;
        if(lev[r][s]==-1)
        {
            puts("impossible");
        }
        else
        {
            _(lev[r][s]);
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



