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
#define SIZE 10000007

bool *prime;
vector <long long> p;

void SEIEVE()
{
    p.clear();
    prime = new bool[SIZE];
    long long i, j, k = SIZE >> 1;;
    for(i=2; i<k; i++)
        if(!prime[i])
            {
                p.pb(i);
                for(j=i*i; j<SIZE; j+=i)
                prime[j] = 1;
            }
    //for(i=0; i<24; i++) deb(p[i]);
    return;
}

int main()
{
     //time_t t1=clock();
#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    SEIEVE();
    long long i, j, cow, l, n, t, keis=0, s = p.size(); //deb(s, p[s-1]);
    takell(t);
    while(t--)
    {
        takell(n);
        if(n==4) {pf("Case %lld: %lld\n", ++keis, 1); continue;}
        cow=0;
        l = n>>1; //deb(l);
        for(i=0; p[i]<=l && i<s; i++)
        {
            //deb(p[i]);
            if(!prime[n-p[i]])
                cow++;//,  deb(i);
        }
        pf("Case %lld: %lld\n", ++keis, cow);
    }

    delete prime;
    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}

