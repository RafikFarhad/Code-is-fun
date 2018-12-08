/*De La Grandi Mephistopheles*/


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
/*****************************************************/
/** Author      : Rafik Farhad                       */
/** Mail        : github.com/RafikFarhad/Code_is_fun */
/** Created on  : 2017-01-21-15.29 _ Saturday      */
/****************************************************/
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
//int SET(int mask, int pos){return mask  singlebar  (1<<pos);}
//bool CHK(int mask, int pos){return (1&(mask>>pos));}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1}; const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define LT (1<<31)-1
#define MX
#define MOD
#define MY INT_MIN
//ll FAST_EXP(ll base, ll power) /*base^power%MOD*/   {ll res=1ll;while(power){if(power&1)res=(res*base)%MOD;base=(base*base)%MOD;power>>=1;}return res%MOD;}
vector <int> mat[505];
int match[505], n;
bool  flag[505];
bool DFS(int x)
{
    int i, j, k;
    for(i=0; i<mat[x].size(); i++)
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

int BPM()
{
    CLR1(match);
    int a = 0;
    for(int i=0; i<n; i++)
    {
        CLR(flag);
        if(DFS(i))
            a++;
    }
    return a;
}
int main()
{
    //ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    //freopen("C:/Users/RafikFarhad/Desktop/000.txt","r",stdin);
    freopen("/home/rafikfarhad/Desktop/000.txt","r",stdin);
    //freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
    //clock_t ooo = clock();
#endif
    ///                                    MAIN
    int i, t, j, k, l,  keis(0), c, d, x, y, a, b;
//    char pp[100];
//    fgets(pp, 100, stdin);
    char lc, dc;
    int like[505], dlike[505];
    while(sf("%d %d %d", &c, &d, &n)!=EOF)
    {
        getchar();
        for(i=0; i<n; i++)
        {
            mat[i].clear();
        }
        for(i=0; i<n; i++)
        {
            sf("%c%d %c%d", &lc, &a, &dc, &b);
            getchar();
            //pf("%c%d %c%d\n", lc, a, dc, b);
            if(lc=='D')
                a+=105;
            if(dc=='D')
                b+=105;
            like[i] = a;
            dlike[i] = b;
        }
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                if(i==j)
                    continue;
                if(like[i]==dlike[j])
                {
                    mat[i].pb(j);
                    mat[j].pb(i);
                }
                if(like[j]==dlike[i])
                {
                    mat[i].pb(j);
                    mat[j].pb(i);
                }
            }
        }
        __(n-BPM()/2);

    }
    /* Coding is FUN  */
    ///                                    ENDD
#ifndef ONLINE_JUDGE
    //pf("-------ENDS OF OUTPUT------\n\n");
    //pf("Time Elapsed: %lu\n", (clock()-ooo));
#endif
    return 0;
}
