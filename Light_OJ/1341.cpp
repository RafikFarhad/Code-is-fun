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
template <class T> T MAX(T a, T b)
{
    return a>b?a:b;
}
template <class T> T MIN(T a, T b)
{
    return a<b?a:b;
}
template <class T1> void __(T1 p)
{
    cout << p << endl;
}
template <class T1> void deb(T1 p)
{
    cout << "Debugging: " << p << endl;
}
template <class T1, class T2> void deb(T1 p, T2 q)
{
    cout << "Debugging: " << p << "\t" << q  << endl;
}
template <class T1, class T2, class T3> void deb(T1 p, T2 q, T3 r)
{
    cout << "Debugging: " << p << "\t " << q << "\t " << r << endl;
}
template <class T1, class T2, class T3, class T4> void deb(T1 p, T2 q, T3 r, T4 s)
{
    cout << "Debugging: " << p << "\t " << q << "\t " << r << "\t " << s << endl;
}
long long int POOW(long long b, long long p)
{
    if(p==0) return 1;
    return b*POOW(b, p-1);
}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};
const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1};
const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define SIZE 1000010

int ss, p[SIZE/32+10], prime[80000];

void SEIEVE()
{
    long long i, j, k;
    ss = 0;
    prime[ss++] = 2;
    for(i=3; i<SIZE; i+=2)
    {
        if(!(p[i/32]&(1<<(i%32))))
        {
            //deb(ss, i, prime[ss-1]);
            prime[ss++] = i;
            for(j=i*i; j<SIZE; j+=i)
            {
                p[j/32]|=(1<<(j%32));
            }
        }
    }
    return;
    deb(ss);
    for(i=0; i<25; i++)
        deb(prime[i]);
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    long long a, b, i, j, k, l, t, keis=0, n;
    SEIEVE();
    takell(t);
    while(t--)
    {
        takell(a);
        k = a;
        takell(b);
        if(b>=sqrt(a))
        {
            csll;
            n = 0;
        }
        else
        {
            n = 1;
            for(i=0; i<ss and a!=1; i++)
            {
                if(a%prime[i]==0)
                {
                    j = 1;
                    while(a%prime[i]==0)
                    {
                        j++;
                        a/=prime[i];
                    }
                    n*=j;
                }
            }
            if(a!=1) n<<=1;
            n>>=1;
            csll;
            for(i=1; i<b; i++)
            {
                if(k%i==0)
                    n--;
            }
        }
        pf("%lld\n", n);
    }
    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}

