#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
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
#define _(o)                                    pf("%d", o)

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
vector <int> v[100005];
int n, m, dp[100005], path[100005];
bool flag[100005];
vector < pair <int, int> >ans;

pair <int, int> GO(int x)
{
    //if(dp[x]!=-1) return dp[x];
    if(flag[x]) return {0,0};
    flag[x] = 1;
    int i, ans = 0;
    pair <int, int> p, q;

    for(i=0; i<v[x].size(); i++)
    {
        if(v[x][i]>x)
        {
            p = GO(v[x][i]);
            ans++;
            if(p>q)
            {
                q = p;
            }
        }
    }
    q.first++;
    deb("*", x, ans);
    if(ans and v[x].size()) q.second += v[x].size()-2;
    else q.second += v[x].size();
    return q;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int i, j, k, l, a, b, c;
    while(cin >> n >> m)
    {
        for(i=0; i<=n; i++)
        {
            v[i].clear();
            flag[i] = 0;
        }
        while(m--)
        {
            takei(a);
            takei(b);
            v[a].pb(b);
            v[b].pb(a);
        }

        for(i=1; i<=n; i++)
        {
           if(flag[i]==0)
           {
               ans.pb(GO(i));
           }
        }
        j = 0;
        k = 0;

        for(i=0; i<ans.size(); i++)
        {
            deb(ans[i].first);
           if(ans[i].first>j)
           {

               j = ans[i].first;
               k = max(k, i);
           }
        }
        deb(k);
    }
    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}



