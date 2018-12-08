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
   // ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int i, j, k, l,  keis=0, a, b, c, d;
    int n, m, ar[200005], maxi=-1, track=0, t[200005], listen[200005];
    takei(n);
    takei(m);
    for(i=0; i<n; i++)
        takei(ar[i]);
    for(i=0; i<m; i++)
    {
        takei(listen[i]);
        takei(t[i]);
        if(maxi<=t[i])
        {
            maxi = t[i];
            track = i;
        }
    }
    sort(ar, ar+maxi);

    if(listen[track]==2)
        reverse(ar, ar+maxi);
    //deb(maxi, track);
    for( i = track; i<m; i=track)
    {
        //deb(i, t[i], listen[i], listen[track]);
        maxi = -1;
        //deb(i, track);
        for(j=i+1; j<m; j++)
        {
            if(maxi<=t[j])
            {
                maxi = t[j];
                track = j;
            }
        }
        //deb(i, track, maxi);
        if(maxi==-1) break;
        //if(t[i]==t[track])
          //  continue;
        if(listen[i]==listen[track])
            continue;
        else
        {
           // ok
            reverse(ar, ar+maxi);
        }
        //deb(i, track);
        //i = track+1;
    }
    for(i=0; i<n; i++)
        cout << ar[i] << " ";
    NL;
    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}


