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
    unsigned long long v[5][5];
    int row, col;
    DATA operator * (const DATA &a)
    {
        DATA temp;
        temp.row = row;
        temp.col = a.col;
        int i, j, k;
        for(i=1; i<=row; i++)
            for(j=1; j<=a.col; j++)
            {
                temp.v[i][j] = 0llu;
                for(k=1; k<=col; k++)
                {
                    temp.v[i][j]+=(v[i][k]*a.v[k][j]);
                }
            }
        return temp;
    }
    void SHOW()
    {
        int i, j;
        for(i=1; i<=row; i++, NL)
            for(j=1; j<=col; j++)
                cout << v[i][j] << " ";
    }
}u, ans, t;
unsigned long long p, q, n;

DATA BIGMOD(DATA &mat, long long unsigned p)
{
    if(p==1) return mat;
    DATA temp = BIGMOD(mat, p/2);
    temp = temp*temp;
    if(p&1)
    {
        temp = mat*temp;
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
    int i, j, k, l, to, keis=0;
    takei(to);
    while(to--)
    {
        takellu(p);
        takellu(q);
        takellu(n);
        if(n<2)
        {
            if(n==0)
            {
                csi;
                pf("2\n");
                continue;
            }
            else
            {
                csi;
                pf("%llu\n", p);
                continue;
            }

        }
        csi;
        t.row = t.col = 2;
        u.row = 2;
        u.col = 1;
        t.v[1][1] = p;
        t.v[1][2] = -q;
        t.v[2][1] = 1llu;
        t.v[2][2] = 0llu;
        u.v[1][1] = p;
        u.v[2][1] = 2llu;
        //t.SHOW();NL;
       // u.SHOW();NL;
       // ok
        ans = BIGMOD(t, n-1);
        //ans.SHOW();NL;

        //ans = ans*u;
        pf("%llu\n", ans.v[1][1]*p+ans.v[1][2]*2llu);
        //ans.SHOW();
    }

    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}


