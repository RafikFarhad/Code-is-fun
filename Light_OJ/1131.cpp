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
#define takei(a)                                 scanf("%d", &a)
#define takell(a)                                scanf("%lld", &a)
#define takellu(a)                               scanf("%I64uu", &a)
#define sf                                          scanf
#define pb                                         push_back
#define mp                                         make_pair
#define ppp                                       system("pause")
#define ok                                         cout << "OK" <<endl;
#define pf                                         printf
#define NL                                        printf("\n")
#define PI                                         2*acos(0)
#define all(o)                                      o.begin(), o.end()

///Helper
using namespace std;
template <class T> T MAX(T a, T b) { return a>b?a:b;}template <class T> T MIN(T a, T b) { return a<b?a:b;}
template <class T1> void deb(T1 p) { cout << "Debugging: " << p << endl;}
template <class T1, class T2> void deb(T1 p, T2 q) { cout << "Debugging: " << p << "\t" << q  << endl;}
template <class T1, class T2, class T3> void deb(T1 p, T2 q, T3 r) { cout << "Debugging: " << p << "\t " << q << "\t " << r << endl;}
template <class T1, class T2, class T3, class T4> void deb(T1 p, T2 q, T3 r, T4 s) { cout << "Debugging: " << p << "\t " << q << "\t " << r << "\t " << s << endl;}
long long int POOW(long long  b, long long p) { if(p==0) return 1; return b*POOW(b, p-1);}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1}; const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define SIZE INT_MAX
long long n, MOD, m;

class DATA
{
public:
    long long row, col, v[50][50];
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
                    s = s + (v[i][k]*b.v[k][j])%MOD;
                    s %= MOD;
                }
                temp.v[i][j] = s;
            }
        }
        return temp;
    }
};

DATA BIGMOD(DATA &a, long long power)
{
    if(power==1) return a;
    DATA ans = BIGMOD(a, power/2);
    ans = ans * ans;
    if(power&1)
        ans = ans*a;
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    long long i, qu, j, k, l, t, keis=0, a1 , b1, c1, a2, b2, c2, f0, f1, f2, g0, g1, g2;
    DATA mat, T, ans;
    takell(t);
    while(t--)
    {
        takell(a1);
        takell(b1);
        takell(c1);
        takell(a2);
        takell(b2);
        takell(c2);
        takell(f0);
        takell(f1);
        takell(f2);
        takell(g0);
        takell(g1);
        takell(g2);
        takell(MOD);
        takell(qu);
        T.row = T.col = 6;
        for(i=1; i<=6; i++)
            for(j=1; j<7; j++)
            {
                T.v[i][j] = 0;
                if(i-1==j)
                    T.v[i][j] = 1;
            }
        T.v[1][1] = a1%MOD;
        T.v[1][2] = b1%MOD;
        T.v[1][6] = c1%MOD;
        T.v[4][3] = c2%MOD;
        T.v[4][4] = a2%MOD;
        T.v[4][5] = b2%MOD;
        //T.SHOW();
        mat.row = 6;
        mat.col = 1;
        mat.v[1][1] = f2%MOD;
        mat.v[2][1] = f1%MOD;
        mat.v[3][1] = f0%MOD;
        mat.v[4][1] = g2%MOD;
        mat.v[5][1] = g1%MOD;
        mat.v[6][1] = g0%MOD;
        //mat.SHOW();
        pf("Case %lld:\n", ++keis);
        while(qu--)
        {
            takell(n);
            if(n<3)
            {
                pf("%lld %lld\n", mat.v[3-n][1], mat.v[6-n][1]);
                continue;
            }
            ans = BIGMOD(T, n-2ll);
            ans = ans*mat;
            pf("%lld %lld\n", ans.v[1][1], ans.v[4][1]);
        }
    }



    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}



