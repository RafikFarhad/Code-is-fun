
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
#define LT (1<<31)-1
#define MX
#define MOD
#define MY INT_MIN
//ll FAST_EXP(ll base, ll power) /*base^power%MOD*/   {ll res=1ll;while(power){if(power&1)res=(res*base)%MOD;base=(base*base)%MOD;power>>=1;}return res%MOD;}
class DATA
{
public:
    ll tot, a, b, sa, sb;
    DATA(ll _tot=0, ll _a=0, ll _b=0, ll _sa=0, ll _sb=0)
    {
        tot = _tot;
        a = _a;
        b = _b;
        sa = _sa;
        sb = _sb;
    }
    bool operator < (const DATA &a) const
    {
        return tot<a.tot;
    }
protected:
private:
};

int n, s=0;
DATA tot[100005];
pair < ll, int> my[100005];
pair < ll, int> tmp[100005];
pair < pair<int, int>, int> in[100005];

bool COMPA(const pair < pair<int, int>, int> &a, const pair < pair<int, int>, int> &b)
{
    if(a.xx.xx == b.xx.xx)
        return a.xx.yy>b.xx.yy;
    return a.xx.xx < b.xx.xx;
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
    i;
    takei(n);
    for(i=0; i<n; i++)
    {
        takei(a);
        takei(b);
        in[i] = {{a, b}, i};
    }
    sort(in, in+n, COMPA);
    DATA tt, ans;
    ll tot = 0, var;
    for(i=0; i<n; )
    {
        //deb(in[i].xx.xx, in[i].xx.yy, in[i].yy);
        tot = 0;
        for(j=i, k = 1; j<n and in[i].xx.xx==in[j].xx.xx; j++, k++)
        {
            tot += in[j].xx.yy;
            //deb(k, tot);
            if(my[k-1].xx>0)
            {
                var = tot + my[k-1].xx;
                tt = DATA(var, in[j].xx.xx, my[k-1].yy, k, k-1);
                if(ans<tt)
                {
                    ans = tt;
                }
            }
            if(my[k].xx>0)
            {
                var = tot + my[k].xx;
                tt = DATA(var, in[j].xx.xx, my[k].yy, k, k);
                //deb(tt.tot);
                if(ans<tt)
                {
                    ans = tt;
                }
            }
            if(my[k+1].xx>0)
            {
                var = tot + my[k+1].xx;
                tt = DATA(var, in[j].xx.xx, my[k+1].yy, k, k+1);
                if(ans<tt)
                {
                    ans = tt;
                }
            }
            tmp[k] = {tot, in[i].xx.xx};
        }
        for(j=i, k = 1; j<n and in[i].xx.xx==in[j].xx.xx; j++, k++)
        {
            my[k] = max(my[k], tmp[k]);
            //deb(my[k].xx, my[k].yy);
        }
        i = j;
    }
    //deb(ans.tot, ans.a, ans.b);
    //deb(ans.sa, ans.sb);
    __(ans.tot);
    __(ans.sa+ans.sb);
    vector <int> pp, qq, rr(ans.sa+ans.sb);
    for(i=0, j=0; j<ans.sa; i++)
    {
        if(in[i].xx.xx == ans.a)
        {
            j++;
            pp.pb(in[i].yy);
        }
    }
    for(i=0, j = 0; j<ans.sb; i++)
    {
        if(in[i].xx.xx == ans.b)
        {
            qq.pb(in[i].yy);
            j++;
        }
    }
    if(ans.sa>ans.sb)
    {
        for(i=0, j=0; j<ans.sa; i+=2, j++)
            rr[i] = pp[j];
        for(i=1, j=0; j<ans.sb; i+=2, j++)
            rr[i] = qq[j];
    }
    else
    {
        for(i=0, j=0; j<ans.sb; i+=2, j++)
            rr[i] = qq[j];
        for(i=1, j=0; j<ans.sa; i+=2, j++)
            rr[i] = pp[j];
    }
    for(i=0; i<ans.sa+ans.sb; i++)
    {
        if(i)
            pf(" %d", rr[i]+1);
        else
            pf("%d", rr[i]+1);
    }
    NL;



    /* Coding is FUN  */
    ///                                    ENDD
#ifndef ONLINE_JUDGE
    //pf("-------ENDS OF OUTPUT------\n\n");
    //pf("Time Elapsed: %lu\n", (clock()-ooo));
#endif
    return 0;
}


