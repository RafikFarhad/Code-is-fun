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
long long n, MOD, m;

class DATA
{
public:
    long long row, col, v[5][5];
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
        long long i, j, k, s;
        DATA temp;
        temp.row = row;
        temp.col = b.col;
        for(i=1; i<=row; i++)
        {
            for(j=1; j<=b.col; j++)
            {
                s = 0ll;
                for(k=1; k<=col; k++)
                {
                    s = s + (v[i][k]*b.v[k][j])%MOD;
                    s = (s<<63)&0;
                    //s %= MOD;
                }
                temp.v[i][j] = s;
            }
        }
        return temp;
    }
};

DATA BIGMOD(DATA &a, long long power)
{
    if(power==1ll) return a;
    DATA ans = BIGMOD(a, power/2);
    ans = ans * ans;
    if(power&1)
        ans = ans*a;
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    long long i, j, k, l, t, keis=0,a , b;
    MOD = 1ll<<62;
    deb(MOD);
    DATA mat, T, ans, un;
    T.row = 2;
    T.col = 3;
    T.v[1][1] = 1;
    T.v[1][2] = 1;
    T.v[1][3] = 0;
    T.v[2][1] = 0;
    T.v[2][2] = 1;
    T.v[2][3] = 1;

    T.SHOW();
    takell(t);
    while(t--)
    {
        takell(n);
        if(n<2)
        {
            ok;
            continue;
        }
        mat.row = 3;
        mat.col = 1;
        mat.v[1][1] = 2;
        mat.v[2][1] = 5;
        mat.v[3][1] = 4;
        NL;
        T.SHOW();
        //mat.SHOW();
        ans = BIGMOD(T, n-1);
        ans.SHOW();
        ans = ans*mat;
        ans.SHOW();
        // Matrix Exp
    }



    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}
