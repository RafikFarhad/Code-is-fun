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
#include <iterator>
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

template <class T> T MAX(T a, T b) { return a>b?a:b;}
template <class T> T MIN(T a, T b) { return a<b?a:b;}
template <class T1> void deb(T1 x){ cout << "Debugging: " << x << endl;}
template <class T1, class T2> void deb(T1 x, T2 y){ cout << "Debugging: " << x << ", " << y << endl;}
template <class T1, class T2, class T3> void deb(T1 x, T2 y, T3 z) { cout << "Debugging: " << x << ", " << y << ", " << z << endl;}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};
const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1};      // diagonal -> 8 horizontal/vertical->4
const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // Knight moovs
#define SIZE 1000002
bool p[SIZE];
long long prime[79000], sz, c;
map <long long, int> mp;
void SEIEVE()
{
    long long i, j;
    sz = 0;
    for(i=2; i<SIZE; i++)
        if(!p[i])
    {
        prime[sz++] = i;
        for(j=i*i; j<SIZE; j+=i)
            p[j] = 1;
    }
   /* for(i=0; i<24; i++)
        cout << prime[i] << endl;
        cout << sz << endl;*/
}

long long POWER(long long base, long long power)
{
    if(power==0) return 1;
    return base*POWER(base, power-1);
}

void Prime_FACTORIZATION(long long m)
{
    int i, j, l, cow = 0;
    for(i=0; i<sz && m>1; i++)
    {
        if(m%prime[i]==0)
        {
            cow = 0;
            while(m%prime[i]==0)
            {
                cow++;
                m/=prime[i];
            }
            mp[prime[i]] = MAX(mp[prime[i]], cow);
        }
    }
    if(m!=1)
        mp[m] = MAX(mp[m], cow);
}

void Prime_FACTORIZATION_FOR_L(long long m)
{
    int i, j, l, cow = 0;
    for(i=0; i<sz && m>1; i++)
    {
        if(m%prime[i]==0)
        {
            cow = 0;
            while(m%prime[i]==0)
            {
                cow++;
                m/=prime[i];
            }
            if(mp[prime[i]]==cow) mp[prime[i]] = 0;
            else mp[prime[i]] = cow;
        }
    }
    if(m!=1)
        if(mp[m]==cow) mp[m] = 0;
        else mp[m] = cow;
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
    SEIEVE();
    long long t, a, b, L, i, j, k, keis = 0;
    takell(t);
    while(t--)
    {
        mp.clear();
        c = 1;
        takell(a);
        takell(b);
        takell(L);
        Prime_FACTORIZATION(a);
        Prime_FACTORIZATION(b);
        Prime_FACTORIZATION_FOR_L(L);
        map <long long, int>:: iterator it;
        for(it = mp.begin(); it!=mp.end(); it++)
            c = c*POWER(it->first, it->second);
        //deb(c);
        if(L%c!=0 || L%a!=0 || L%b!=0) pf("Case %lld: impossible\n", ++keis);
        else pf("Case %lld: %lld\n", ++keis, c);
    }
    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}

