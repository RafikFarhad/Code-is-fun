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
template <class T> T MAX(T a, T b) { return a>b?a:b;}template <class T> T MIN(T a, T b) { return a<b?a:b;}
template <class T1> void __(T1 p) { cout << p << endl;}
template <class T1> void deb(T1 p) { cout << "Debugging: " << p << endl;}
template <class T1, class T2> void deb(T1 p, T2 q) { cout << "Debugging: " << p << "\t" << q  << endl;}
template <class T1, class T2, class T3> void deb(T1 p, T2 q, T3 r) { cout << "Debugging: " << p << "\t " << q << "\t " << r << endl;}
template <class T1, class T2, class T3, class T4> void deb(T1 p, T2 q, T3 r, T4 s) { cout << "Debugging: " << p << "\t " << q << "\t " << r << "\t " << s << endl;}
long long int POOW(long long b, long long p) { if(p==0) return 1; return b*POOW(b, p-1);}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1}; const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define SIZE INT_MAX
int n, m, match[500];
bool flag[500], have[500];
vector <int> mat[400];

int TO_LINIER(int i, int j)
{
    return i*m+j;
}

bool DFS(int x)
{
    int i, j, k;
    for(i=0; i<mat[x].size();i++)
    {
        if(flag[mat[x][i]]==0)
        {
            flag[mat[x][i]] = 1;
            if(match[mat[x][i]]==-1)
            {
                match[mat[x][i]] = x;
                return true;
            }
            if(DFS(match[mat[x][i]]))
            {
                match[mat[x][i]] = x;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    //ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int i, t, j, k, l,  keis=0, a, b, c, d;
    char pp[40][25];
    takei(t);
    while(t--)
    {
        takei(n);
        takei(m);
        getchar();
        //getchar();
        for(i=0; i<n; i++)
        {
            gets(pp[i]);
           // puts(pp[i]);
        }
        for(i=0; i<=n*m; i++)
            mat[i].clear();
        d = 0;
        CLR(have);
        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                if(pp[i][j]=='*')
                {
                    a = TO_LINIER(i, j);
                    have[a] = 1;
                    d++;
                    if(j and pp[i][j-1]=='*')
                    {
                        mat[a].pb(TO_LINIER(i, j-1));
                    }
                    if(j+1!=m and pp[i][j+1]=='*')
                    {
                        mat[a].pb(TO_LINIER(i, j+1));
                    }

                    if(i and pp[i-1][j]=='*')
                    {
                        mat[a].pb(TO_LINIER(i-1, j));
                    }
                    if(i+1!=n and pp[i+1][j]=='*')
                    {
                        mat[a].pb(TO_LINIER(i+1, j));
                    }
                }
            }
        }
        CLR1(match);
        a = 0;
        for(i=0; i<n*m; i++)
        {
            CLR(flag);
            if(have[i] and DFS(i))
                a++;
        }
        //deb(a, d);
        pf("%d\n", d-a/2);
    }
    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}



