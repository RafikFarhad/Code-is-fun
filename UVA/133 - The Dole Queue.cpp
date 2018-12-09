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
#define CLR(o)                                  memset(o, 0, sizeof o)
#define CLR1(o)                                 memset(o, -1, sizeof o)
#define takei(a)                                 scanf("%d", &a)
#define takell(a)                                scanf("%I64d", &a)
#define takellu(a)                               scanf("%I64uu", &a)
#define sf                                          scanf
#define pb                                         push_back
#define mp                                         make_pair
#define ppp                                       system("pause")
#define ok                                         cout << "OK" <<endl;
#define pf                                         printf
#define NL                                        printf("\n")
#define PI                                         2*acos(0)

///Helper
using namespace std;
template <class T> T MAX(T a, T b)
{
    return a>b?a:b;
}
template <class T> T MIN(T a, T b)
{
    return a<b?a:b;
}
template <class T1> void deb(T1 p)
{
    cout << "Debugging: " << p << endl;
}
template <class T1, class T2> void deb(T1 p, T2 q)
{
    cout << "Debugging: " << p << "\t" << q  << endl;
}
template <class T1, class T2, class T3> void deb(T1 p, T2 q, T3 r)
{
    cout << "Debugging: " << p << "\t " << q << "\t " << r << endl;
}
template <class T1, class T2, class T3, class T4> void deb(T1 p, T2 q, T3 r, T4 s)
{
    cout << "Debugging: " << p << "\t " << q << "\t " << r << "\t " << s << endl;
}
long long int POOW(int b, int p)
{
    if(p==0) return 1;
    return b*POOW(b, p-1);
}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};
const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1};
const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define SIZE INT_MAX
bool flag[25];
int n, k,m;

int main()
{
#ifndef ONLINE_JUDGE
    // freopen("000.txt","r",stdin);
   // freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int i, j, l, a, p, b, c, d;
    while(sf("%d %d %d", &n, &k, &m)==3 && n && m && k)
    {
        a = n+1;
        b = 0;
        CLR(flag);
        for(i=0; i<=n; i++) flag[i] = 1;
        for(l=0;  ; l++ )
        {
            for(i=1, p=0; i<=n; i++)
                if(flag[i])
                    p++;
            if(!p) break;

            for(i=a, p=0;  ; i++)
            {
                if(i>n) i = 1;
                if(flag[i])
                    p++;
                if(p==k) break;
            }
            c = i;
            //deb(c);

            for(i=b, p=0; ; i--)
            {
                if(i<=0) i = n;
                if(flag[i])
                    p++;
                if(p==m) break;
            }
            d = i;
            //deb(d);
            if(l) pf(",");
            if(c!=d) pf("%3d%3d", c, d);
            else pf("%3d", c);
            flag[c] = flag[d] = 0;
            a = c+1;
            b = d-1;
        }
        pf("\n");
    }

    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}

