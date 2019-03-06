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
#define sf scanf
#define ssf sscanf
#define pb push_back
#define PPP system("pause")
#define ok cout << "OK" <<endl;
#define pf printf
#define PI 2*acos(0)
#define SIZE 1000005
using namespace std;

template <class T> T MAX(T a, T b) { return a>b?a:b;}
template <class T> T MIN(T a, T b) { return a<b?a:b;}
template <class T1> void deb(T1 x){ cout << "Debugging: " << x << endl;}
template <class T1, class T2> void deb(T1 x, T2 y){ cout << "Debugging: " << x << ", " << y << endl;}
template <class T1, class T2, class T3> void deb(T1 x, T2 y, T3 z) { cout << "Debugging: " << x << ", " << y << ", " << z << endl;}

bool prime[SIZE];
vector <long> p;
void SEIEVE()
{
    long i, j;
    for(i=2; i<1002; i++)
        if(!prime[i])
            for(j=i*i; j<SIZE; j+=i)
                prime[j] = 1;
    for(i=2; i<SIZE; i++)
        if(!prime[i])
            p.pb(i);
    return;
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
    long long unsigned n;
    int test, ti, cow, sum, i, j, k;
    sf("%d", &test);
    for(ti=0; ti<test; ti++)
    {
        sf("%llu", &n);
        sum = 1;
        for(i=0; i<p.size() && p[i] *p[i]<=n; i++)
        {
            cow = 1;
            while(n%p[i]==0)
            {
                cow++;
                n/=p[i];
            }
            sum*=cow;
        }
        if(n!=1) sum*=2;
        pf("Case %d: %d\n", ti+1, sum-1);
    }

    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}
