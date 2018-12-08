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
/** Author      : Rafik Farhad            */
/** Mail to     : rafikfarhad@gmail.com   */
/******************************************/
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
template <class T> T MAX(T a, T b) { return a>b?a:b;}template <class T> T MIN(T a, T b) { return a<b?a:b;}
template <class T1> void __(T1 p) { cout << p << endl;}
template <class T1> void deb(T1 p) { cout << "Debugging: " << p << endl;}
template <class T1, class T2> void deb(T1 p, T2 q) { cout << "Debugging: " << p << "\t" << q  << endl;}
template <class T1, class T2, class T3> void deb(T1 p, T2 q, T3 r) { cout << "Debugging: " << p << "\t " << q << "\t " << r << endl;}
template <class T1, class T2, class T3, class T4> void deb(T1 p, T2 q, T3 r, T4 s) { cout << "Debugging: " << p << "\t " << q << "\t " << r << "\t " << s << endl;}
long long int POOW(long long b, long long p) { if(p==0) return 1; return b*POOW(b, p-1);}
//int SET(int mask, int pos){return mask(1<<pos);}
//bool CHK(int mask, int pos){return (1&(mask>>pos));}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1}; const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define LT (1<<31)-1
#define MX
#define MOD
#define MY INT_MIN
//ll FAST_EXP(ll base, ll power) /*base^power%MOD*/   {ll res=1ll;while(power){if(power&1)res=(res*base)%MOD;base=(base*base)%MOD;power>>=1;}return res%MOD;}

int match[3][105], f, d, n;
bool flag[3][105];
vector < pair<int, int> > mat[105];


bool DFS(int x)
{
    int i, j, k;
    for(i=0; i<mat[x].size(); i++)
    {
        if(flag[0][mat[x][i].xx]==0 and flag[1][mat[x][i].yy]==0)
        {
            flag[0][mat[x][i].xx] = 1;
            flag[1][mat[x][i].yy] = 1;
            if(match[0][mat[x][i].xx]==-1 and match[1][mat[x][i].yy]==-1)
            {
                match[0][mat[x][i].xx]= x;
                match[1][mat[x][i].yy]= x;
                return true;
            }
            else if(match[0][mat[x][i].xx]==-1)
            {
                match[0][mat[x][i].xx] = x;
                bool temp = DFS(match[1][mat[x][i].yy]);
                if(temp)
                {
                    match[0][mat[x][i].xx]= x;
                    match[1][mat[x][i].yy]= x;
                    return true;
                }
                match[0][mat[x][i].xx]= -1;
            }
            else if(match[1][mat[x][i].yy]==-1)
            {
                match[1][mat[x][i].yy]= x;
                bool temp = DFS(match[0][mat[x][i].xx]);
                if(temp)
                {
                    match[0][mat[x][i].xx]= x;
                    match[1][mat[x][i].yy]= x;
                    return true;
                }
                match[1][mat[x][i].yy]= -1;
            }
            else
            {
//                int dd = match[0][mat[x][i].xx];
//                match[0][mat[x][i].xx] = x;
//                int ef = match[1][mat[x][i].yy];
//                match[1][mat[x][i].yy]= x;
                bool temp = DFS(match[1][mat[x][i].yy]);
                bool temp2 = DFS(match[0][mat[x][i].xx]);
                if(temp and temp2)
                {
                    match[0][mat[x][i].xx]= x;
                    match[1][mat[x][i].yy]= x;
                    return true;
                }
//                match[0][mat[x][i].xx]= dd;
//                match[1][mat[x][i].yy]= ef;
            }
//            if(DFS(match[mat[x][i]]))
//            {
//                match[mat[x][i]] = x;
//                return true;
//            }
        }
    }
    return false;
}
int BPM()
{
    CLR1(match);
    int a = 0;
    for(int i=1; i<=n; i++)
    {

        CLR(flag);
        if(DFS(i))
            a++;

    }
    return a;
}

int main()
{
    //ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
    //clock_t ooo = clock();
#endif
    ///                                    MAIN
    int i, t, j, k, l,  keis(0), c, x, y, a, b;
//    char pp[100];
//    fgets(pp, 100, stdin);
    int ar[200];
    takei(n);
    takei(f);
    takei(d);
    for(i=1; i<=n; i++)
    {
        takei(a);
        takei(b);
        //deb("*******", a, b);
        for(j=0; j<a; j++)
            takei(ar[j]);
        for(j=0; j<b; j++)
        {
            takei(c);
            for(k=0; k<a; k++)
            {
                if(ar[k]<=f and c<=d)
                    mat[i].pb(make_pair(ar[k], c));
                //deb(ar[k], c);
            }
        }
    }
    pf("%d\n", BPM());
//    for(i=1; i<=f; i++)
//        deb("food:", i, match[0][i]);
//    for(i=1; i<=d; i++)
//        deb("drink:", i, match[0][i]);



    /* Coding is FUN  */
    ///                                    ENDD
#ifndef ONLINE_JUDGE
    //pf("-------ENDS OF OUTPUT------\n\n");
    //pf("Time Elapsed: %lu\n", (clock()-ooo));
#endif
    return 0;
}



