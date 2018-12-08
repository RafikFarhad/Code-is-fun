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

template <class T> T MAX(T a, T b) { return a>b?a:b;}
template <class T> T MIN(T a, T b) { return a<b?a:b;}
template <class T1> void deb(T1 x){ cout << "Debugging: " << x << endl;}
template <class T1, class T2> void deb(T1 x, T2 y){ cout << "Debugging: " << x << ", " << y << endl;}
template <class T1, class T2, class T3> void deb(T1 x, T2 y, T3 z) { cout << "Debugging: " << x << ", " << y << ", " << z << endl;}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};
const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1};      // diagonal -> 8 horizontal/vertical->4
const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // Knight moovs
#define SIZE 1<<29

int P(int b, int p)
{
    if(p==0) return 1;
    return b*P(b, p-1);
}

 long long unsigned COUNT( long long unsigned n, int fact)
{
     long long unsigned sum = 0;
    // deb(n, fact);
    while(n)
    {
        sum+=(n/fact);
        n/=fact;
    }
    return sum;
}

int main()
{
    // time_t t1=clock();
#ifndef ONLINE_JUDGE
    freopen("000.txt", "r", stdin);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int t, keis=0, limit = 2*(1<<21)+1000, i, j, k, base, fact,l;
    long long unsigned n, maxi;
    double *lo, cow;
    lo = new double[limit];
    lo[0] = 0;
    vector<pair<int, int> >pp;
    for(i=1; i<limit; i++)
    {
        lo[i] = log10(i)+lo[i-1];
    }
    while(sf("%llu %d", &n, &base)==2)
    {
        pp.clear();
        cow = ceil(lo[n]/log10(base)+1e-9);
        k = base;
        for(i=2, maxi=0, fact=0; base!=1; i++)
        {
            if(base%i==0)
            {
                j = 0;
                while(base%i==0)
                {
                    j++; //deb(base);
                    base/=i;
                }
                l = i;
            }
        }
        //deb(--i, j);
        //deb(fact);
        maxi = 0;
        while(n/l)
        {
            maxi+=(n/l);
            n/=l;
        }
        maxi/=j;
        //deb(i);
        pf("%llu %.0lf\n", maxi,  cow);
    }
    delete(lo);
    /* Coding is FUN  */
    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}
