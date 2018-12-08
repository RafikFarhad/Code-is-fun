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
long long int POOW(long long b, long long p) { if(p==0) return 1; return b*POOW(b, p-1);}
int SET(int mask, int pos){return mask|(1<<pos);}
bool CHK(int mask, int pos){return (1&(mask>>pos));}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1}; const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define LT (1<<31)-1
#define MX
#define MOD
#define MY INT_MIN
//ll FAST_EXP(ll base, ll power) /*base^power%MOD*/   {ll res=1ll;while(power){if(power&1)res=(res*base)%MOD;base=(base*base)%MOD;power>>=1;}return res%MOD;}
ull fact[25];
char in[25];
int l;
llu aa;
bool fre[25];
map <char, int> mymap;
map <char, int> :: iterator it, i;
void COUNT_FREE()
{
    int a = 0, i, ar[27];
    CLR(ar);
    for(i=0; i<l; i++)
    {
        mymap[in[i]]++;
    }
    return;
}

llu nPr()    /// Return nPr
{
    llu a = 0, b = 1llu;
    for(it=mymap.begin(); it!=mymap.end(); it++)
    {
        a+=it->yy;
        if(it->yy) b = b*fact[it->yy];
        //deb(it->yy, it->xx);
    }
   // deb(fact[a], b);
    return fact[a]/b;
}

void PRINT(int pos, llu have)
{
    if(have==1 or pos==l-1)
    {
        for(i=mymap.begin(); i!=mymap.end(); i++)
            while(i->yy)
            {
                pf("%c", i->xx);
                i->yy--;
            }
        return;
    }
    ull c = 0, d;
    for(i=mymap.begin(); i!=mymap.end(); i++)
    {
        if(i->yy==0) continue;
        i->yy--;
        d = nPr();
        c+=d;
        if(c>=have)
        {
            c-=d;
            break;
        }
        i->yy++;
    }
    pf("%c", i->xx);
    PRINT(pos+1, have-c);
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
    //clock_t ooo = clock();
#endif
    ///                                    MAIN
    int i, t, j, k,  keis(0),  x, y, a, b;
    llu c, d;
//    char pp[100];
//    fgets(pp, 100, stdin);
    fact[0] = 1llu;
    for(i=1; i<21; i++)
    {
        fact[i] = fact[i-1]*i;
        //deb(i, fact[i]);
    }
    takei(t);
    while(t--)
    {
        sf("%s %llu", in, &aa);
        l = strlen(in);
        sort(in, in+l);
        CLR(fre);
        mymap.clear();
        COUNT_FREE();
        c = nPr();
        //deb(c);
        csi;
        if(aa>c)
        {
            puts("Impossible");
            continue;
        }
        else
        {
            //pf("%llu ", aa);
            PRINT(0, aa);
            NL;
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



