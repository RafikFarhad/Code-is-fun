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
#define READ(a) freopen(a,"r",stdin);
#define WRITE(b) freopen(b, "w", stdout);

using namespace std;
template <class T> T MAX(T a, T b) { return a>b?a:b;}template <class T> T MIN(T a, T b) { return a<b?a:b;}
template <class T1> void deb(T1 p) { cout << "Debugging: " << p << endl;}
template <class T1, class T2> void deb(T1 p, T2 q) { cout << "Debugging: " << p << "\t" << q  << endl;}
template <class T1, class T2, class T3> void deb(T1 p, T2 q, T3 r) { cout << "Debugging: " << p << "\t " << q << "\t " << r << endl;}
template <class T1, class T2, class T3, class T4> void deb(T1 p, T2 q, T3 r, T4 s) { cout << "Debugging: " << p << "\t " << q << "\t " << r << "\t " << s << endl;}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1}; const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moovs xx-> diagonal -> 8 horizontal/vertical->4
#define SIZE 140000

int COUNT(int p)
{
    int cow = 0, i;
    for(i=0; i<17; i++)
        if(p & 1<<i)
            cow++;
    return cow;
}
void BIN(int i)
{
    if(i==0)
    {
        //NL;
        return;
    }
    BIN(i/2);
    if(i&1)
        pf("1");
    else
        pf("0");
    return;
}

int main()
{
    // time_t t1=clock();
#ifndef ONLINE_JUDGE
    READ("input.txt");
    WRITE("output.txt");
#endif
    ///                                    MAIN
    int t, keis=0, i, j, k, n, ar[SIZE+5][2], h;
    int c = 0;;
    ar[0][0] = 0;
    ar[0][1] = 0;
    for(i=1; i<SIZE; i++)
    {
        ar[i][0] = floor(log2(i)) + 1;
        ar[i][1] = COUNT(i);
    }
//    for(i=1; i<10; i++)
//        deb(i, ar[i][0], ar[i][1]);
    takei(t);
    while(t--)
    {
        if(keis++) pf("\n");
        takei(n);
        takei(h);
        for(i=0; i<SIZE && ar[i][0] <=n; i++)
            if(ar[i][1] == h)
            {
                if(ar[i][0] < n)
                    pf("%0*d", n - ar[i][0], c);
                BIN(i);
                NL;
            }
    }
    /* Coding is FUN  */
    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}
