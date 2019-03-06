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
#define csi                                         pf("Case %d: ", ++keis)
#define csll                                         pf("Case %lld: ", ++keis)

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
class DATA
{
public:
    int v[5][5];
    DATA operator *(const DATA &a)
    {
        DATA t;
        int i, j, k;
        for(i=1; i<4; i++)
            for(j=1; j<4; j++)
            {
                t.v[i][j] = 0;
                for(k=1; k<4; k++)
                {
                    t.v[i][j]+=(v[i][k]*a.v[k][j]);
                    t.v[i][j]%=10007;
                }
            }
        return t;
    }
    void SHOW()
    {
        int i, j;
        for(i=1; i<4; i++, NL)
            for(j=1; j<4; j++)
                cout << v[i][j] << " ";
        return;
    }
}ans, u0, p;

DATA BIGMOD(DATA &mat, int n)
{
    if(n==1)
        return mat;
    DATA temp;
    temp = BIGMOD(mat, n/2);
    temp = temp*temp;
    if(n&1)
        temp = mat*temp;
    return temp;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int i, to, j, keis= 0, n;
    u0.v[1][1] = 2;
    u0.v[1][2] = 0;
    u0.v[1][3] = 1;
    u0.v[2][1] = 1;
    u0.v[2][2] = 0;
    u0.v[2][3] = 0;
    u0.v[3][1] = 0;
    u0.v[3][2] = 1;
    u0.v[3][3] = 0;

    takei(to);
    while(to--)
    {
        takei(n);
        csi;
        if(n<4)
        {
            if(n==1) pf("1\n");
            else if(n==2) pf("2\n");
            else pf("5\n");
            continue;
        }
       // ok u0.SHOW() ; ok
        ans = BIGMOD(u0, n-3);
        //ok ans.SHOW();
        //ans = u0;
        pf("%d\n", (5*ans.v[1][1]+2*ans.v[1][2]+ans.v[1][3])%10007);
    }

    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}


