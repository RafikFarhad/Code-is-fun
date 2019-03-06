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
template <class T> T MAX(T a, T b) { return a>b?a:b;}template <class T> T MIN(T a, T b) { return a<b?a:b;}
template <class T1> void __(T1 p) { cout << p << endl;}
template <class T1> void deb(T1 p) { cout << "Debugging: " << p << endl;}
template <class T1, class T2> void deb(T1 p, T2 q) { cout << "Debugging: " << p << "\t" << q  << endl;}
template <class T1, class T2, class T3> void deb(T1 p, T2 q, T3 r) { cout << "Debugging: " << p << "\t " << q << "\t " << r << endl;}
template <class T1, class T2, class T3, class T4> void deb(T1 p, T2 q, T3 r, T4 s) { cout << "Debugging: " << p << "\t " << q << "\t " << r << "\t " << s << endl;}
long long int POOW(long long b, long long p) { if(p==0) return 1; return b*POOW(b, p-1);}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1}; const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define SIZE INT_MAX
char in[2][12];
int k, dp[12][100][110][2];

int DO(int pos, int mod, int sum, bool maxi, int st)
{
    if(pos==strlen(in[st]))
    {
        if(mod==0 and sum%k==0) return 1;
        return false;
    }
    if(mod>90) return 0;
    int &ret = dp[pos][mod][sum][maxi];
    if(~ret) return ret;
    ret = 0;
    int last = maxi?(in[st][pos]-'0'):9;
    for(int i=0; i<=last; i++)
    {
        ret+=DO(pos+1, (mod*10+i)%k, sum+i, maxi and i==last, st);
    }
    return ret;
}

int main()
{
    //ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    //freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int i, t, j, l,  keis=0, a, b, c, d, x, y;
    takei(t);
    getchar();
    while(t--)
    {
        sf("%s %s %d", in[0], in[1], &k);
        CLR1(dp);
        x = DO(0, 0, 0, 1, 0);
        CLR1(dp);
        y = DO(0, 0, 0, 1, 1);
        int a=0, b=0;
        for(i=0; i<strlen(in[0]); i++)
        {
            a = (a*10)+in[0][i]-'0';
            a%=k;
            b+=in[0][i]-'0';
        }
        if(a==0 and b%k==0) x--;

        csi;
        _(y-x);
    }

    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}




