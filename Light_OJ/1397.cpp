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
int SET(int mask, int pos){return mask|(1<<pos);}
bool CHK(int mask, int pos){return (1&(mask>>pos));}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1}; const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define LT (1<<31)-1
#define MX
#define MOD
#define MY INT_MIN
//ll FAST_EXP(ll base, ll power) /*base^power%MOD*/   {ll res=1ll;while(power){if(power&1)res=(res*base)%MOD;base=(base*base)%MOD;power>>=1;}return res%MOD;}
int mat[10][10], ar[82][3], khali;
void INIT()
{
    CLR(ar);
    CLR(mat);
    khali = 0;
}

bool CHECK(int r, int c, int val)
{
    int i, j, k, l;
    for(i=0; i<9; i++)
        if(mat[i][c]==val || mat[r][i]==val)
            return false;
    k = r/3*3;
    l = c/3*3;
    for(i=k; i<k+3; i++)
        for(j=l; j<l+3; j++)
            if(mat[i][j]==val)
                return false;
    return true;
}


bool FIND_BEST(int &r, int &c)
{
    int k, i, j,x, best = 100, it;
    for(x=0; x<khali; x++)
    {
        i = ar[x][0];
        j = ar[x][1];
            if(mat[i][j]!=-1) continue;
            it = 0;
            for(k=1; k<10; k++)
            {
                if(CHECK(i, j, k))
                    it++;
            }
//            deb(it, best);
            if(it<best)
            {
                r = i;
                c = j;
                best = it;
            }

    }
//    deb(best);
    return best==100;
}

bool SOLVE()
{
    int r, c;
    if(FIND_BEST(r, c)) return true;
    for(int i=1; i<10; i++)
    {
        if(CHECK(r, c, i))
        {
            mat[r][c] = i;
            if(SOLVE())
                return true;
            mat[r][c] = -1;
        }
    }
    return false;
}

int main()
{
    //ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
    //clock_t ooo = clock();
#endif
    ///                                    MAIN
    int i, t, j, k, l,  keis(0), cm, d, x, y, a, b;
//    char pp[100];
//    fgets(pp, 100, stdin);
    char c, tt[10];
    takei(t);
    while(t--)
    {
        getchar();
        pf("Case %d:\n", ++keis);
        INIT();
        for(i=0; i<9; i++)
        {
            getchar();
            fgets(tt, 10, stdin);
            for(j=0; j<9; j++)
            {
                c = tt[j];
                if(c=='.')
                {
                    mat[i][j] = -1;
                    ar[khali][0]= i;
                    ar[khali++][1]= j;
                }
                else
                    mat[i][j] = c - '0';
            }
        }
        SOLVE();
        for(i=0; i<9; i++)
        {
            for(j=0; j<9; j++)
            {
                pf("%d", mat[i][j]);
            }
            NL;
        }


    }

    /* Coding is FUN  */
    ///                                    ENDD
#ifndef ONLINE_JUDGE
    //pf("-------ENDS OF OUTPUT------\n\n");
    //pf("Time Elapsed: %lu\n", (clock()-ooo));
#endif
    return 0;
}



