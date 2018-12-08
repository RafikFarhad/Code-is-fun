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
//int SET(int mask, int pos){return mask(1<<pos);}
bool CHK(int mask, int pos){return (1&(mask>>pos));}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1}; const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define LT (1<<31)-1
#define MX
#define MOD
#define MY INT_MIN
//ll FAST_EXP(ll base, ll power) /*base^power%MOD*/   {ll res=1ll;while(power){if(power&1)res=(res*base)%MOD;base=(base*base)%MOD;power>>=1;}return res%MOD;}
int prime[100005], ison[100005], safe[100005], sob[10000], tot=0;
set <int> ss[100005];

#define SIZE 100005
void SEIEVE()
{
    long long unsigned i, j, lim = sqrt(100001+100);
    for(i=2; i<=lim ; i++)
    {
        if(prime[i]==0)
        {
            for(j=i*i; j<SIZE; j+=i)
            {
                prime[j] = 1;
            }
        }
    }
    return;
}

int OKAY(int val)
{
    int i, j;
    for(i=0; i<tot; i++)
    {
        if(val%sob[i]==0)
        {
            if(safe[sob[i]]) return sob[i];
            while(val%sob[i]==0)
                val/=sob[i];
        }
    }
    if(val!=1)
    {
        if(safe[val]) return val;
    }
    return 0;
}
void UPDATE(int val)
{
    int i, j, a = val;
    for(i=0; i<tot; i++)
    {
        if(val%sob[i]==0)
        {
            safe[sob[i]]++;
            ss[sob[i]].insert(a);
            while(val%sob[i]==0)
                val/=sob[i];
        }
    }
    if(val!=1)
    {
        safe[val]++;
        ss[val].insert(a);
    }
}
void NEG_UPDATE(int val)
{
    int i, j, a = val;;
    for(i=0; i<tot; i++)
    {
        if(val%sob[i]==0)
        {
            if(safe[sob[i]]) safe[sob[i]]--;
            ss[sob[i]].erase(a);

            while(val%sob[i]==0)
                val/=sob[i];
        }
    }
    if(val!=1)
    {
        if(safe[val]) safe[val]--;
        ss[val].erase(a);
    }
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
    int i, t, j, k, l,  keis(0), c, d, x, y, a, b, n, m;
    char sign;
    set <int> my;
    SEIEVE();
    prime[1] = 1;
    for(i = 1; i<sqrt(100001+100); i++)
    {
        if(prime[i]==0)
            sob[tot++] = i;
    }
    //deb(sob[tot-1]);
    takei(n);
    takei(m);
    CLR(ison);
    CLR(safe);
    while(m--)
    {
        sf(" %c %d", &sign, &a);
        //pf("%c %5d   ", sign, a);
        if(sign=='+')
        {
            if(ison[a])
            {
                puts("Already on");
                continue;
            }
            b = OKAY(a);
            if(b==0)
            {
                ison[a] = 1;
                my.insert(a);
                UPDATE(a);
                puts("Success");
            }
            else
            {
                pf("Conflict with ");
                for(auto uu: ss[b])
                {
                    _(uu);
                    break;

                }
            }

        }
        else
        {
            if(!ison[a])
            {
                puts("Already off");
                continue;
            }
            NEG_UPDATE(a);
            ison[a] = 0;
            my.erase(a);
            puts("Success");
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



