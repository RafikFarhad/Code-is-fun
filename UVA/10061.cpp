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

int pr[800], ss;
bool p[805];

void SEEIEVE()
{
    int i, j;
    ss = 0;
    pr[ss++] = 2;
    for(i=3; i<801; i+=2)
    {
        if(!p[i])
        {
            pr[ss++] = i;
            for(j=i*i; j<801; j+=i)
                p[j] = 1;
        }
    }
    return ;
    deb(ss);
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
    /*
    Now we can break the Base B as a product of primes :
    B = a^p1 * b^p2 * c^p3 * …
    Then the number of trailing zeros in N factorial in Base B is given by the formula
    min{1/p1*(n/a + n/(a*a) + ….), 1/p2*(n/b + n/(b*b) + ..), ….}.

    And the number of digits in N factorial is :
    floor (ln(n!)/ln(B) + 1)

    */
    int t, keis=0, limit = (1<<23)+1000, i, j, k, base, fact,l;
    int n, maxi;
    double *lo, cow;
    lo = new double[limit];
    lo[0] = 0;
    for(i=1; i<limit; i++)
    {
        lo[i] = log10(i)+lo[i-1];
    }
    SEEIEVE();
    while(sf("%d %d", &n, &base)!=EOF)
    {
        cow = ceil(lo[n]/log10(base)+10e-9);
        k = base;
        t = n;
        l = n;
       // deb(l);
        for(i=ss-1; i>=0 and k!=1; i--)
        {
            if(k%pr[i]==0)
            {
                j = 0;
                while(k%pr[i]==0)
                {
                    j++;
                    k/=pr[i];
                }
                t = n;
                fact = pr[i];
                maxi = 0;
                while(t/fact)
                {
                    maxi+=(t/fact);
                    t/=fact;
                }
                //deb(maxi, maxi/j);
                l = min(l, maxi/j);

            }
        }
        //deb(i);
        pf("%d %.0f\n", l,  cow);
    }
    delete(lo);
    /* Coding is FUN  */
    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}
