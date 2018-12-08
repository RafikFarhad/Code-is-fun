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
#define _(o)                                    pf("%d", o)

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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("high_security.txt","r",stdin);
    freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int t, x, y, ans1, ans2, i, j, k, n, ans, l;
    string a, b;

    //long long * mat = new long long[1000][1000];
    takei(t);
    for(int mm = 1; mm<=t; mm++)
    {
        takei(n);
        cin >> a >> b;
        for(i=0; i<n; i++)
        {
            if(i==0 and a[i]=='.' and a[i+1]=='X' and b[i]=='.')
            {
                j = i;
                a[i]='X';
                while(j>=0 and b[j]!='X')
                    b[j--] = '*';
                j = i;
                while(j<n and b[j]!='X')
                    b[j++] = '*';
            }
            else if(i==n-1 and a[i-1]=='X' and a[i]=='.' and b[i]=='.')
            {
                j = i;
                a[i]='X';
                while(j>=0 and b[j]!='X')
                    b[j--] = '*';
                j = i;
                while(j<n and b[j]!='X')
                    b[j++] = '*';
            }
            else if(a[i-1]=='X' and a[i]=='.' and a[i+1]=='X' and b[i]=='.')
            {
                j = i;
                a[i]='X';
                while(j>=0 and b[j]!='X')
                    b[j--] = '*';
                j = i;
                while(j<n and b[j]!='X')
                    b[j++] = '*';
            }

        }

        for(i=0; i<n; i++)
        {
            if(i==0 and b[i]=='.' and b[i+1]=='X' and a[i]=='.')
            {
                j = i;
                b[i]='X';
                while(j>=0 and a[j]!='X')
                    a[j--] = '*';
                j = i;
                while(j<n and a[j]!='X')
                    a[j++] = '*';
            }
            else if(i==n-1 and b[i-1]=='X' and b[i]=='.' and a[i]=='.')
            {
                j = i;
                b[i]='X';
                while(j>=0 and a[j]!='X')
                    a[j--] = '*';
                j = i;
                while(j<n and a[j]!='X')
                    a[j++] = '*';
            }
            else if(b[i-1]=='X' and b[i]=='.' and b[i+1]=='X' and a[i]=='.')
            {
                j = i;
                b[i]='X';
                while(j>=0 and a[j]!='X')
                    a[j--] = '*';
                j = i;
                while(j<n and a[j]!='X')
                    a[j++] = '*';
            }

        }
        x = 0;
        for(i=j=0; i<n; i++)
        {
            if(a[i]=='.' or a[i]=='*')
                j = 1;
            else
            {
                if(j==1)
                    x++;
                j = 0;
            }
        }
        if(j) x++;
        for(i=j=0; i<n; i++)
        {
            if(b[i]=='.' or b[i]=='*')
                j = 1;
            else
            {
                if(j==1)
                    x++;
                j = 0;
            }
        }
        if(j) x++;

        //cout << a << endl << b << endl;


        pf("Case #%d: ", mm);
        cout << x << endl;
    }
    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}



