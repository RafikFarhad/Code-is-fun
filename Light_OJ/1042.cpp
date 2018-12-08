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
typedef long long unsigned llu;
string a;

llu BRING()
{
    llu cow=0, i = a.size(), fact=1;
    //deb(a.size(), i);
    for(--i; i>0; i--, fact*=2)
        {
            //deb(i);
            if(a[i]=='1') cow += fact;
        }
    return cow;
}

void BIN(llu n)
{
    if(n==0) return;
    BIN(n>>1);
    n&1?a +="1":a+="0";
}
int main()
{
    // time_t t1=clock();
#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int t, keis=0;
    llu i, n, j;
   // deb(BRING(16));
   takei(t);
   while(t--)
   {
       takellu(n);
       a = "00";
   BIN(n);
   //cout << a << endl;
   for(i=j=a.size()-1; i>0; i--)
   {
       if(a[i]=='1' && a[i-1]=='0')
       {
           a[i] = '0';
           a[i-1] = '1';
           break;
       }
       else if(a[i]=='1')
       {
           while(j>i)
           {
               if(a[j]=='0')
               {
                   a[j] = '1';
                   a[i] = '0';
                   ;
                   break;
               }
               else --j;
           }
       }

   }
//cout << a << endl;
  // a = "0";
  n = BRING();
  pf("Case %d: %llu\n", ++keis, n);
  //cout << a << endl;
   }
    /* Coding is FUN  */
    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}
