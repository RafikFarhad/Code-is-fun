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
int ar[500015][6];
int main()
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    //freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int i, j, k, l, n, keis=0, a, t, c, g, ans, track, p1, p2;
    char pp[500015];
    takei(n);
    getchar();
    sf("%s", pp);
    a = c = t = g = 0;
    ar[0][0] = ar[0][1] = ar[0][2] = ar[0][3] = ar[0][4] = 0;
    for(i=0; i<n; i++)
    {
        if(pp[i]=='A')
        {
            a++;
            ar[i][1]++;
        }
        else if(pp[i]=='C')
        {
            c++;
            ar[i][3]++;
        }
        else if(pp[i]=='T')
        {
            t++;
            ar[i][2]++;
        }
        else if(pp[i]=='G')
        {
            g++;
            ar[i][4]++;
        }
        ar[i+1][1] = ar[i][1];
        ar[i+1][2] = ar[i][2];
        ar[i+1][3] = ar[i][3];
        ar[i+1][4] = ar[i][4];
    }
    //deb(a, t, c, g);
    a=a-(n/4);
    t=t-(n/4);
    c=c-(n/4);
    g=g-(n/4);
    a = a<0?0:a;
    t = t<0?0:t;
    c = c<0?0:c;
    g = g<0?0:g;
    if(a+c+t+g==0)
    {
        puts("0");
        return 0;
    }
    /*ans = max(max(a, t), max(c, g));
    if(ans==a)
        track = 1;
    else if(ans==t)
        track = 2;
    else if(ans==c)
        track = 3;
    else if(ans==g)
        track = 4;

    if(ans==0)
    {
        puts("0");
        return 0;
    }
    /*
    deb(ans, track);
    deb(a, t, c, g);*/
    i = 0; j = 1e9;
    p1 = p2 = 0;
    for(p2=1; p2<n; p2++)
    {
        while(ar[p2][1] - ar[p1][1] >=a and ar[p2][2] - ar[p1][2] >=t and ar[p2][3] - ar[p1][3] >=c and ar[p2][4] - ar[p1][4] >=g)
        {
            if(j-i>p2-p1)
            {
                j = p2;
                i = p1;
            }
            p1++;
        }
    }
    __(j-i);


    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}


