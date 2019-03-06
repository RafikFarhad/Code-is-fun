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
#define takei(a)                                 scanf("%d", &a)
#define takell(a)                                scanf("%lld", &a)
#define takellu(a)                               scanf("%llu", &a)
#define sf                                          scanf
#define pb                                         push_back
#define mp                                         make_pair
#define ppp                                       system("pause")
#define ok                                         cout << "OK" <<endl;
#define pf                                         printf
#define NL                                        printf("\n")
#define PI                                         2*acos(0)
#define all(o)                                      o.begin(), o.end()
#define csi                                         pf("Case %d: ", ++keis)
#define csll                                         pf("Case %lld: ", ++keis)

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
#define SIZE 2147483750

typedef long long ll;
ll *p;
vector <long long> prime;
ll ss;

void SEIEVE()
{
    ll i, j, l = sqrt(SIZE)+5;
    p = new ll[l];
    for(i=1; i<=l; i++)
        p[i] = i;
    for(i=2; i<=l; i++)
    {
        if(p[i]==i)
        {
            prime.pb(i);
            for(j=i; j<l; j+=i)
            {
                p[j]-=p[j]/i;
            }
        }
    }
    ss = prime.size();
    //deb(ss, prime[ss-1]);
    return;
    for(i=0; i<35; i++)
        deb(i, prime[i]);
}

ll COUNT_PHI(ll n)
{
    if(n<sqrt(SIZE)) return p[n];
    int i, j, k = n;
    for(i=0; i<ss and n>1; i++)
    {
        if(n%prime[i]==0)
        {
            while(n%prime[i]==0)
                n/=prime[i];
            k-=k/prime[i];
        }
    }
    //deb(n);
    if(n>1) k-=k/n;
    return k;
}

ll COUNT_DIV(ll n)
{
    int i, j, k = 1;
    for(i=0; i<ss and n>1; i++)
    {
        if(n%prime[i]==0)
        {
            j = 0;
            while(n%prime[i]==0)
            {
                n/=prime[i];
                j++;
            }
            k*=(j+1);
            //deb(prime[i], j, k);
        }
    }
    //deb(n);
    if(n>1) k<<=1;
    return k;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    ll n, i, j, k, l, t, keis=0, a, b, c;
    SEIEVE();
    while(sf("%lld", &n)!=EOF)
    {
        a = COUNT_PHI(n);
        b = COUNT_DIV(n);
        //deb(a, b);
        //deb(n, a+b-1);
        pf("%lld\n", n-a-b+1);
    }
    delete(p);
    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}


