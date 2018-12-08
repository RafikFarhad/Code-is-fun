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
#define SIZE 100005
int prime[10000], ss;
bool p[SIZE+5];

void SEIVE()
{
    int i, j;
    ss = 0;
    prime[ss++] = 2;
    for(i=3; i<SIZE; i+=2)
    {
        if(!p[i])
        {
            prime[ss++] = i;
            for(j=i*i; j>0 and j<SIZE; j+=i)
                p[j] = 1;
        }
    }
    return;
    for(i=0; i<25; i++)
        deb(prime[i]);
    deb(ss, prime[ss-1]);
}

typedef pair<int, int> pii;

#define x first
#define y second

pii extendedEuclid(int a, int b)    // returns x, y | ax + by = gcd(a,b)
{
    if(b == 0) return pii(1, 0);
    else
    {
        pii d = extendedEuclid(b, a % b);
        return pii(d.y, d.x - d.y * (a / b));
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int n, p, q, i, j, k, l, t, keis=0;
    SEIVE();
    pii temp1, temp2, qu;
    takei(t);
    while(t--)
    {
        takei(n);
        for(i=0; i<ss; i++)
            if(n%prime[i]==0)
            {
                p = prime[i];
                q = n/prime[i];
                break;
            }
        temp1 = extendedEuclid(p, q);
        temp2 = extendedEuclid(q, p);
        //deb(temp1.x*p-temp1.y*q, temp1.x*p, temp1.y*q);
        //deb(temp2.x*q-temp2.y*p, temp2.x*q, temp2.y*p);
        i = p*temp1.x;
        j = temp2.x*q;
        //deb(i, j);
        if(i<0) i+=n;
        //i%=n;
        if(j<0) j+=n;
        //j%=n;
        pf("0 1 %d %d\n", min(i, j), max(i, j));
    }
    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}


