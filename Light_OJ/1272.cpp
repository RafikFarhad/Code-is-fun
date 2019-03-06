
/**         HODOR          **/



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
int SET(int mask, int pos){return mask | (1<<pos);}
bool CHK(ll mask, int pos){return (1ll&(mask>>pos));}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1}; const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define LT (1<<31)-1
#define MX
#define MOD
#define MY INT_MIN
//ll FAST_EXP(ll base, ll power) /*base^power%MOD*/   {ll res=1ll;while(power){if(power&1)res=(res*base)%MOD;base=(base*base)%MOD;power>>=1;}return res%MOD;}
ll ar[105];
bool COMPA(ll a, ll b)
{
    return a>b;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
    //clock_t ooo = clock();
#endif
    int i, t, j, k, l,  kk, n, keis(0);
    ll c, d, x, y, a, b;
    takei(t);
    while(t--)
    {
        takei(n);
        for(i=0; i<n; i++)
        {
            takell(ar[i]);
        }
        a = 0;
        sort(ar, ar+n, COMPA);
        int my = 0;
        for(i=63; i>=0 and my<n; i--)
        {
            b = 0;
            if(CHK(ar[my], i)==0)
            {
                for(j=my+1; j<n; j++)
                {
                    if(CHK(ar[j], i))
                    {
                        swap(ar[j], ar[my]);
                        break;
                    }
                }
            }
            if(CHK(ar[my], i)==0)
                continue;
            else
            {
                for(j=0; j<n; j++)
                {
                    if(j==my) continue;
                    if(CHK(ar[j], i))
                        ar[j] = ar[j]^ar[my];
                }
            }
            my++;
        }
        a = 0;
        for(j=0; j<n; j++)
        {
            a^=ar[j];
            //eb("------------------->", i, b, ar[j]);
        }
        csi;
        __(a);
    }

    return 0;
}

