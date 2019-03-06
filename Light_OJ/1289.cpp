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
#define SIZE 100000008
int flag[(int)(SIZE)/32+100], cow;
int prime[5761456+5];
void SEIEVE()
{
    int i, j, l = sqrt(SIZE);
    for(i=3; i<=l; i+=2)
    {
        if(!(flag[i/32]&(1<<(i%32))))
        {
            for(j=i*i; j<SIZE; j+=2*i)
            {
                flag[j/32]|=(1<<(j%32));
            }
        }
    }
    cow = 0;
    prime[cow++] = 2;
    for(i=3; i<SIZE; i+=2)
    {
        //if(!(flag[i/32]&(1<<(i%32))) and i<100) deb(i);
        if(!(flag[i/32]&(1<<(i%32))))
            prime[cow++] = i;
    }

    //cow = prime.size();
    //deb(prime.size());

    return;
}

unsigned int dp[5761456+5], ans;

void GO()
{
    dp[0] = 2;
    int i;
    for(i=1; i<cow; i++)
        dp[i] = prime[i]*dp[i-1];
    //ok;
    return;
}

unsigned int OKA(int a)
{
    int i, j, k;
    unsigned int anu = 1;
    for(i=0; prime[i]*prime[i]<=a; i++)
    {
        k = a/prime[i];
        while(k>=prime[i])
        {
            anu*=prime[i];
            k/=prime[i];
        }
    }
    return anu;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int i, j, k, l, t, keis=0;
    SEIEVE();
    GO();
    takei(t);
    while(t--)
    {
        takei(k);
        ans = OKA(k);
        l = upper_bound(prime, prime+cow, k) - prime -1;
        //deb(l, ans, dp[l]);
        ans*=dp[l];
        csi;
        pf("%u\n", ans);

    }
    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}


