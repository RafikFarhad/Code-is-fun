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
long long int POOW(int b, int p) { if(p==0) return 1; return b*POOW(b, p-1);}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1}; const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define SIZE INT_MAX
long long MOD;
class DATA
{
public:
    long long v[5][5];
};

DATA T, init, ans;
long long n, m;

DATA GUNON(DATA a, DATA b)
{
    int i, j, k;
    DATA temp;
    for(i=1; i<3;i++)
    {
        for(j=1; j<3; j++)
        {
            temp.v[i][j] = 0;
            for(k=1; k<3; k++)
            {
                temp.v[i][j] += (a.v[i][k] * b.v[k][j]);
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
    //freopen("input.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    long long i, j, k;
    init.v[1][1] = 1;
    init.v[2][1] = 0;
    while(sf("%lld%lld", &n, &m)!=EOF)
    {
        if(n<2)
        {
            if(n==0) pf("0\n");
            else
            {
                pf("%lld\n", 1%POOW((long long)2, (long long)m));
            }
            continue;
        }
        ans.v[1][1] = 0;
        ans.v[1][2] = 0;
        ans.v[2][1] = 0;
        ans.v[2][2] = 0;
        T.v[1][1] = 1;
        T.v[1][2] = 1;
        T.v[2][1] = 1;
        T.v[2][2] = 0;
        MOD = POOW((long long)2, (long long)m);
        ans = BIGMOD(T, n-1);
        //deb(MOD);
       // ans = GUNON(T, T);
       // ans = GUNON(ans, T);
        ans = GUNON(ans, init);
        //deb(ans.v[1][1], ans.v[1][2]);
        //deb(ans.v[2][1], ans.v[2][2]);
        pf("%lld\n", ans.v[1][1]%MOD);

    }

    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}


