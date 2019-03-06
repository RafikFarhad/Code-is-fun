
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
/*****************************************************/
/** Author      : Rafik Farhad                       */
/** Mail        : github.com/RafikFarhad/Code_is_fun */
/** Created on  : 2017-01-19-14.27 _ Thursday       */
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
#define MOD 320
#define MY INT_MIN
//ll FAST_EXP(ll base, ll power) /*base^power%MOD*/   {ll res=1ll;while(power){if(power&1)res=(res*base)%MOD;base=(base*base)%MOD;power>>=1;}return res%MOD;}
class DATA
{
public:
    int l, r, id;

    bool operator < (const DATA &a) const
    {
        if(l/MOD==a.l/MOD)
            return r < a.r;
        return l/MOD < a.l/MOD;
    }
};
DATA query[100000];
int freq[250000], ar[100005], n, q, ans[100005], mm[100005];


int main()
{
    //ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("/home/looser/Desktop/000.txt","r",stdin);
    //freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
    //clock_t ooo = clock();
#endif
    ///                                    MAIN
    int i, t, j, k, l,  keis(0), c, d, x, y, a, b;
//    char pp[100];
//    fgets(pp, 100, stdin);
   // double ans = 0.0;

    while(takei(n)==1 and n)
    {
        takei(q);
        for(i=1; i<=n; i++)
        {
            takei(ar[i]);
            ar[i]+=100001;
        }
        for(i=0; i<q; i++)
        {
            takei(query[i].l);
            takei(query[i].r);
            query[i].id = i;
        }
        sort(query, query+q);
        CLR(freq);
        CLR(mm);
        i = 0;
        j = 1;
        mm[0] = n;
        int tot = 0, smax = 0;
        for(k=0; k<q; k++)
        {
            x = query[k].l;
            y = query[k].r;
            t =  query[k].id;
            while(j<=y)
            {
                freq[ar[j]]++;
                mm[freq[ar[j]]]++;
                mm[freq[ar[j]]-1]--;
                if(freq[ar[j]]>tot)
                {
                    tot = freq[ar[j]];
                    smax = tot;
                }
                else if(freq[ar[j]] == tot)
                {
                    smax = tot;
                }

                if(j+1>y)
                    break;
                j++;
            }
            while(j>y)
            {
                freq[ar[j]]--;
                mm[freq[ar[j]]+1]--;
                mm[freq[ar[j]]]++;
                if(tot==freq[ar[j]]+1)
                    tot = smax;
                else tot = max(tot, freq[ar[j]]);
                j--;
            }
            while(i>=x)
            {
                freq[ar[i]]++;
                mm[freq[ar[i]]]++;
                mm[freq[ar[i]]-1]--;
                 if(freq[ar[j]]>tot)
                {
                    tot = freq[ar[j]];
                    smax = tot;
                }
                else if(freq[ar[j]] == tot)
                {
                    smax = tot;
                }
                if(i-1<x)
                    break;
                i--;
            }
            //deb("*", i, x);
            while(i<x)
            {
                //deb(ar[i], freq[ar[i]], mm[freq[ar[i]]]--);
                freq[ar[i]]--;
                mm[freq[ar[i]]+1]--;
                mm[freq[ar[i]]]++;
                if(tot==freq[ar[i]]+1)
                    tot = smax;
                else
                {
                    tot = max(tot, freq[ar[j]]);
                }
                //deb(tot);
                i++;
            }
            //deb(x, y, tot);
            ////deb(i, j);
            j++;
            i--;
            ans[t] = tot;
        }
        for(i=0; i<q; i++)
        {
            pf("%d\n", ans[i]);
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



