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

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int i, j, k, l,  keis=0, a, b;
    while(sf("%d %d", &a, &b)!=EOF)
    {
        if(b>=a)
        {
            b-=a;
            ++b;
            if(b==1 or b==30)
                cout << "New Moon";
            else if(b<8)
                cout << "Waxing Moon";
            else if(b==8)
                cout << "Waning Moon";
            else if(b<15)
                cout << "Gibbous Moon";
            else if(b==15)
                cout << "Full Moon";
            else if(b<22)
                cout << "Gibbous Moon";
            else if(b==22)
                cout << "Waning Moon";
            else if(b==29)
                cout << "Waxing Moon";
            NL;
        }
        else
        {
            b+=30;
            b-=a;
            ++b;
            if(b==1)
                cout << "New Moon";
            else if(b<8)
                cout << "Waxing Moon";
            else if(b==8)
                cout << "Waning Moon";
            else if(b<15)
                cout << "Gibbous Moon";
            else if(b==15)
                cout << "Full Moon";
            else if(b<22)
                cout << "Gibbous Moon";
            else if(b==22)
                cout << "Waning Moon";
            else if(b==29)
                cout << "Waxing Moon";
                NL;
        }
    }


    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}


