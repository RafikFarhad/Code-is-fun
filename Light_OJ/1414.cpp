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

bool IS_LEAP(long long unsigned year)
{
    if(year%4==0 && !(year%100 ==0) || year%400==0) return 1;
    return false;
}
bool ONE(char p[])
{
    if(strcmp(p, "January")==0 || strcmp(p, "February")==0) return true;
    return false;
}
bool TWO(char p[], long long unsigned d)
{
    if(strcmp(p, "January")==0) return true;
    if(strcmp(p, "February")==0 && d<29) return true;
    return false;
}
int main()
{
    // time_t t1=clock();
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    long long unsigned t, i, j, cow, keis = 0, k, l, date1, year1, year2, date2;
    char m1[20], m2[20];
    sf("%llu", &t);
    while(t--)
    {
        sf("%s %llu, %llu", m1, &date1, &year1);
        sf("%s %llu, %llu", m2, &date2, &year2);
        year2--;
        cow = (year2/4 - year1/4) - (year2/100 - year1/100) + (year2/400 - year1/400);
        year2++;
        if(ONE(m1) && IS_LEAP(year1)) cow++;
        if(!TWO(m2, date2) && IS_LEAP(year2)) cow++;

        if(year1==year2 && IS_LEAP(year1))
            if(ONE(m1))
            if(!TWO(m2, date2))
                cow = 1;

        pf("Case %lld: %lld\n", ++keis, cow);
    }
    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}

