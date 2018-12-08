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
///
const int xx[] = {0,0, 0, 1, -1, -1, 1, -1, 1, 0};
const int yy[] = {0,1, -1, 0, 0, 1, 1, -1, -1, 0};
//const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define LT (1<<31)-1
#define MX
#define MOD
#define MY INT_MIN
//ll FAST_EXP(ll base, ll power) /*base^power%MOD*/   {ll res=1ll;while(power){if(power&1)res=(res*base)%MOD;base=(base*base)%MOD;power>>=1;}return res%MOD;}
string ab[] =  {"*", "R", "L", "D", "U", "UR", "DR", "UL", "DL", "*"};
char mat[32][32], qu[20];
int r, c, l;
vector <int> ans;
bool knok_knok;
int vis[32][32][32];
bool DFS(int x, int y, int pos);
void BACK_TRACK(int x, int y, int pos)
{
    if(pos==l-1)
    {
        knok_knok = true;
        pf("%s found: (%d,%d)", qu, ans[0], ans[1]);
        for(int i=2; i<ans.size(); i++)
        {
            //if(ans[i-1]==ans[i] and ans[i]==8 and i>2) continue;
            pf(", %s",ab[ans[i]].c_str());
        }
        NL;
        return;
    }
    int u, v, i;
    for(i=0; i<9 and !knok_knok; i++)
    {
        u = x+xx[i];
        v = y+yy[i];
        if(u==-1 or v==-1 or u==r or v==c or mat[u][v]!=qu[pos+1]) continue;
        //deb(i, qu[pos+1]);
        //deb(x+1, y+1, xx[i], yy[i]);
        if(DFS(u, v, pos+1)==false) continue;
        ans.pb(i);
        BACK_TRACK(u, v, pos+1);
        ans.pop_back();
    }
    return;
}

bool DFS(int x, int y, int pos)
{
    if(vis[x][y][pos]!=-1) return vis[x][y][pos];
    if(pos==l-1)
    {
        return vis[x][y][pos]=true;
    }
    int u, v, i;
    for(i=0; i<9; i++)
    {
        u = x+xx[i];
        v = y+yy[i];
        if(u==-1 or v==-1 or u==r or v==c or mat[u][v]!=qu[pos+1]) continue;
        //deb(i, qu[pos+1]);
        //deb(x+1, y+1, xx[i], yy[i]);
        //ans.pb(i);
        if(DFS(u, v, pos+1)) return vis[x][y][pos] = true;
        //ans.pop_back();
    }
    return vis[x][y][pos] = false;
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
    int i, t, j, k,  keis(0), d, x, y, a, b;
//    char pp[100];
//    fgets(pp, 100, stdin);
    takei(t);
    while(t--)
    {
        takei(r);
        takei(c);
        getchar();
        for(i=0; i<r; i++)
        {
            sf("%s", mat[i]);
        }
        csii;
        takei(a);
        getchar();
        while(a--)
        {
            sf("%s", qu);
            l = strlen(qu);
            ans.clear();
            for(i=0; i<r; i++)
            {
                for(j=0; j<c; j++)
                {
                    knok_knok = false;
                    if(mat[i][j]==qu[0])
                    {
                        CLR1(vis);
                        if(DFS(i, j, 0)==false) continue;
                        knok_knok = false;
                        ans.clear();
                        ans.pb(i+1);
                        ans.pb(j+1);
                        BACK_TRACK(i, j, 0);
                        if(knok_knok)
                        {
                            i = j = r+c;
                        }
                    }
                }
            }
            if(!knok_knok)
            {
                pf("%s", qu);
                pf(" not found\n");
            }
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



