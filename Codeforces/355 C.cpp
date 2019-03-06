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
#define _(o)                                    pf("%d\n", o)
#define ll                                      long long
#define ull                                     unsigned long long
#define exx                                     2.7182818284590452353602875

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
#define SIZE INT_MAX
ll BIGMOD(ll b, ll p, ll mod)
{
    if(p==0) return 1ll;
    ll temp = BIGMOD(b, p/2, mod);
    temp = temp*temp;
    temp%=mod;
    if(p&1)
        temp*=b;
    return temp%mod;
}
int main()
{
    //ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    //freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int i, t, j, k, l,  keis=0;
    ll a, b, c, d, x, y, ar[19];
    ar[0] = 1ll;
    for(i=1; i<10; i++)
    {
        ar[i] = 2*ar[i-1];//*(ll)i;
        //deb(i, ar[i]);
    }

    string ss;
    while(cin >> ss)
    {
        a = 1ll;
        ll mod = 1e9+7;//    00000007;
        l = ss.size();
        for(i=0; i<l; i++)
        {
            if(isdigit(ss[i]))
                k = ss[i] -'0';
            else if(isupper(ss[i]))
                k = ss[i] - 'A' + 10;
            else if(islower(ss[i]))
                k = ss[i] - 'a' + 36;
            else if(ss[i]=='-')
                k = 62;
            else if(ss[i]=='_')
                k = 63;
            t = 0;
            //deb(k);
            for(j=0; j<6; j++)
            {
                if(k%2==0) t++;
                k/=2;
            }
           // deb(t, ar[t]);
            x=1;
            for(j=0; j<t; j++)
            {
                x*=3;
            }
            a*=(x);
            a%=mod;

        }
        //a = (a+a)%mod;
        //a++;
        //a = a * BIGMOD(2, mod-2, mod);
        a%=mod;
        cout << a<< endl;
    }

    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}



