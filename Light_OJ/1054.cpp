/// #define_SUST
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
#define CLR(o) memset(o, 0, sizeof o)
#define CLR1(o) memset(o, -1, sizeof o)
#define MAX3(a, b, c) MAX(a , MAX(b,c))
#define MIN3(a, b, c) MIN(a , MIN(b,c))
#define takei(a) scanf("%d", &a)
#define takel(a) scanf("%ld", &a)
#define takell(a) scanf("%lld", &a)
#define takellu(a) scanf("%llu", &a)
#define sf scanf
#define ssf sscanf
#define pb push_back
#define PPP system("pause")
#define ok cout << "OK" <<endl;
#define pf printf
#define PI 2*acos(0)
using namespace std;

typedef long long ll;
template <class T> T MAX(T a, T b) { return a>b?a:b;}
template <class T> T MIN(T a, T b) { return a<b?a:b;}
template <class T1> void deb(T1 x){ cout << "Debugging: " << x << endl;}
template <class T1, class T2> void deb(T1 x, T2 y){ cout << "Debugging: " << x << ", " << y << endl;}
template <class T1, class T2, class T3> void deb(T1 x, T2 y, T3 z) { cout << "Debugging: " << x << ", " << y << ", " << z << endl;}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};
const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1};      // diagonal -> 8 horizontal/vertical->4
const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // Knight moovs
#define SIZE 100000
const ll mod = 1000000007;
bool prime[SIZE];
ll pi[50000], up;
void SEIVE()
{
    ll i, j, k=0, l=sqrt(SIZE);
    pi[k++] = 2;
    for(i=3; i<SIZE; i+=2)
        if(prime[i]==0)
    {
        pi[k++] = i; //deb(k);
        for(j=i*i; j<SIZE; j+=i)
            prime[j] = 1;
    }
    up = k;
    //for(i=0; i<10; i++) deb(pi[i]);
}
ll BIGMOD(ll base, ll power, ll mod)
{
    if(power==0) return 1;
    ll res = BIGMOD(base, power/2, mod);
    res = (res*res)%mod;
    if(power & 1)
        res = (res*base)%mod;
    return res;
}

int main()
{
    // time_t t1=clock();
#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    ll i, j, k, t, n, m, res, fact, p, q, keis = 0;
    SEIVE();
    //cout << pi[up-1];
    takell(t);
    while(t--)
    {
        takell(n); takell(m);
        res = 1;
        p = q = 1;
        for(i=0; i<up && n!=1; i++)
        {
            if(n%pi[i]==0)
            {
                fact = 0;
                while(n%pi[i]==0)
                {
                    fact++;
                    n/=pi[i];
                }
                //deb(pi[i], fact);
                p = (p*(BIGMOD(pi[i], m*fact+1, mod) - 1))%mod;
                q = q*(pi[i]-1);
                //if(q>=mod)q = BIGMOD(q, mod-2, mod);
                //deb(p, q);
                //res *= ((p/q)%mod);
            }
        }
        if(n!=1)
        {
            p = (p*(BIGMOD(n, m+1, mod) - 1))%mod;
            q = q*(n-1);
            if(p<0) p= (p+mod)%mod;
            //deb(p, BIGMOD(q, mod-2, mod));
        }
        res = (p*BIGMOD(q, mod-2, mod))%mod;-
        pf("Case %lld: %lld\n", ++keis, res);
    }
    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}

