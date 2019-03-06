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
#define SIZE 46400
int ar[105], n;
void SUM()
{
    int i, s;
    sf("%d", &s);
    for(i=0; i<n; i++)
        ar[i]+=s;
    return;
}
void MUL()
{
    int i, s;
    sf("%d", &s);
    for(i=0; i<n; i++)
        ar[i]*=s;
    return;
}
void DIV()
{
    int i, s;
    sf("%d", &s);
    for(i=0; i<n; i++)
        ar[i]/=s;
    return;
}
void SWAP()
{
    int i, s;
    sf("%d %d", &s, &i);
    if(i==s) return;
    ar[s] = ar[s]^ar[i];
    ar[i] = ar[s]^ar[i];
    ar[s] = ar[s]^ar[i];
    return;
}
void REV()
{
    int i, s;
    //getchar();
    for(i=0; i<n/2; i++)
    {
        s = ar[i];
        ar[i] = ar[n-i-1];
        ar[n-i-1] = s;
    }
    return;
}

int main()
{
    // time_t t1=clock();
#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
    freopen("input.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int t, keis=0, i, m;
    char ch;
    takei(t);
    while(t--)
    {
        sf("%d %d", &n, &m); //deb(n, m);
        for(i=0; i<n; i++)
            sf("%d ", &ar[i]);
        while(m--)
        {
            sf(" %c", &ch); //putchar(ch);
            if(ch=='S') SUM();
            else if(ch=='M') MUL();
            else if(ch=='D') DIV();
            else if(ch=='P') SWAP();
            else if(ch=='R') REV();
        }
        pf("Case %d:\n", ++keis);
        for(i=0;  ; i++)
        {
            pf("%d", ar[i]);
            if(i==n-1) break;
            pf(" ");
        }
        pf("\n");
    }
    /* Coding is FUN  */
    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}

