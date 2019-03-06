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
template <class T> T MAX(T a, T b) { return a>b?a:b;}template <class T> T MIN(T a, T b) { return a<b?a:b;}
template <class T1> void deb(T1 p) { cout << "Debugging: " << p << endl;}
template <class T1, class T2> void deb(T1 p, T2 q) { cout << "Debugging: " << p << "\t" << q  << endl;}
template <class T1, class T2, class T3> void deb(T1 p, T2 q, T3 r) { cout << "Debugging: " << p << "\t " << q << "\t " << r << endl;}
template <class T1, class T2, class T3, class T4> void deb(T1 p, T2 q, T3 r, T4 s) { cout << "Debugging: " << p << "\t " << q << "\t " << r << "\t " << s << endl;}
long long int POOW(int b, int p) { if(p==0) return 1; return b*POOW(b, p-1);}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1}; const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define SIZE INT_MAX
int mat[505][505], n;

void FLOYD()
{
    int i, j, k;
    for(k=0; k<n; k++)
    {
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                mat[i][j] = min(mat[i][j], max(mat[i][k], mat[k][j]));
            }
        }
    }
    return;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int i, j, t, keis=0, a, b, m;
    takei(t);
    while(t--)
    {
        takei(n);
        takei(m);
        for(i=0; i<=n/2; i++)
        {
            for(j=0; j<n; j++)
            {
                mat[j][i] = mat[i][j] = 1<<28;
            }
        }
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                deb(i, j, mat[i][j]);
            }
        }

        //memset(mat, 1, sizeof(mat));
        //deb(mat[1][2]);
        for(i=0; i<n; i++) mat[i][i] = 0;
        while(m--)
        {
            takei(a);
            takei(b);
            takei(i);
           // if(mat[a][b])
               mat[b][a] = mat[a][b] = min(mat[a][b], i);
           // else
               // mat[b][a] = mat[a][b] = i;
        }
        takei(j);
        FLOYD();
        pf("Case %d:\n", ++keis);
        for(i=0; i<n; i++)
        {
            if(mat[j][i]>20001) pf("Impossible\n");
            else pf("%d\n",mat[j][i]);
        }
    }
    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}


