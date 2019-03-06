/**         HODOR          **/



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
//#define mp                                      make_pair
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
//int SET(int mask, int pos){return mask singlebar (1<<pos);}
//bool CHK(int mask, int pos){return (1&(mask>>pos));}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1}; const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define LT (1<<31)-1
#define MX
#define MOD
#define MY INT_MIN
//ll FAST_EXP(ll base, ll power) /*base^power%MOD*/   {ll res=1ll;while(power){if(power&1)res=(res*base)%MOD;base=(base*base)%MOD;power>>=1;}return res%MOD;}
vector <int> v[55];
int in[55] = {0}, n, m, k = 0;
vector <pair <int, int> > ans, tt;

int DFS(int x, int prev = -1)
{
//    deb(x, prev);
    if(v[x].size()==0) return 0;
    for(int i=0; i<v[x].size(); i++)
    {
        //deb(i, v[x][i]);
        if(v[x][i]==prev) continue;
        if(in[v[x][i]]!=2) return v[x][i];
        return DFS(v[x][i], x);
    }
    return 0;
}


int main()
{
    //ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
    //clock_t ooo = clock();
#endif
    ///                                    MAIN
    int i, t, j, l,  keis(0), c, d, x, y, a, b;
//    char pp[100];
//    fgets(pp, 100, stdin);
    map <pair<int, int>, int> mp;
    takei(n);
    takei(m);
    for(i=0; i<m; i++)
    {
        takei(a);
        takei(b);
        v[a].pb(b);
        v[b].pb(a);
        in[a]++;
        in[b]++;
        if(in[a]>2 or (a==b) and n!=1)
        {
            puts("NO");
            return 0;
        }
        if(in[b]>2)
        {
            puts("NO");
            return 0;
        }

    }
    k = 0;

    for(i=1; i<=n; i++)
    {
        while(in[i]<2)
        {
            in[i]++;
            t = DFS(i);
            if(t==0)
            {
                for(j=1; j<=n; j++)
                    if(in[j]==0)
                {
                    t = j;
                    break;
                }
            }
            if(t==0)
            {
                for(j=1; j<=n; j++)
                    if(in[j]==1)
                {
                    t = j;
                    break;
                }
            }
            if(i==t and n!=1)
            {
                i = n+1;
                k = 1;
                break;
            }
            v[t].pb(i);
            v[i].pb(t);
            in[t]++;
            ans.pb({i,t});
        }
    }
    if(k)
    {
//        if(n==1)
//        {
//            if(m!=0) puts("YES\n0\n");
//            else puts("YES\n1\n1 1\n");
//            return 0;
//        }
        puts("NO");
    }
    else
    {
        puts("YES");
        __(ans.size());
        for(i=0; i<ans.size(); i++)
        {
            tt.pb({min(ans[i].xx, ans[i].yy), max(ans[i].xx, ans[i].yy)});
            //tt.pb(ans[i]);
        }
        sort(all(tt));
        for(i=0; i<ans.size(); i++)
        {
            pf("%d %d\n", min(tt[i].xx, tt[i].yy), max(tt[i].xx, tt[i].yy));
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



