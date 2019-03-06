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
long long MOD=10ll, k, n;
class DATA
{
public:
    long long v[50][50];
    long long row, col;
    /*void SHOW()
    {
        int i, j;
        for(i=1; i<=row; i++, NL)
            for(j=1; j<=col; j++)
                pf("%lld", v[i][j]);

        return;
    }*/
};

DATA one, mat, ans;

DATA GUNON(DATA a, DATA b)
{
    int i, j, k;
    DATA temp;

    for(i=1; i<=n;i++)
    {
        for(j=1; j<=n; j++)
        {
            temp.v[i][j] = 0;
            for(k=1; k<=n; k++)
            {
                temp.v[i][j] += ((a.v[i][k] * b.v[k][j])%10);
                temp.v[i][j] %= 10;
            }
        }
    }
    return temp;
}

DATA JOOG (DATA a, DATA b)
{
    int i, j;
    DATA temp;
    temp.row = temp.col = n;
    for(i=1; i<=n;i++)
    {
        for(j=1; j<=n; j++)
        {
            temp.v[i][j] = a.v[i][j] + b.v[i][j];
            temp.v[i][j]%=10;
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

DATA BIGMOD_PLUS_PLUS(DATA mat, long long p)
{
    if(p==1) return mat;
    DATA temp, temp1, temp2;
    if(p&1)
    {
        temp = JOOG(BIGMOD_PLUS_PLUS(mat, p-1), BIGMOD(mat, p));
    }
    else
    {
        temp = GUNON(BIGMOD_PLUS_PLUS(mat, p/2), JOOG(one, BIGMOD(mat, p/2)));
    }
    return temp;
}

int main()
{
#ifndef ONLINE_JUDGE
   freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    long long i, j, t, keis = 0;;
    for(i=1; i<35; i++)
    {
        for(j=1; j<35; j++)
        {
            one.v[i][j]=0;
            if(i=j)
                one.v[i][j] = 1;
        }
    }
    takell(t);
    while(t--)
    {
        //deb(n, k);
        sf("%lld %lld", &n, &k);
        pf("Case %lld:\n", ++keis);
        //DATA mat;
        mat.row = mat.col = one.row = one.col = n;
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
            {
                takell(mat.v[i][j]);
            }
        }
        ans = BIGMOD_PLUS_PLUS(mat, k);
        /*for(i=2; i<=k; i++)
        {
            ans = JOOG(ans , BIGMOD(mat, k));
        }*/
        //ans.SHOW();
        for(i=1; i<=n; i++, NL)
            for(j=1; j<=n; j++)
                pf("%lld", ans.v[i][j]%10);
    }

    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}

/*3
1 1059
0



3 10

1 4 6

6 5 2

1 2 3
3 2

1 4 6

6 5 2

1 2 3
*/
