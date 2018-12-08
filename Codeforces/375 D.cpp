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
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1}; const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define MX INT_MAX
#define MOD 1000000007
#define MY INT_MIN



char M[55][55];
bool flag[55][55];
bool flag2[55][55];
int n, m, k;

class DATA
{
public:
    int all, x, y;
    DATA(int _x, int _y, int _all)
    {
        x = _x;
        y = _y;
        all = _all;
    }
    bool operator < (const DATA &a) const
    {
        return all<a.all;
    }
};

bool DFS_FALSE(int x, int y)
{
    if(flag2[x][y])
        return true;
    //deb(x, y);
    flag2[x][y] = 1;
    bool mark = true;
    for(int i=0; i<4 and mark; i++)
    {
        int a = x+xx[i];
        int b = y+yy[i];
        if(a==-1 or b==-1 or a==n or b==m) return false;
        if(flag2[a][b] or M[a][b]=='*') continue;
        mark = mark&DFS_FALSE(a, b);
    }
    return mark;
}

int DFS_COUNT(int x, int y, int change)
{
    if(flag[x][y])
        return 0;
    flag[x][y] = 1;
    if(change) M[x][y] = '*';
    int mark = 1;
    for(int i=0; i<4; i++)
    {
        int a = x+xx[i];
        int b =y+yy[i];
        if(a==-1 or b==-1 or a==n or b==m) continue;
        if(flag[a][b] or M[a][b]=='*') continue;
        mark = mark + DFS_COUNT(a, b, change);
    }
    return mark;
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
    int i, t, j,  l,  keis=0, c, d=0, x, y;
    takei(n);
    takei(m);
    takei(k);
    getchar();
    for(i=0; i<n; i++)
        gets(M[i]);
    CLR(flag2);
    CLR(flag);
    vector <DATA> v;
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            if(flag[i][j]) ;
            else if(M[i][j]=='*') ;
            else
            {
                bool l = DFS_FALSE(i, j);
                if(l)
                {
                    c = DFS_COUNT(i, j, 0);
                    v.pb(DATA(i, j, c));
                }
                else
                {
                    //v.pb(DATA(0 ,0,1<<20));
                    c = DFS_COUNT(i, j, 0);
                    d++;
                }
            }
        }
    }
    sort(all(v));
    //deb(v.size());
    l = v.size()-k;
    c = 0;
    CLR(flag);
    for(i=0; i<l; i++)
    {
        c+=v[i].all;
        DFS_COUNT(v[i].x, v[i].y, 1);
    }
    _(c);
    for(i=0; i<n; i++)
        puts(M[i]);

    /* Coding is FUN  */
    ///                                    ENDD
#ifndef ONLINE_JUDGE
    //pf("-------ENDS OF OUTPUT------\n\n");
    //pf("Time Elapsed: %lu\n", (clock()-ooo));
#endif
    return 0;
}



