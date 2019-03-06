/// Heil Hydra
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
#define CLR(o) memset(o, 0x00, sizeof o)
#define CLR1(o) memset(o, -1, sizeof o)
#define MAX3(a, b, c) MAX(a , MAX(b,c))
#define MIN3(a, b, c) MIN(a , MIN(b,c))
#define takei(a) scanf("%d", &a)
#define takell(a) scanf("%lld", &a)
#define takellu(a) scanf("%llu", &a)
#define sf scanf
#define ssf sscanf
#define pb push_back
#define PPP system("pause")
#define ok cout << "OK" <<endl;
#define pf printf
#define NL printf("\n")
#define PI 2*acos(0)
#define READ freopen("input.txt","r",stdin);
#define WRITE freopen("output.txt", "w", stdout);

using namespace std;
template <class T> T MAX(T a, T b) { return a>b?a:b;}template <class T> T MIN(T a, T b) { return a<b?a:b;}
template <class T1> void deb(T1 p) { cout << "Debugging: " << p << endl;}
template <class T1, class T2> void deb(T1 p, T2 q) { cout << "Debugging: " << p << "\t" << q  << endl;}
template <class T1, class T2, class T3> void deb(T1 p, T2 q, T3 r) { cout << "Debugging: " << p << "\t " << q << "\t " << r << endl;}
template <class T1, class T2, class T3, class T4> void deb(T1 p, T2 q, T3 r, T4 s) { cout << "Debugging: " << p << "\t " << q << "\t " << r << "\t " << s << endl;}
long long int POOW(int b, int p) { if(p==0) return 1; return b*POOW(b, p-1);}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1}; const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define SIZE 100005
long long unsigned memory[12][30005];
int paisha[] = {10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5};
//$100, $50, $20, $10, and $5 notes and $2, $1, 50c, 20c, 10c and 5c

long long unsigned COIN_CHANGE(int cent, int rem)
{
    if(cent>=11)
    {
        if(rem==0) return 1;
        return 0;
    }
    if(memory[cent][rem] != -1) return memory[cent][rem];
    long long unsigned pr1 = 0, pr2 = 0;
    if(rem - paisha[cent]>=0)
        pr1 = COIN_CHANGE(cent, rem-paisha[cent]);
    pr2 = COIN_CHANGE(cent+1, rem);
    return memory[cent][rem] = pr1 + pr2;
}

int main()
{
    // time_t t1=clock();
#ifndef ONLINE_JUDGE
    READ;
    WRITE;
#endif
    ///                                    MAIN
    int t, keis=0, i;
    double n;
    CLR1(memory);
    while(sf("%lf", &n)==1 && n>.000001)
        pf("%6.2lf%17llu\n", n, COIN_CHANGE(0, (int)round(n*100)));
    /* Coding is FUN  */
    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}
