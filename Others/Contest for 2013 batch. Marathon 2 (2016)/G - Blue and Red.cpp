/// Olee vai josh

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

vector <int> matA[205], matB[205];
int n, match[205], ar[205];
bool flag[205], baad[205];

bool DFS(int x)
{
    int i;
    for(i=0; i<matA[x].size(); i++)
    {
        if(flag[matA[x][i]]==0 and baad[matA[x][i]]==0)
        {
            flag[matA[x][i]] = 1;
            if(match[matA[x][i]]==-1)
            {
                match[matA[x][i]] = x;
                return true;
            }
            if(DFS(match[matA[x][i]]))
            {
                match[matA[x][i]] = x;
                return true;
            }

        }
    }
    return false;
}

int BPM()
{
    CLR1(match);
    int i, j, ans=0;
    for(i=0; i<n; i++)
    {
        CLR(flag);
        if(!baad[i] and ar[i]==0 and DFS(i))
            ans++;
    }
    return ans;
}

int main()
{
    //ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int i, t, j, k, l,  keis=0, a, b, c, d,  m;
    takei(t);
    while(t--)
    {
        takei(n);
        takei(m);
        for(i=0; i<n; i++)
        {
            takei(ar[i]);
            matA[i].clear();
            matB[i].clear();
        }
        while(m--)
        {
            takei(a);
            takei(b);
            if(ar[a]==ar[b]) continue;
            if(ar[a]==0)
            {
                matA[a].pb(b);
                matB[b].pb(a);
            }
            else
            {
                matA[b].pb(a);
                matB[a].pb(b);
            }
        }
        CLR(baad);
        CLR1(match);
        a = BPM();
       // deb(a);
        vector <int> res;
        for(i=0; i<n; i++)
        {
            baad[i] = 1;
            b = BPM();
            if(b<a)
            {
                res.pb(i);
                a = b;
            }
            else
                baad[i] = 0;
        }
       // deb(b);
        pf("%d", (int)res.size());
        for( i=0; i<res.size(); i++)
            pf(" %d", res[i]);
        NL;

    }
    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}



