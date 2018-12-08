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
#define csll                                    pf("Case %lld: ", ++keis)
#define _(o)                                    pf("%d\n", o)
#define ll                                      long long
#define ull                                     unsigned long long
#define exx                                     2.7182818284590452353602875

///Helper
using namespace std;
template <class T> T MAX(T a, T b)
{
    return a>b?a:b;
}
template <class T> T MIN(T a, T b)
{
    return a<b?a:b;
}
template <class T1> void __(T1 p)
{
    cout << p << endl;
}
template <class T1> void deb(T1 p)
{
    cout << "Debugging: " << p << endl;
}
template <class T1, class T2> void deb(T1 p, T2 q)
{
    cout << "Debugging: " << p << "\t" << q  << endl;
}
template <class T1, class T2, class T3> void deb(T1 p, T2 q, T3 r)
{
    cout << "Debugging: " << p << "\t " << q << "\t " << r << endl;
}
template <class T1, class T2, class T3, class T4> void deb(T1 p, T2 q, T3 r, T4 s)
{
    cout << "Debugging: " << p << "\t " << q << "\t " << r << "\t " << s << endl;
}
long long int POOW(long long b, long long p)
{
    if(p==0) return 1;
    return b*POOW(b, p-1);
}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};
const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1};
const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define SIZE INT_MAX
char mat[1005][1005];
int level[2][1005][1005], r, c;
queue <int> qu1, qu2;
void BFS1()
{
    int i, a, b, x, y;
    while(qu1.size())
    {
        a = qu1.front(); qu1.pop();
        b = qu1.front(); qu1.pop();
        for(i=0; i<4; i++)
        {
            x = a+xx[i];
            y = b+yy[i];
            if(x<0 or y<0 or x==r or y==c or level[0][x][y]!= 1000006 or mat[x][y]=='#' or mat[x][y]=='F') continue;
            level[0][x][y] = level[0][a][b] + 1;
            qu1.push(x);
            qu1.push(y);

        }

    }
}
void BFS2()
{
    int i, a, b, x, y;
    while(qu2.size())
    {
        a = qu2.front(); qu2.pop();
        b = qu2.front(); qu2.pop();
        for(i=0; i<4; i++)
        {
            x = a+xx[i];
            y = b+yy[i];
            if(x<0 or y<0 or x==r or y==c or level[1][x][y]!= 1000006 or mat[x][y]=='#' or mat[x][y]=='F') continue;
            level[1][x][y] = level[1][a][b] + 1;
            qu2.push(x);
            qu2.push(y);
        }
    }
}


int main()
{
    //ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int i, t, j, k, l,  keis=0, a, b, d, x, y;
    takei(t);
    while(t--)
    {
        takei(r);
        takei(c);
        //getchar();
        for(i=0; i<r; i++)
            scanf("%s", mat[i]);
        for(i=0; i<r; i++)
            for(j=0; j<c; j++)
                level[0][i][j] = level[1][i][j] = 1000006;
        while(qu1.size()) qu1.pop();
        while(qu2.size()) qu2.pop();
        for(i=0; i<r; i++)
            for(j=0; j<c; j++)
                if(mat[i][j]=='J')
                {
                    qu1.push(i);
                    qu1.push(j);
                    level[0][i][j]=0;
                    i = j = r*c;
                }
        for(i=0; i<r; i++)
            for(j=0; j<c; j++)
                if(mat[i][j]=='F')
                {
                    qu2.push(i);
                    qu2.push(j);
                    level[1][i][j] = 0;
                }
        BFS1();
        BFS2();
        int ans = 1000006;
        for(i=0; i<c; i++)
            for(j=0; j<c; j++)
            {
                if(i==0 or j==0 or i==r-1 or j==c-1)
                {
                    if(level[0][i][j]<level[1][i][j])
                        ans = min(ans, level[0][i][j]);
                }
            }

        if(ans < 1000006)
            pf("%d\n", ans+1);
        else
            pf("IMPOSSIBLE\n");
    }

    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}




