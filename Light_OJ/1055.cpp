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
bool dp[11][11][11][11][11][11];
int n, tt[7], pp[7];
char mat[11][11];
bool VALID(int a, int b)
{
    if(a==-1 or b==-1 or a==n or b==n) return false;
    return true;
}
bool ANSWER(int aa,int  bb,int  cc,int  dd,int  ee,int  ff)
{
    if(aa==tt[0] and bb==tt[1] and cc==tt[2] and dd==tt[3] and ee==tt[4] and ff==tt[5]) return true;
    if(aa==tt[0] and bb==tt[1] and ee==tt[2] and ff==tt[3] and cc==tt[4] and dd==tt[5]) return true;
    if(cc==tt[0] and dd==tt[1] and aa==tt[2] and bb==tt[3] and cc==tt[4] and dd==tt[5]) return true;
    if(cc==tt[0] and dd==tt[1] and ee==tt[2] and ff==tt[3] and aa==tt[4] and bb==tt[5]) return true;
    if(ee==tt[0] and ff==tt[1] and aa==tt[2] and bb==tt[3] and cc==tt[4] and dd==tt[5]) return true;
    if(ee==tt[0] and ff==tt[1] and cc==tt[2] and dd==tt[3] and aa==tt[4] and bb==tt[5]) return true;
    return false;
}

int BFS()
{
    CLR(dp);
    queue <int> qu;
    qu.push(pp[0]);
    qu.push(pp[1]);
    qu.push(pp[2]);
    qu.push(pp[3]);
    qu.push(pp[4]);
    qu.push(pp[5]);
    qu.push(0);
    dp[pp[0]][pp[1]][pp[2]][pp[3]][pp[4]][pp[5]] = 1;
    int a, b, c, d, e, f, aa, bb, cc, dd, ee, ff, lev, i, ok1, ok2, ok3;
    while(qu.size())
    {
        a = qu.front(); qu.pop();
        b = qu.front(); qu.pop();
        c = qu.front(); qu.pop();
        d = qu.front(); qu.pop();
        e = qu.front(); qu.pop();
        f = qu.front(); qu.pop();
        lev = qu.front(); qu.pop();
        for(i=0; i<4; i++)
        {
            aa = a+xx[i];
            bb = b+yy[i];
            cc = a+xx[i];
            dd = b+yy[i];
            ee = a+xx[i];
            ff = b+yy[i];
            ok1 = ok2 = ok3 = 0;
            if(VALID(aa, bb)) ok1 = 1;
            if(VALID(cc, dd)) ok2 = 1;
            if(VALID(ee, ff)) ok3 = 1;
            if(ok1+ok2+ok3==3 and !dp[aa][bb][cc][dd][ee][ff])                 /// Everyone is movable
            {
                dp[aa][bb][cc][dd][ee][ff] = 1;
                {
                    if(ANSWER(aa, bb, cc, dd, ee, ff))
                        return lev+1;
                    qu.push(aa);
                    qu.push(bb);
                    qu.push(cc);
                    qu.push(dd);
                    qu.push(ee);
                    qu.push(ff);
                    qu.push(lev+1);
                }
                continue;
            }
        }
    }
    return -5;
}


int main()
{
    ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
    //clock_t ooo = clock();
#endif
    ///                                    MAIN
    int i, t, j, k, l,  keis(0), c, d, x, y, a, b;
//    char pp[100];
//    fgets(pp, 100, stdin);
    takei(t);
    while(t--)
    {
        takei(n);
        getchar();
        a = b = 0;
        for(i=0; i<n; i++)
        {
            sf("%s", mat[i]);
            for(j=0; j<n; j++)
            {
                if(mat[i][j]>='A' and mat[i][j]<='C')
                {
                    pp[a++] = i;
                    pp[a++] = j;
                }
                else if(mat[i][j]=='X')
                {
                    tt[a++] = i;
                    tt[a++] = j;
                }
            }
        }
        a = BFS();
        csi;
        _(a);
    }
    /* Coding is FUN  */
    ///                                    ENDD
#ifndef ONLINE_JUDGE
    //pf("-------ENDS OF OUTPUT------\n\n");
    //pf("Time Elapsed: %lu\n", (clock()-ooo));
#endif
    return 0;
}



