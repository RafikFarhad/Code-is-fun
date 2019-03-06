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
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1}; const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define SIZE INT_MAX
int n, MOD, m, r, c;
/*
class DATA
{
public:
    int row, col, v[50][50];
    void SHOW()
    {
        int i, j;
        for(i=1; i<=row; i++, NL)
            for(j=1; j<=col; j++)
                cout << v[i][j] << " ";
        return;
    }
    DATA operator * (const DATA &b) const
    {
        int i, j, k, s;
        DATA temp;
        temp.row = row;
        temp.col = b.col;
        for(i=1; i<=row; i++)
        {
            for(j=1; j<=b.col; j++)
            {
                s = 0;
                for(k=1; k<=col; k++)
                {
                    s = s + (v[i][k]*b.v[k][j]);
                }
                temp.v[i][j] = s;
            }
        }
        return temp;
    }
};*/

int v[100][100];
bool flag[100], mark;
vector <int> p;
void GO(int x, int c)
{
    if(c==n)
    {
        mark = 1;
        pf("(");
        for(int i=0; i<=c; i++)
            if(i) pf(",%d", p[i]);
            else pf("%d", p[i]);
        pf(")\n");
        return;
    }
    for(int i=1; i<=r; i++)
    {
        if(v[x][i] and flag[i]==0)
        {
            p.pb(i);
            flag[i] = 1;
            GO(i, c+1);
            p.pop_back();
            flag[i] = 0;
        }
    }
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
    int i, t, j, k, l,  keis=0, a, b, d, x, y;
    while(sf("%d%d", &r, &n)!=EOF)
    {
        CLR(v);
        mark = 0;
        if(keis++) NL;
        for(i=1; i<=r; i++)
        {
            for(j=1; j<=r;j++)
            {
                takei(a);
                v[i][j] = a;
            }
        }
        CLR(flag);
        for(i=1; i<=1; i++)
        {
            flag[i] = 1;
            p.clear();
            p.pb(i);
            GO(i, 0);
        }
        if(!mark) pf("no walk of length %d\n", n);
        takei(a);
    }
    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}



