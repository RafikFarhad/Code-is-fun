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
bool CHECK(int k)
{
    if(k%400==0) return true;
    if(k%100==0) return 0;
    if (k%4==0) return 1;
    else return 0;
}
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int i, j, k, l,  keis=0, a, b, c, d, t, dd, mm, yy, cow, r1, r2, r3, day, leap;
    int en[] = {0, 31,28,31,30,31,30,31,31,30,31,30,31};
    int ban[] = {13,30,30,30,31,31,31,31,31,30,30,30, 17};
    string mp[] = {"Poush", "Magh", "Falgun", "Chaitra", "Baishakh", "Jaishtha", "Ashar",
                    "Sraban", "Bhadra", "Ashwin", "Kartik" ,"Agrahayan", "Poush"};
    for(i=1; i<13; i++)
        en[i] = en[i]+en[i-1];
    takei(t);
    while(t--)
    {
        leap = 0;
        csi;
        takei(dd);
        takei(mm);
        takei(yy);
        r3 = 1378 + (yy-1972);
        day = en[mm-1] + dd;
        leap = CHECK(yy);
        if(leap)
        {
            ban[2]++;
            if(mm>2)
            {
                day++;
            }
        }
        //deb(day);
        //deb("*", leap);
      //  if(!leap and day>=104) r3++;
       // else if(leap and day>=105) r3++;
        //deb(day);
        for(i=0; i<13; i++)
        {
            //deb(i, day, ban[i]);
            if(day<=ban[i])
                break;
            day-=ban[i];
            //deb(i, day);
        }
        if(i==0)
        {
            printf("%d, %s, %d\n", 17+day, mp[i].c_str(), r3);
        }
        else
        {
            printf("%d, %s, %d\n", day, mp[i].c_str(), i>3?r3+1:r3);
        }
        if(leap)
            ban[2]--;
    }
    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}


