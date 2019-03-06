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
ll dp[100005][10], n, ar[100005], rett, ans;

ll GO(int pos=0, int st=0, ll sum = 0ll)
{
    if(pos==n)
    {
        return sum;
    }
    ll &ret = dp[pos][st];
    if(~ret) return ret;
    ret = -(1ll<<62);
    if(st==0)
    {
        //deb(sum, ar[pos]);
        if(sum+ar[pos]<0)
        {
            ret = max(ret, GO(pos+1, 0, 0));
        }
        else if(ar[pos]<0)
        {
            ret = max(ret, GO(pos+1, 1, sum));
            ret = max(ret, GO(pos+1, 0, sum+ar[pos]));
        }
        else
        {
            ret = max(ret, GO(pos+1, 0, sum+ar[pos]));
        }
        //if(sum + ar[pos]<0)
            //ret = max(ret, GO(pos+1, 0, 0));

    }
    /*else if(sum+ar[pos]<0)
        ret = max(ret, GO(pos+1, st, 0));*/
    else
        ret = GO(pos+1, 1, sum+ar[pos]);
    return ret;
}

int main()
{
    //ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int i, t, j, k, l,  keis=0, a, b, c, d, x, y;
    takei(t);
    while(t--)
    {
        takell(n);
        for(i=0; i<n; i++)
            takell(ar[i]);
        //ll ans = 0, ret = 0;;
        /*ans = 0;
        rett = 0;
        for(i=0; i<n; i++)
        {
            if(ar[i]+ans<0)
                ans = 0;
            else{
                ans = ans+ar[i];
                rett = max(rett, ans);
            }
        }
        deb(rett);*/
        CLR1(dp);
        ans = GO(0, 0, 0);
        if(ans==0)
        {
            ans = ar[0];
            for(i=0; i<n; i++)
                ans = max(ans, ar[i]);
        }
        cout << ans << endl;
    }
    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}



