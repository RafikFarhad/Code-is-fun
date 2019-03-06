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
pair <vector <int> , int> v[35];
int dir[35], dp[35], n, k;

bool CHECK(vector <int> p, vector <int> q)
{
    int i, l = p.size();
    for(i=0; i<l; i++)
        if(p[i]>=q[i])
            return false;
    return true;
}

int LIS(int x)
{
    if(x==k) return 0;
    int &ret = dp[x];
    if(~ret) return ret;
    ret = 0;
    int i;
    for(i=x+1; i<k; i++)
    {
        if(CHECK(v[x].first,v[i].first))
        {
            if(LIS(i)>ret)
            {
                ret = LIS(i);
                dir[x] = i;
            }
        }
    }
    ret++;
    return ret;
}

void PRINT(int x, int t)
{
    if(x==-1) return;
    if(!t) pf("%d", v[x].second+1);
    else pf(" %d", v[x].second+1);
    PRINT(dir[x], 1);
    return;
}

int main()
{
    //ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int i, t, j, l,  keis=0, a, b, c, d, x, y;
    vector <int> dummy;
    while(sf("%d%d", &k, &n)!=EOF)
    {
        for(i=0; i<k; i++)
        {
            v[i] = {dummy, i};
            for(j=0; j<n; j++)
            {
                takei(a);
                v[i].first.pb(a);
            }
            sort(all(v[i].first));
        }
        sort(v, v+k);
        /*for(i=0; i<k; i++)
        {
            for(j=0; j<n; j++)
                cout << v[i].first[j] << " ";
            NL;
        }*/
        CLR1(dp);
        int res = 0, start = -1;
        for(i=0; i<k; i++)
        {
            a = LIS(i);
            if(a>res)
            {
                res = a;
                start = i;
            }
        }
        CLR1(dir);
        CLR1(dp);
        LIS(start);
        //deb(res, start);
        _(res);
        PRINT(start, 0);
        NL;
    }
    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}



