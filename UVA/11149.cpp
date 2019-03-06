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
#define takellu(a)                               scanf("%llu", &a)
#define sf                                          scanf
#define pb                                         push_back
//#define mp                                         make_pair
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
long long int POOW(long long b, long long p) { if(p==0) return 1; return b*POOW(b, p-1);}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1}; const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define SIZE INT_MAX
long long MOD=10, c[25], k, in[25], n;
class DATA
{
public:
    long long v[50][50];
    long long row, col;
    void SHOW()
    {
        int i, j;
        for(i=1; i<=row; i++, NL)
            for(j=1; j<=col; j++)
                if(j==col) pf("%lld", v[i][j]);
                else pf("%lld ", v[i][j]);
        return;
    }
};
map <int, DATA> mp;

DATA GUNON(DATA a, DATA b)
{
    int i, j, k;
    DATA temp;
    temp.row = a.row;
    temp.col = b.col;
    for(i=1; i<=a.row;i++)
    {
        for(j=1; j<=b.col; j++)
        {
            temp.v[i][j] = 0;
            for(k=1; k<=a.col; k++)
            {
                temp.v[i][j] += ((a.v[i][k] * b.v[k][j])%MOD);
                temp.v[i][j] %= MOD;
            }
        }
    }
    return temp;
}

DATA JOOG (DATA a, DATA b)
{
    int i, j;
    for(i=1; i<=a.row;i++)
    {
        for(j=1; j<=a.col; j++)
        {
            a.v[i][j]+=b.v[i][j];
            a.v[i][j]%=MOD;
        }
    }
    return a;
}

DATA BIGMOD(DATA mat, long long p)
{
    if(p==1) return mat;
    DATA temp;

    temp = BIGMOD(mat, p/2);
    temp = GUNON(temp, temp);
    if(p&1)
        temp = GUNON(mat, temp);
    return temp;
}

DATA BIGMOD_PLUS_PLUS(DATA mat, long long p)
{
    if(p==1) return mat;
    DATA temp;
    DATA temp1;
    temp1 = BIGMOD(mat, p/2);
    temp = BIGMOD_PLUS_PLUS(mat, p/2);
    temp = JOOG(temp, GUNON(temp, temp1));
    if(p&1)
        temp = JOOG(mat, GUNON(temp, mat));
    return temp;
}
int main()
{
#ifndef ONLINE_JUDGE
   freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    long long i, j, t;


    while(sf("%lld %lld", &n, &k)==2 and n)
    {
        //deb(n, k);
        DATA mat;
        mat.row = mat.col = n;
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
            {
                takell(mat.v[i][j]);
                mat.v[i][j]%=10;
            }
        }
        mp.clear();
        DATA ans = BIGMOD_PLUS_PLUS(mat, k);
        /*for(i=2; i<=k; i++)
        {
            ans = JOOG(ans , BIGMOD(mat, k));
        }*/
        ans.SHOW();
        NL;
    }

    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}






