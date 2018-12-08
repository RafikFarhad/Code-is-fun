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
/** Created on  : 2017-01-21-16.26 _ Saturday      */
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
#define llu                                     unsigned long long
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
long long unsigned POOW(long long unsigned b, int p) { if(p==0) return 1llu; return b*POOW(b, p-1);}
//int SET(int mask, int pos){return mask  singlebar  (1<<pos);}
bool CHK(int mask, int pos){return (1&(mask>>pos));}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1}; const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define LT (1<<31)-1
#define MX 41000
#define MOD
#define MY INT_MIN
//ll FAST_EXP(ll base, ll power) /*base^power%MOD*/   {ll res=1ll;while(power){if(power&1)res=(res*base)%MOD;base=(base*base)%MOD;power>>=1;}return res%MOD;}
vector <llu> my;
int t2[MX], t3[MX], t5[MX];
void DONE()
{
    int i, j, k = 1;
    my.pb(0llu);
    my.pb(1llu);
    llu a = 1llu;
    for(i=2; i<50000 ; i++)
    {
        a = 0llu;
        for(j=0; j<31; j++)
        {
            if(CHK(i, j))
            {
                a+=POOW(26llu, j);
                //deb(i, j, POOW(26llu, j));
            }
        }
        //deb(a);
        if(a<my[k]) continue;
        k++;
        my.pb(a);
    }
    k = my.size();
    CLR(t2);
    CLR(t3);
    CLR(t5);
    for(i=1; i<k; i++)
    {
        a = my[i];
        while(a%2==0)
        {
            a/=2;
            t2[i]++;
        }
        while(a%3==0)
        {
            a/=3;
            t3[i]++;
        }
        while(a%5==0)
        {
            a/=5;
            t5[i]++;
        }
    }
    return;
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
    llu p;
    DONE();
    k = my.size();
    a = b= c =0;
    for(i=0; i<k; i++)
    {
        a = max(a, t2[i]);
        b = max(a, t3[i]);
        c = max(a, t5[i]);
    }
    //deb(a, b, c);
    while(sf("%d %d %d %llu", &a, &b, &c, &p)!=EOF)
    {
        csi;
        for(i=0; i<k; i++)
        {
            if(t2[i]>=a and t3[i]>=b and t5[i]>=c and p<my[i])
            {
                string aa;
                p = my[i];
                while(p)
                {
                    aa += (char) (p%26 + '0');
                    //deb(p%26, p);
                    p/=26;
                }
                reverse(all(aa));
                __(aa);
                break;
            }
        }
        if(i==k)
        {
            puts("No Solution");
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
