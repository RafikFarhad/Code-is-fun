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
//int SET(int mask, int pos){return mask singlebar (1<<pos);}
//bool CHK(int mask, int pos){return (1&(mask>>pos));}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1}; const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define LT (1<<31)-1
#define MX
#define MOD
#define MY INT_MIN
vector <ll> prime;
class PRIME
{
public:
    int SIZE, total;

    int *primee;
    PRIME(int _SIZE)
    {
        SIZE = _SIZE;
        primee = new int[SIZE/32+10];
        memset(primee, 0, sizeof primee);
        /// Calculating
        long long i, j, lim = sqrt(SIZE) + 1;
        for(i=2; i<=lim ; i++)
        {
            if((primee[i>>5] & 1<<(i&31))==0)
            {
                for(j=i*i; j<SIZE; j+=i)
                {
                    primee[j>>5] = (primee[j>>5] | (1<<(j&31)));
                }
            }
        }
        return;
    }
    void SAVE(vector <ll> &prime)
    {
        int i;
        prime.pb(4);
        prime.pb(9);
        for(i=6; i<SIZE-1; i+=6)
        {
            if(primee[(i-1)>>5] & 1<<((i-1)&31))
                ;
            else prime.pb((ll)(i-1)*(i-1));
            if(primee[(i+1)>>5] & 1<<((i+1)&31))
                ;
            else
                prime.pb((ll)(i+1)*(i+1));
        }
        total = prime.size();
    }

};
ll ans;

void GO(ll a, ll prev, ll taken, ll cur)
{
    if(prev>a) return;
    if(taken&1ll)
        ans-=(a/prev);
    else
        ans+=(a/prev);
    for(int i=cur; prime[i]<=a; i++)
    {
        if(prev>a/prime[i]+1) break;
        //deb(ans , prev, prev*prime[i]);
        GO(a, prev*prime[i], taken+1, i+1);
    }
    return;
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
    int i, t, j, k, l,  keis(0); ll c, d, x, y, a, b;
//    char pp[100];
//    fgets(pp, 100, stdin);
    PRIME p((int)1e7 + 100);
    p.SAVE(prime);

    takei(t);
    while(t--)
    {
        takell(a);
        ans = 0;
        GO(a, 1ll, 0ll, 0);
        __(ans);
    }


    /* Coding is FUN  */
    ///                                    ENDD
#ifndef ONLINE_JUDGE
    //pf("-------ENDS OF OUTPUT------\n\n");
    //pf("Time Elapsed: %lu\n", (clock()-ooo));
#endif
    return 0;
}



