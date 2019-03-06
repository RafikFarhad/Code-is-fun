
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
#define MX 12158598919ll
#define MOD
#define MY INT_MIN
//ll FAST_EXP(ll base, ll power) /*base^power%MOD*/   {ll res=1ll;while(power){if(power&1)res=(res*base)%MOD;base=(base*base)%MOD;power>>=1;}return res%MOD;}
#define MAX 1000005
int phi[MAX];
ll sum[1000005];
void calculatePhi()
{
    int i, j;
    for (i = 1; i < MAX; i++)
    {
        phi[i] = i;
    }
    for (i = 2; i < MAX; i++)
    {
        if (phi[i] == i)
        {
            for (j = i; j < MAX; j += i)
            {
                phi[j] -= phi[j] / i;
            }
        }
    }
    return;
}

int COW(int a, int b)
{
    int i, j=0;
    for(i=1; i<=a; i++)
    {
        if(__gcd(a, i)==1) j++;
        if(j==b) return i;
    }

}

int main()
{
    //ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    //freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
    //clock_t ooo = clock();
#endif
    ///                                    MAIN
    int i, t, j, k, l,  keis(0); ll c, d, x, y, a, b;
//    char pp[100];
//    fgets(pp, 100, stdin);
    calculatePhi();
    sum[1] = 1;
    for(i=2; i<300005; i++)
    {
        sum[i] = sum[i-1]+phi[i];
        //if(sum[i]>22158598919ll) break;
        //deb(i, sum[i]);
    }
    //deb(i, sum[i-1]-MX);


//    for(k=1; k<100; k++)
//    {
//        //deb(k);
//        a = k;
//        if(a==1)
//        {
//            puts("0/1");
//            continue;
//        }
//        a--;
//        //deb(a);
//        for(i=1; a>sum[i] ; i++)
//        {
//           ;// deb(a, sum[i]);
//        }
//        l = a-sum[i-1];
//        //deb(a, sum[i-1], l);
//        //deb(l, phi[200000]);
//        if(i<=l) deb(i, l, k);;
//
//
//        //pf("%d/%d\n", COW(i, l), i);
//    }

    while(sf("%lld", &a) and a)
    {
        if(a==1)
        {
            puts("0/1");
            continue;
        }
        if(a==2)
        {
            puts("1/1");
            continue;
        }

        a--;
        //deb(a);
        for(i=1; a>sum[i] ; i++)
        {
           ;// deb(a, sum[i]);
        }
        l = a-sum[i-1];
        //deb(a, sum[i-1], l);
        //deb(l, phi[200000]);


        pf("%d/%d\n", COW(i, l), i);
    }

    /* Coding is FUN  */
    ///                                    ENDD
#ifndef ONLINE_JUDGE
    //pf("-------ENDS OF OUTPUT------\n\n");
    //pf("Time Elapsed: %lu\n", (clock()-ooo));
#endif
    return 0;
}


