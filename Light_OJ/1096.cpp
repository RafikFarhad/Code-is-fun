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
long long int POOW(long long b, long long p) { if(p==0) return 1; return b*POOW(b, p-1);}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1}; const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define SIZE INT_MAX
long long MOD=10007;
class DATA
{
public:
    long long v[5][5];
    long long row, col;
    void SHOW()
    {
        int i, j;
        for(i=1; i<=row; i++, NL)
            for(j=1; j<=col; j++)
                cout << v[i][j] << "   ";
        return;
    }
};

DATA T, init, ans;
long long n, m;

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

int main()
{
#ifndef ONLINE_JUDGE
   freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    long long i, j, t,a , b, c, keis=0;

    takell(t);
    while(t--)
    {
        takell(n);
        takell(a);
        takell(b);
        takell(c);
        pf("Case %lld: ", ++keis);
        if(n<3)
        {
            pf("0\n");
            continue;
        }
        T.row = 4;
        T.col = 4;

        for(i=1; i<=T.row; i++)
            for(j=1; j<=T.col; j++)
                T.v[i][j] = 0;

        T.v[1][1] = a%MOD;
        T.v[1][2] = 0;
        T.v[1][3] = b%MOD;
        T.v[1][4] = 1;

        for(i=2; i<T.row; i++)
        {
            T.v[i][i-1] = 1;
        }
        T.v[T.row][T.col] = 1;
        //T.SHOW();NL;
        ans = BIGMOD(T, n-2);
       // ans.SHOW();NL;
        init.row = 4;
        init.col = 1;

        for(i=3; i>=1; i--)
        {
            init.v[i][1] = 0;
        }
        init.v[4][1] = c%MOD;
       //init.SHOW();NL;
       // deb(ans.row, ans.col);

        ans = GUNON(ans, init);
        //deb(ans.row, ans.col);
        //for(i=1; i<=ans.row; i++, NL)
            //cout << ans.v[i][1];
        //ans.SHOW();NL;
        pf("%lld\n", ans.v[1][1]%MOD);

    }

    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}





