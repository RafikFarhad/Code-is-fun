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
char mat[100][100];
int n, ghost, man, match[10006], level[100][100], num[100][100], lo, hi, mid;
bool flag[10006], visit[100][100];
vector < pair < pair <int, int> , int> > v;
vector <int> edge[100];
void BFS(int x, int y, int id)
{
    CLR(visit);
    int i, j, k, a, b, c, d;
    queue <int> qu;
    qu.push(x);
    qu.push(y);
    level[x][y] = 0;
    visit[x][y] = 1;
    while(qu.size())
    {
        a = qu.front();
        qu.pop();
        b = qu.front();
        qu.pop();
        for(i=0; i<4; i++)
        {
            c = a + xx[i];
            d = b + yy[i];
            if(c<0 or c>=n or d<0 or d>=n) continue;
            if(mat[c][d]=='#' or visit[c][d]==1) continue;
            visit[c][d] = 1;
            level[c][d] = level[a][b] + 1;
            qu.push(c);
            qu.push(d);
            if(mat[c][d]=='H')
            {
                lo = min(lo, (1+level[c][d])<<1);
                hi = max(hi, (1+level[c][d])<<1);
                v.push_back({{id, num[c][d]}, 2*level[c][d]+2});
            }
        }
    }
}

bool DFS(int x)
{
    int i;
    //deb(x, edge[x].size());
    for(i=0; i<edge[x].size(); i++)
    {
        if(flag[edge[x][i]]) continue;
        flag[edge[x][i]] = 1;
        if(match[edge[x][i]]==-1)
        {
            match[edge[x][i]] = x;
            return true;
        }
        if(DFS(match[edge[x][i]]))
        {
            match[edge[x][i]] = x;
            return true;
        }
    }
    return false;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("000.txt","r",stdin);
#endif
    ///                                    MAIN
    int i, t, j, k, l,  keis=0, a, b, c, d, q, x, y, ans;
    takei(t);
    while(t--)
    {
        takei(n);
        for(i=0; i<n; i++)
            sf("%s", mat[i]);
        CLR(num);
        ghost = 0;
        man = 0;
        v.clear();
        //edge.clear();
        lo = 1<<29;
        hi = -lo;
        for(i=0; i<n; i++)
            for(j=0; j<n; j++)
                if(mat[i][j]=='G') num[i][j] = ++ghost;
                else if(mat[i][j]=='H') num[i][j] = ++man;

        for(i=0; i<n; i++)
            for(j=0; j<n; j++)
                if(mat[i][j]=='G') BFS(i, j, num[i][j]);

        l = v.size();
        for(i=0; i<=ghost; i++) edge[i].clear();
        for(i=0; i<l; i++)
        {
            if(v[i].second<=hi)
            {
                edge[v[i].first.first].pb(v[i].first.second);
            }
        }
        CLR1(match);
        ans = 0;
        for(i=1; i<=ghost; i++)
        {
            CLR(flag);
            if(DFS(i))
                ans++;
        }
        csi;
        if(man!=ans)
        {
            puts("Vuter Dol Kupokat");
            continue;
        }
        b = hi;

        while(lo<hi)
        {
            mid = (lo+hi)>>1;
            for(i=0; i<=ghost; i++) edge[i].clear();
            for(i=0; i<l; i++)
            {
                if(v[i].second<=mid)
                    edge[v[i].first.first].pb(v[i].first.second);
            }
            CLR1(match);
            ans = 0;
            for(i=1; i<=ghost; i++)
            {
                CLR(flag);
                if(DFS(i))
                    ans++;
            }
            if(ans==man)
            {
                hi = mid;
                b = mid;
            }
            else
            {
                lo = mid+1;
            }
        }
        _(b);

    }
    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}




