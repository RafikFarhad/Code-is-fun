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
#define SIZE INT_MAX
long long dp[(1<<16)+5][21], n, ar[20], ans, k, base;
int len;
long long CALL_OF_DUTY(int mod, int flag, int taken=0)
{
    if(taken==len)
    {
        return mod==0;
    }
    long long &ans = dp[flag][mod];
    if(ans!=-1) return ans;
    ans = 0;
    int i, j;
    //deb(taken);
    for(i=0; i<len; i++)
    {
        //deb(i);
        if(!(flag&(1<<i)))
        {
            ans+=CALL_OF_DUTY((mod*base+ar[i])%k, flag|(1<<i), taken+1);
        }
    }
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int i, j, l, t, keis=0;
    takei(t);
    string a;
    while(t--)
    {
        sf("%lld %lld", &base, &k);
        //deb(base, k);
        getchar();
        cin >> a;
        //deb(a);
        len = a.size();
        //deb(len);
        //deb("?", k, a, len);
        for(i=0; i<len; i++)
        {
            if(isdigit(a[i]))
                ar[i] = a[i]-'0';
            else
                ar[i] = a[i] - 'A' + 10;
            //deb(ar[i]);
        }
        CLR1(dp);
        ans = CALL_OF_DUTY(0, 0);
        csi;
        pf("%lld\n", ans);
    }
    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}


