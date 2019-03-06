/*
ID: rafikfa1
PROG: transform
LANG: C++
*/
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
int n;
string in[10], out[10], c[10], d[10], e[10];

bool is90()
{
    int i, j, k, l;
//    for(i=0; i<n; i++)
//        for(j=0; j<n; j++)
//            c[i]+="1";
    for(i=0; i<n; i++)
    {
        for(j=n-1; j>=0; j--)
        {
            c[i]+=in[j][i];
        }
    }
    for(i=0; i<n; i++)
    {
        if(c[i]!=out[i])
            return false;
    }
    return true;
}
bool is180()
{
    int i, j, k, l;
//    for(i=0; i<n; i++)
//        for(j=0; j<n; j++)
//            c[i]+="1";
    for(i=0; i<n; i++)
    {
        for(j=n-1; j>=0; j--)
        {
            d[i]+=c[j][i];
        }
    }
    for(i=0; i<n; i++)
    {
        if(d[i]!=out[i])
            return false;
    }
    return true;
}

bool is270()
{
    int i, j, k, l;
//    for(i=0; i<n; i++)
//        for(j=0; j<n; j++)
//            c[i]+="1";
    for(i=0; i<n; i++)
    {
        for(j=n-1; j>=0; j--)
        {
            e[i]+=d[j][i];
        }
    }
    for(i=0; i<n; i++)
    {
        if(e[i]!=out[i])
            return false;
    }
    return true;
}

bool reflection(string *in, string *qq)
{
    int i, j, k, l;
    string pp[10];
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
        {
            pp[i]+="1";
            qq[i]+="1";
        }
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            pp[j][i] = in[i][j];
        }
    }
    for(i=0; i<n/2; i++)
        swap(pp[i], pp[n-i-1]);
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            qq[j][i] = pp[i][j];
        }
    }
    for(i=0; i<n; i++)
    {
        if(qq[i]!=out[i])
            return false;
    }
    return true;
}
bool combination()
{
    string qq[10], pp[10], zz[10], tt[10];
    reflection(in, qq);
        int i, j, k, l;
        for(i=0; i<n; i++)
        {
            //cout << qq[i] << endl;
            for(j=n-1; j>=0; j--)
            {
                pp[i]+=qq[j][i];
            }
        }
        l = 0;
        for(i=0; i<n; i++)
        {
            if(pp[i]!=out[i])
            {
                l = 1;
                break;
            }
        }
        if(!l) return true;

    reflection(in, qq);
    {
        int i, j, k, l;
        for(i=0; i<n; i++)
        {
            for(j=n-1; j>=0; j--)
            {
                zz[i]+=qq[j][i];
            }
        }
        for(i=0; i<n; i++)
        {
            for(j=n-1; j>=0; j--)
            {
                pp[i]+=zz[j][i];
            }
        }
        l = 0;
        for(i=0; i<n; i++)
        {
            if(pp[i]!=out[i])
            {
                l = 1;
                break;
            }
        }
        if(!l) return true;

    }
    reflection(in, qq);
    {
        int i, j, k, l;
        for(i=0; i<n; i++)
        {
            for(j=n-1; j>=0; j--)
            {
                zz[i]+=qq[j][i];
            }
        }
        for(i=0; i<n; i++)
        {
            for(j=n-1; j>=0; j--)
            {
                pp[i]+=zz[j][i];
            }
        }
        for(i=0; i<n; i++)
        {
            for(j=n-1; j>=0; j--)
            {
                tt[i]+=pp[j][i];
            }
        }

        l = 0;
        for(i=0; i<n; i++)
        {
            if(tt[i]!=out[i])
            {
                l = 1;
                break;
            }
        }
        if(!l) return true;
    }
    return false;
}

bool same()
{
    for( int i=0; i<n; i++)
    {
        if(in[i]!=out[i])
        {
            return false;
        }
    }
    return true;
}


int main()
{
    //ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("transform.in","r",stdin);
    freopen("transform.out", "w", stdout);
#endif
    ///                                    MAIN
    int i, t, j, k, l,  keis=0, a, b, c, d, x, y;
    string qq[10];
    takei(n);
    getchar();
    for(i=0; i<n; i++)
    {
        cin >> in[i];
    }
    for(i=0; i<n; i++)
    {
        cin >> out[i];
    }
    if(is90())
    {
        puts("1");
    }
    else if(is180())
    {
        puts("2");
    }
    else if(is270())
    {
        puts("3");
    }
    else if(reflection(in, qq))
    {
        puts("4");
    }
    else if(combination())
    {
        puts("5");
    }
    else if(same())
    {
        puts("6");
    }
    else puts("7");



    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}


