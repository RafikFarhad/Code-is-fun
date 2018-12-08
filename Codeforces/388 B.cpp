
/*Winter is coming*/


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
//int SET(int mask, int pos){return mask  singlebar  (1<<pos);}
//bool CHK(int mask, int pos){return (1&(mask>>pos));}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1}; const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define LT (1<<31)-1
#define MX
#define MOD
#define MY INT_MIN
//ll FAST_EXP(ll base, ll power) /*base^power%MOD*/   {ll res=1ll;while(power){if(power&1)res=(res*base)%MOD;base=(base*base)%MOD;power>>=1;}return res%MOD;}
ll DIST(int a, int b, int c, int d)
{
    return (a-c)*1ll*(a-c)+(b-d)*1ll*(b-d);
}
vector <pair<int, int> > ans;
pair<int, int> GO(int x1, int y1, int x2, int y2, int x3, int y3)
{
    int i, j;
    int a, b, c, d;
    for(i=-3000; i<=3000; i++)
    {
        for(j=-3000; j<=3000; j++)
        {
            a = x3 - i;
            b = y3-j;
            c = x1-x2;
            d = y1-y2;
            if(b==0 and d==0 and DIST(x1, y1, x2, y2)==DIST(x3, y3, i, j))
            {
                ans.pb({i, j});
            }
            if(b==0 or d==0) continue;
            if(a*d==b*c and DIST(x1, y1, x2, y2)==DIST(x3, y3, i, j))
            {
                ans.pb({i, j});
            }
        }
    }
    return {1<<30, 1<<30};
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
    int i, t, j, k, l,  keis(0), c, d, x, y, a, b;
//    char pp[100];
//    fgets(pp, 100, stdin);

    int x1, y1, x2, y2, x3, y3;
    while(cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3)
    {
        ans.clear();
        GO( x1, y1, x2, y2, x3, y3);
        GO( x1, y1, x3, y3, x2, y2);
        GO( x3, y3, x2, y2, x1, y1);
        sort(all(ans));
        k = 0;
        for(i=0; i<ans.size(); i++)
        {
            if(!i)
            {
                k++;
            }
            else if(ans[i].xx!=ans[i-1].xx or ans[i].yy!=ans[i-1].yy)
            {
                k++;
            }
        }
        __(k);
        for(i=0; i<ans.size(); i++)
        {
            if(!i)
            {
                pf("%d %d\n", ans[i].xx, ans[i].yy);
            }
            else if(ans[i].xx!=ans[i-1].xx or ans[i].yy!=ans[i-1].yy)
            {
                pf("%d %d\n", ans[i].xx, ans[i].yy);
            }
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


