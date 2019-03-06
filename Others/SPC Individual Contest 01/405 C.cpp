/*Winter is coming*/


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
/*****************************************************/
/** Author      : Rafik Farhad                       */
/** Mail        : github.com/RafikFarhad/Code_is_fun */
/** Created on  : 2017-03-18-21.47 _ Saturday       */
/****************************************************/
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
#define csii                                     pf("Case %d:\n", ++keis)
#define _(o)                                    pf("%d\n", o)
#define ll                                      long long
#define ull                                     unsigned long long
#define exx                                     2.7182818284590452353602875
#define xx                                      first
#define yy                                      second

///Helper
using namespace std;
template <class T> T MAX(T a, T b)
{
    return a>b?a:b;
}
template <class T> T MIN(T a, T b)
{
    return a<b?a:b;
}
template <class T1> void __(T1 p)
{
    cout << p << endl;
}
template <class T1> void deb(T1 p)
{
    cout << "Debugging: " << p << endl;
}
template <class T1, class T2> void deb(T1 p, T2 q)
{
    cout << "Debugging: " << p << "\t" << q  << endl;
}
template <class T1, class T2, class T3> void deb(T1 p, T2 q, T3 r)
{
    cout << "Debugging: " << p << "\t " << q << "\t " << r << endl;
}
template <class T1, class T2, class T3, class T4> void deb(T1 p, T2 q, T3 r, T4 s)
{
    cout << "Debugging: " << p << "\t " << q << "\t " << r << "\t " << s << endl;
}
long long int POOW(long long b, long long p)
{
    if(p==0) return 1;
    return b*POOW(b, p-1);
}
//int SET(int mask, int pos){return mask  singlebar  (1<<pos);}
//bool CHK(int mask, int pos){return (1&(mask>>pos));}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};
const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1};
const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define LT (1<<31)-1
#define MX
#define MOD
#define MY INT_MIN
//ll FAST_EXP(ll base, ll power) /*base^power%MOD*/   {ll res=1ll;while(power){if(power&1)res=(res*base)%MOD;base=(base*base)%MOD;power>>=1;}return res%MOD;}


int main()
{
    //ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("/home/looser/Desktop/000.txt","r",stdin);
    //freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
    //clock_t ooo = clock();
#endif
    ///                                    MAIN
    int i, t, j, k, l,  keis(0), c, d, x, y, a, b, n;
//    char pp[100];
//    fgets(pp, 100, stdin);
    string test[600], st, ans[55];
    int mm = 0;
    for(i=0; i<26; i++)
    {
        for(j=0; j<26; j++)
        {
            //deb(i, j,mm);
            if(mm==600) break;
            test[mm] = "  ";
            test[mm][0] = 'A'+i;
            test[mm][1] = 'a'+j;
            //deb(test[mm]);
            mm++;
        }
        if(mm==600) break;

    }
    int ar[55];
    while(cin >> n >> k)
    {
        for(i=0; i<n-k+1; i++)
        {
            cin >> st;
            if(st=="YES")
                ar[i] = 1;
            else
                ar[i] = 0;
           // deb(i, st, ar[i]);
        }
        for(i=0; i<n; i++)
            ans[i] = "Zz";
        mm = 0;

        for(i = 0; i<n-k+1; i++)
        {
            if(ar[i]==1)
            {
                for(j=i; j<i+k; j++)
                {
                    if(ans[j]!="Zz") continue;
                    ans[j] = test[mm++];
                }
            }
        }
        for(i=0; i<n; i++)
        {
            if(ans[i]!="Zz")
            {
                string in = ans[i];
                for(j=i-1; j>=0; j--)
                {
                    if(ans[j]!="Zz")
                        break;
                    ans[j] = in;
                }
                for(j=i+1; j<n; j++)
                {
                    if(ans[j]!="Zz")
                        break;
                    ans[j] = in;
                }

            }
        }


        int br[55];
        for(i = 0; i<n-k+1; i++)
        {
            for(j=i+1; j<i+k; j++)
            {
                if(ans[j]==ans[j-1])
                    break;
            }
            if(j==i+k)
                br[i] = 1;
            else br[i] = 0;;
        }
        for(i = 0; i<n-k+1; i++)
        {
            if(br[i]!=ar[i])
            {
                deb(i, i+k-1);
                ans[i] = ans[i+k-1];
            }
        }
        for(i=0; i<n; i++)
        {
            if(i) pf(" ");
            cout << ans[i];
        }
        NL;

                                                                                                    #ifndef ONLINE_JUDGE
                                                                                                                    for(i = 0; i<n-k+1; i++)
                                                                                                                    {
                                                                                                                        for(j=i+1; j<i+k; j++)
                                                                                                                        {
                                                                                                                            if(ans[j]==ans[j-1])
                                                                                                                                break;
                                                                                                                        }
                                                                                                                        if(j==i+k)
                                                                                                                            pf("YES ");
                                                                                                                        else pf("NO ");
                                                                                                                    }
                                                                                                                    NL;
                                                                                                                    //pf("-------ENDS OF OUTPUT------\n\n");
                                                                                                                    //pf("Time Elapsed: %lu\n", (clock()-ooo));
                                                                                                            #endif
    }

    /* Coding is FUN  */
    ///                                    ENDD

    return 0;
}




