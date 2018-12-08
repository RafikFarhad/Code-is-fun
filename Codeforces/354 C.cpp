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
/******************************************/
/** Author     : Rafik Farhad              */
/** Mail to     : rafikfarhad@gmail.com   */
/*****************************************/
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
char in[100005];
int n, k;
int main()
{
    //ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    //freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int i, t, j, l,  keis=0, a, b, c, d, x, y;
    takei(n);
    takei(k);
    sf("%s", in);
    l = n;
    int ansa = 0, ansb=0;
    j = 0;
    a = 0;
    for(i=0; i<l; i++)
    {
        if(in[i]=='b') j++;
        if(j==k+1) break;
        a++;
    }
    j = i+1;
    ansa = a;
    for(i=0, j; j<l; )
    {
        while(i<=j and in[i]!='b') i++;
        while(j<l and in[j]!='b') j++;
        if(j<l) ansa = max(ansa, j-i-1);
        else ansa = max(ansa, j-i-1);
        i++;
        j++;
    }
    j = 0;
    a = 0;
    for(i=0; i<l; i++)
    {
        if(in[i]=='a') j++;
        if(j==k+1) break;
        a++;
    }
    j = i+1;
    ansb = a;
    for(i=0, j; j<l; )
    {
        while(i<=j and in[i]!='a') i++;
        while(j<l and in[j]!='a') j++;
        if(j<l) ansb = max(ansb, j-i-1);
        else ansb = max(ansb, j-i-1);
        i++;
        j++;
    }
    //deb(ansa, ansb);
    _(max(ansa, ansb));
    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}



