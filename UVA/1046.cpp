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
class DATA
{
public:
    int time, x, y, k;
    DATA(int a = 0, int b=0, int c=0)
    {
        x = a;
        y = b;
        k = c;
    }
};
int m, n, flag[10][10][10], visit[10][10][10], all, ar[10][10];
unsigned int level[10][10][10], res[10][10];
char in[10][10];
queue <DATA> qu;

bool INV(int x, int y)
{
    return (x<=-1 or y<=-1 or x>=m or y>=n);
}

void BFS(int x, int y)
{
    int u, v, k, l;
    DATA temp;
    CLR1(level);
    while(qu.size()) qu.pop();
    qu.push(DATA(x, y, ar[x][y]+1));
    level[x][y][ar[x][y] + 1] = 1;
    while(qu.size())
    {
        temp = qu.front(); qu.pop();
        u = temp.x;
        v = temp.y;
        k = temp.k;
        l = k - 1;
        if(l==0)
            l = ar[x][y];
        for(int i=0; i<8; i++)
        {
            int px = u+kx[i];
            int py = v+ky[i];
            if(INV(px, py)) continue;
            //deb(u,v,k);
            unsigned int dist = level[u][v][k] + ((k==1)?1:0);
            //deb(dist, level[u][v][k], k);
            if(dist<level[px][py][l])
            {
                level[px][py][l] = dist;
                //deb(px, py, l, dist);
                qu.push(DATA(px, py, l));
            }
        }
    }
    for(int i=0; i<m; i++)
    {
        for( int j=0; j<n; j++)
        {
            if(i==x and j==y)
                continue;
            unsigned int mx = -1;
            for(int p=1; p<10; p++)
            {
                mx = min(mx, level[i][j][p]);
            }
            //deb(i, j, mx);
            if(mx==-1) res[i][j] = -1;
            else if(res[i][j]!=-1) res[i][j]+=mx;
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
    int i, t, j, k, l,  keis=0, c, d, x, y;
    takei(t);
    while(t--)
    {
        takei(m);
        takei(n);
        getchar();
        all = 0;
        CLR(res);
        for(i=0; i<m; i++)
        {
            gets(in[i]);
            for(j=0; j<n; j++)
            {
                if(isdigit(in[i][j]))
                {
                    ar[i][j] = in[i][j]-'0';
                    all++;
                    qu.push(DATA(i, j, ar[i][j]));
                    BFS(i, j);
                }
                //ok
            }
           // puts(in[i]);
        }
        unsigned int c = -1;
        for(i=0; i<m; i++)
        {
            for(j=0; j<n; j++)
            {
               if(res[i][j]==-1) continue;
               c = min(c, res[i][j]);
            }
        }
        csi;
        _(c);
    }
    /* Coding is FUN  */
    ///                                    ENDD
#ifndef ONLINE_JUDGE
    //pf("-------ENDS OF OUTPUT------\n\n");
    //pf("Time Elapsed: %lu\n", (clock()-ooo));
#endif
    return 0;
}


