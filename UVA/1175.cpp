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
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1}; const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define MX INT_MAX
#define MOD 1000000007
#define MY INT_MIN
int r, c, flag[220][220],flag2[220][220], level[220][220], level2[220][220];
char in[220][220];

void BFS(int x, int y)
{
    int i, j, ux, uv, vx, vv;

    queue <int> qu;
    qu.push(x);
    qu.push(y);
    flag[x][y] = 1;
    level[x][y] = 0;
    while(qu.size())
    {
        ux = qu.front(); qu.pop();
        uv = qu.front(); qu.pop();
        for(i=0; i<4; i++)
        {
            vx = ux+xx[i];
            vv = uv+yy[i];
            if(vx==-1 or vv==-1 or vx==r or vv==c or flag[vx][vv] or in[vx][vv]=='#') continue;
            flag[vx][vv] = 1;
            level[vx][vv] = level[ux][uv] + 1;
            qu.push(vx);
            qu.push(vv);
        }
    }
    return;
}
queue <int> qu2;

void BFS2()
{
    int i, j, ux, uv, vx, vv;

    while(qu2.size())
    {
        ux = qu2.front(); qu2.pop();
        uv = qu2.front(); qu2.pop();
        for(i=0; i<4; i++)
        {
            vx = ux+xx[i];
            vv = uv+yy[i];
            if(vx==-1 or vv==-1 or vx==r or vv==c or flag2[vx][vv] or in[vx][vv]=='#') continue;
           // deb(vx, vv, flag2[vx][vv]);
            flag2[vx][vv] = 1;
            level2[vx][vv] = level2[ux][uv] + 1;
            qu2.push(vx);
            qu2.push(vv);
        }
    }

    return;
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
    int i, t, j, k, l,  keis=0, a, b, d, x, y;
    takei(t);
    while(t--)
    {
        takei(r);
        takei(c);
        getchar();
        for(i=0; i<r; i++)
        {
            gets(in[i]);
            //puts(in[i]);
        }
        CLR(flag2);
        for(i=0; i<r; i++)
        {
            for(j=0; j<c; j++)
            {
                flag[i][j] = 0;
                level[i][j] = 1<<30;
                level2[i][j] = 1<<30;
            }
        }
        for(i=0; i<r; i++)
        {
            for(j=0; j<c; j++)
            {
                if(in[i][j]=='J')
                {
                    BFS(i, j);
                }
                else if(in[i][j]=='F')
                {
                    flag2[i][j] = 1;
                    level2[i][j] = 0;
                    //deb("*", i, j);
                    //deb(level2[0][5]);
                    qu2.push(i);
                    qu2.push(j);
                }
            }
        }
        x = 1<<30;
        BFS2();
        i=0; j=5;
        //deb(i, j, level2[0][5]);
        for(i=0; i<r; i+=(r-1))
        {
            for(j=0; j<c; j++)
            {
                //deb(i, j);
                if(flag2[i][j]==0 and flag[i][j]==1)
                {
                    x = min(x, level[i][j]);
                }
                else if(flag2[i][j]==1 and flag[i][j]==1 and level2[i][j]>level[i][j])
                {
                    x = min(x, level[i][j]);
                }
            }
        }
        for(i=0; i<r; i++)
        {
            for(j=0; j<c; j+=(c-1))
            {
               // deb(i, j);
                if(flag2[i][j]==0 and flag[i][j]==1)
                {
                    x = min(x, level[i][j]);
                }
                else if(flag2[i][j]==1 and flag[i][j]==1 and level2[i][j]>level[i][j])
                {
                    x = min(x, level[i][j]);
                    //deb(level2[i][j],level[i][j]);
                }
            }
        }



        csi;
        (x!=1<<30)?pf("%d\n", ++x):pf("IMPOSSIBLE\n");
    }
    /* Coding is FUN  */
    ///                                    ENDD
#ifndef ONLINE_JUDGE
    //pf("-------ENDS OF OUTPUT------\n\n");
    //pf("Time Elapsed: %lu\n", (clock()-ooo));
#endif
    return 0;
}



